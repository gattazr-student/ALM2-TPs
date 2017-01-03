#include <stdio.h>
#include <ctype.h>
#include <string.h>

#include "samsung.h"
#include "evaluator.h"
#include "rs232.h"
#include "config_it.h"

#include "affichage_7Segs.h"
#include "affichage_LEDs.h"
#include "ligneSerie.h"

#define TAILLE_MESS 33

char MESSAGE[TAILLE_MESS];
int CHAR_AFFICHE = -1;
int CHAR_COURANT = 0;

/* Initialisation des variables du programmes et envoie d'un message par le port serie */
void initialisation (){
	int wI;
	char wDebut[] = "\nBonjour, connection etablie :-)\n";

	/* Intialise la chaine MESSAGE à vide */
	for(wI=0; wI < TAILLE_MESS; wI++){
		MESSAGE[wI] = '\0';
	}
	/* Envoi d'un message de bienvenu */
	wI = 0;
	do{
		write_byte(1, wDebut[wI]);
		wI++;
	}while(wDebut[wI]!='\0');
}

/* Gère l'interruption ligneSérie */
void it_ligneSerie(){
	int wI;
	char wChar;
	/* Acquittement de l'interruption */
	traiter_sources_IT(ACQUITTER_IT, INTUART1R, 0);
	
	/* efface le MESSAGE précédent si il était complet */
	/* Si le pointeur CHAR_COURANT est sur la première case du tableau, c'est qu'aucun message n'est en lecture*/
	if(CHAR_COURANT == 0) {
		for(wI = 0; wI < TAILLE_MESS; wI++ ){
			MESSAGE[wI] = '\0';
		}
		CHAR_AFFICHE = -1; /* On ne veut pas afficher de lettres pendant qu'on remplace le mesasge */
	}
	/* Lecture du caractère */
	wChar = read_byte(1);
	write_byte(1, wChar); /* ACK de la lecture (utile pour le debug) */

	/* Sortie d'interuption si on vient de lire un caractère fin de chaine */
	/* CHAR_COURANT et CHAR_AFFICHE pointent sur le premier caractère du message */
	if ( wChar == '.') {
		MESSAGE[CHAR_COURANT] = '\0';
		CHAR_COURANT = 0;
		CHAR_AFFICHE = 0;
		return;
	}

	/* Si le caractère n'est pas une lettre, on l'ignore*/
	if(wChar < 'a' || wChar > 'z'){
		return;
	}
	MESSAGE[CHAR_COURANT] = wChar;

	/* Si le MESSAGE est plein, bloquer cette interruption */
	if ( CHAR_COURANT == TAILLE_MESS - 1){
		traiter_sources_IT(MASQUER_IT, INTUART1R, 0);
	}
	CHAR_COURANT++;
}

/* gère l'interruption le bouton user int0 */
void it_bouton(){
	/* Acquittement de l'interruption */
	traiter_sources_IT(ACQUITTER_IT, INTxIRQ0, 0);

	/* affiche prochain caractère si celui affiché couramment est différent de '\0' */
	if(CHAR_AFFICHE >= 0 && MESSAGE[CHAR_AFFICHE + 1] != '\0' ){
		CHAR_AFFICHE ++;
	}else{
		CHAR_AFFICHE = -1;
	}
}

/* Connaître l'interruption qui a été levée*/
void traiter_interruption(){
	if(*INTPND & INTUART1R) {it_ligneSerie();}
	if(*INTPND & INTxIRQ0) {it_bouton();}
}


void do_loop(void){
	int wLength;
	eteindre_segments();
	eteindre_diode();
	while (1) {
		if(CHAR_AFFICHE != -1){
			wLength = strlen(MESSAGE);
			afficher_segments(MESSAGE[CHAR_AFFICHE]);
			afficher_nb_lettres(wLength - CHAR_AFFICHE - 1);
		}else{
			eteindre_diode();
			afficher_infini();
		}
	}
}

int main(void){
	int wDummy;
	int wLigne;

	wLigne = 1;

	_startup_init_rs();
	wDummy = _setup_speed_rs(wLigne,600);

	initialisation();

	/* Décide quels i/o sont activés */
	/* Tous les périphes sont activés sauf les intérupteurs DIP1 à DIP4 */
	*IOPMOD = ~ ( DIP1 | DIP2 | DIP3 | DIP4);
	*IOPDATA = 0;

	/* traite les sources d'interruptions en mode IRQ*/
	traiter_sources_IT(MODE_IRQ, INTUART1R, INTxIRQ0);
	/* traiter_sources_IT(MODE_FIQ, TIMER1, TIMER0); */
	traiter_sources_IT(DEMASQUER_IT, GBLINTMSK, INTUART1R, INTxIRQ0, 0);
	/* permet l'activation des IRQ mais pas des FIQ */
	traiter_cpsr_IT(ENABLE_IRQ, DISABLE_FIQ);

	do_loop();
	return 0;
}
