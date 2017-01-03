#include <stdio.h>
#include <ctype.h>
#include <string.h>

#include "samsung.h"
#include "evaluator.h"
#include "rs232.h"
#include "config_it.h"


void eteindre_segments(){
	*IOPDATA &= ~(SEGA | SEGB | SEGC | SEGD | SEGE | SEGF | SEGG);
}

/* Affiche les cractères compris entre 'a' et 'z' */
void afficher_segments(char aChar){
	eteindre_segments();
	unsigned int wCode;
	switch( aChar ) {
		case 'a':
			wCode = SEGA | SEGB | SEGC | SEGE | SEGF | SEGG;
		break;
		case 'b':
			wCode = SEGA | SEGB | SEGC | SEGD | SEGE | SEGF | SEGG;
		break;
		case 'c':
			wCode = SEGA | SEGD | SEGE | SEGF;
		break;
		case 'd':
			wCode = SEGA | SEGB | SEGC | SEGD | SEGE | SEGF;
		break;
		case 'e':	
			wCode = SEGA | SEGD | SEGE | SEGF | SEGG;
		break;
		case 'f':
			wCode = SEGA | SEGE | SEGF | SEGG;
		break;
		case 'g':
			wCode = SEGA | SEGC | SEGD | SEGE | SEGF;
		break;
		case 'h':
			wCode = SEGB | SEGC | SEGE | SEGF | SEGG;
		break;
		case 'i':
			wCode = SEGB | SEGC;
		break;
		case 'j':
			wCode = SEGA | SEGB | SEGC | SEGD | SEGE;
		break;
		case 'k':
			wCode = SEGE | SEGF | SEGG;
		break;
		case 'l':
			wCode = SEGD | SEGE | SEGF;
		break;
		case 'm':
			wCode = SEGA | SEGB | SEGC | SEGE | SEGF;
		break;
		case 'n':
			wCode = SEGB | SEGC | SEGE | SEGF;
		break;
		case 'o':
			wCode = SEGA | SEGB | SEGC | SEGD | SEGE | SEGF;
		break;
		case 'p':
			wCode = SEGA | SEGB | SEGE | SEGF | SEGG;
		break;
		case 'q':
			wCode = SEGA | SEGB | SEGD | SEGE | SEGF;
		break;
		case 'r':
			wCode = SEGA | SEGB | SEGC | SEGE | SEGF | SEGG;
		break;
		case 's':
			wCode = SEGA | SEGC | SEGD | SEGF | SEGG;
		break;
		case 't':
			wCode = SEGA | SEGE | SEGF;
		break;
		case 'u':
			wCode = SEGB | SEGC | SEGD | SEGE | SEGF;
		break;
		case 'v':
			wCode = SEGB | SEGC | SEGD | SEGE | SEGF;
		break;
		case 'w':
			wCode = SEGB | SEGC | SEGD | SEGE | SEGF | SEGG;
		break;
		case 'x':
			wCode = SEGA | SEGD | SEGG;
		break;
		case 'y':
			wCode = SEGB | SEGC | SEGF | SEGG;
		break;
		case 'z':
			wCode = SEGA | SEGB | SEGD | SEGE | SEGG;
		break;

		default :
			wCode = 0;
	}
	*IOPDATA |= wCode;
}

void afficher_infini (void){
	int wCompteur; /* "horloge" */
	int wNB_seg = 8; /* nombre d'étapes dans notre dessin */
	int wNB_s = 10000; /* temps d'affichage d'un segment */
	int wSeg; /* numero de l'étape */
	unsigned int wCode; /* registre temporaire */
	
	wCompteur = 0;
	while(wCompteur < (wNB_s * wNB_seg) ){
		wSeg = wCompteur / wNB_s; /* On récupère l'étpae à laquele on se trouve */
		switch(wSeg){ /* en fonction de l'étape dans laquelle on est on affiche tel segment */
			case 0:
				wCode = SEGA;
			break;
			case 1:
				wCode = SEGB;
			break;
			case 2:
				wCode = SEGG;
			break;
			case 3:
				wCode = SEGE;
			break;
			case 4:
				wCode = SEGD;
			break;
			case 5:
				wCode = SEGC;
			break;
			case 6:
				wCode = SEGG;
			break;
			case 7:
				wCode = SEGF;
			break;
			default :
				wCode = SEGA | SEGB | SEGC | SEGD | SEGE | SEGF | SEGG;
		}
		if ( *IOPDATA != wCode){ /* on regarde si on a changé de segment */
			eteindre_segments();
			*IOPDATA |= wCode;
		}
		wCompteur ++;
	}
}