#include <stdio.h>
#include <ctype.h>
#include <string.h>

#include "samsung.h"
#include "evaluator.h"
#include "rs232.h"
#include "config_it.h"

#define NB_CHAR 16

void eteindre_diode (){
	*IOPDATA &= ~(LED1 | LED2 | LED3 | LED4);
}

void afficher_nb_lettres (int wNB_l){
	eteindre_diode();
	wNB_l %= NB_CHAR;
	if(wNB_l >= 8){
		*IOPDATA |= LED1;
		wNB_l -= 8;
	}
	
	if(wNB_l >= 4){
		*IOPDATA |= LED2;
		wNB_l -= 4;
	}
	
	if(wNB_l >= 2){
		*IOPDATA |= LED3;
		wNB_l -= 2;
	}

	if(wNB_l == 1){
		*IOPDATA |= LED4;
	}
}
