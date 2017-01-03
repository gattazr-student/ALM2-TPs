#include <stdio.h>
#include <ctype.h>
#include <string.h>

#include "samsung.h"
#include "evaluator.h"
#include "rs232.h"
#include "config_it.h"

char read_byte(int aLigne){
	vuint *wUstat, *wUrxbuf;
	/* Mise en place de pointeurs sur le registre à utilser pour la lecture et celui de stat */
	wUstat = aLigne ? USTAT1 : USTAT0; /* Etat registre URXBUF (entré) */
	wUrxbuf = aLigne ? URXBUF1 : URXBUF0; /* registre URXBUF */

	/* Attend que buffer signalé comme non vide */
	/* USTAT[5] : 	0 -> pas de donnée dans le registre de transmission (UTXBUF) */
	/* 				1 -> donnée valide dans le registre de transmission (UTXBUF) */
	while ((*wUstat & (1 << USTAT_RDR_POS))==0);

	return *wUrxbuf;
	/* USTAT[5] est passé à 1 par le processeur automatiquement */
}

void write_byte(int aLigne, char aChar){
	vuint *wUstat, *wUtxbuf;
	/* Mise en place de pointeurs sur le registre à utilser pour transmettre et celui de stat */
	wUstat = aLigne ? USTAT1 : USTAT0; /* Etat registre UTXBUF (sortie) */
	wUtxbuf = aLigne ? UTXBUF1 : UTXBUF0; /* registre UTXBUF */
	/* USTAT0 -> stat de UTXBUF0 et URXBUF0 */
	/* USTAT1 -> stat de UTXBUF1 et URXBUF1*/

	// if(aLigne){
	// 	wUstat = USTAT1;
	// }else{
	// 	wUstat = USTAT0;
	// }
	
	/* Attend que buffer signalé comme vide */
	/* USTAT[6] : 	0 -> donnée valide dans le registre de transmission (UTXBUF) */
	/* 				1 -> pas de donnée dans le registre de transmission (UTXBUF) */
	while ((*wUstat & (1 << USTAT_TX_BUFFER_EMPTY_POS))==0);

	/* Transmission */
	*wUtxbuf = aChar;
	/* USTAT[6] est passé à 1 par le processeur automatiquement */
}
