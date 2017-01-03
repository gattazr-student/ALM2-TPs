#include <stdarg.h>
#include <stdio.h>

#include "evaluator.h"
#include "samsung.h"
#include "config_it.h"


/***********************************************************************
 * config_it.c
 * 
 * Auteur : Philippe Waille 
 *
 **********************************************************************/

/***********************************************************************
 * définir les bits de masquage de IRQ et FIQ dans cpsr
 ***********************************************************************/

void traiter_cpsr_IT(int aIrq_command, int aFiq_command){
  unsigned int wInterdire = 0;
  unsigned int wAutoriser = 0;
  if (aIrq_command < 0) 
     wInterdire |= -aIrq_command;
  else
     wAutoriser |= aIrq_command;
  if (aFiq_command < 0) 
     wInterdire |= -aFiq_command;
  else
     wAutoriser |= aFiq_command;
  asm (	"mrs  r1, cpsr\n\t" 
  "orr  r1, r1, %0;\n\t"          /* |= wInterdire  */
  "bic  r1, r1, %1\n\t"           /* &= ~wAutoriser */
  "msr  cpsr_c, r1"
    : /* no output register */
    : "r" (wInterdire), "r" (wAutoriser)
    :"%r1");
}

int MASQUE, MODE, PENDING;

/***********************************************************************
 * masquer
 ***********************************************************************/

void masquer(int aListe){
  *INTMSK |= aListe;
}

/***********************************************************************
 * demasquer
 ***********************************************************************/

void demasquer(int aListe){
  *INTMSK &= ~aListe;
}


/***********************************************************************
 * set_intmod
 * 
 * basculer sur FIQ 
 ***********************************************************************/

void set_intmod(int aListe){
  *INTMOD |= aListe;
}

/***********************************************************************
 * reset_intmod
 * 
 * basculer sur IRQ 
 ***********************************************************************/

void reset_intmod(int aListe) {
  *INTMOD &=  ~aListe;
}

/***********************************************************************
 * clear_pending
 *
 * acquitter
 ***********************************************************************/

void clear_pending (int aListe) {
  *INTPND = aListe;
}

/**********************************************************************
 * appliquer une commande à une liste de sources d'IT
 *
 **********************************************************************/

void traiter_sources_IT (int aCommande, ...) {
  int wListe = 0;
  int wArg_lu;
  va_list wPt_arg; /* pointeur les éléments de la liste */
  
  va_start(wPt_arg, aCommande);  /* pointer sur le 1 arg après commande */
  do {
    wArg_lu =  va_arg(wPt_arg, int); /* lire argument et passer au suivant */
    wListe |= wArg_lu;
  } while (wArg_lu !=0);
  va_end(wPt_arg);
  
  switch(aCommande) {
    case MASQUER_IT   : masquer(wListe);       break;
    case DEMASQUER_IT : demasquer(wListe);     break;
    case MODE_FIQ     : set_intmod(wListe);    break;
    case MODE_IRQ     : reset_intmod(wListe);  break;
    case ACQUITTER_IT : clear_pending(wListe); break;
  }
}

/**********************************************************************
 * Afficher l'état des principales sources d'IT utilisables
 *
 *********************************************************************/

void  afficher_IT () {
  MODE = *INTMOD;
  PENDING = *INTPND;
  printf (" Masque : %8x      mode  : %8x     pending : %8x\n\n",
            MASQUE, MODE, PENDING);
  printf ("Source          Masque             Mode                Pending\n");
  printf ("INTxIRQ0      	%d               	%d                 	%d\n",
           (MASQUE & INTxIRQ0) != 0, 
           (MODE & INTxIRQ0) != 0, 
           (PENDING & INTxIRQ0) != 0);
  printf ("INTUART1X      	%d                 	%d                 	%d\n",
           (MASQUE & INTUART1X) != 0, 
           (MODE & INTUART1X) != 0, 
           (PENDING & INTUART1X) != 0);
  printf ("INTUART1R      	%d                 	%d                 	%d\n",
           (MASQUE & INTUART1R) != 0, 
           (MODE & INTUART1R) != 0, 
           (PENDING & INTUART1R) != 0);
  printf ("INTTIMER0      	%d                 	%d                 	%d\n",
           (MASQUE & INTTIMER0) != 0, 
           (MODE & INTTIMER0) != 0, 
           (PENDING & INTTIMER0) != 0);
  printf ("INTTIMER1      	%d                 	%d                 	%d\n",
           (MASQUE & INTTIMER1) != 0, 
           (MODE & INTTIMER1) != 0, 
           (PENDING & INTTIMER1) != 0);
  printf ("GBLINTMSK      	%d                 	-                 	-\n",
           (MASQUE & GBLINTMSK) != 0);
  printf ("\n\n");
}
