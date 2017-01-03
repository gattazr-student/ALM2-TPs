/***********************************************************************
 * evaluator.h
 *
 * Auteur : Pierre Habraken
 *
 * Definitions relatives a la carte Arm Evaluator7T
 *
 * Ajout des constantes de configuration initiale de IOPCON
 * et du tableau de conversion entier -> 7 segments
 * par Philippe Waille
 **********************************************************************/

#include "samsung.h"

#define NUMDIP4   3
#define NUMDIP3   2
#define NUMDIP2   1
#define NUMDIP1   0
#define DIP4      (1 << NUMDIP4)
#define DIP3      (1 << NUMDIP3)
#define DIP2      (1 << NUMDIP2)
#define DIP1      (1 << NUMDIP1)

#define NUMLED4   4
#define NUMLED3   5
#define NUMLED2   6
#define NUMLED1   7
#define LED4      (1 << NUMLED4)
#define LED3      (1 << NUMLED3)
#define LED2      (1 << NUMLED2)
#define LED1      (1 << NUMLED1)

#define NUMUSW3   8
#define USRSW3    (1 << NUMUSW3)

#define NUMSEGA   10
#define NUMSEGB   11
#define NUMSEGC   12
#define NUMSEGD   13
#define NUMSEGE   14
#define NUMSEGG   15
#define NUMSEGF   16
#define SEGA      (1 << NUMSEGA)
#define SEGB      (1 << NUMSEGB)
#define SEGC      (1 << NUMSEGC)
#define SEGD      (1 << NUMSEGD)
#define SEGE      (1 << NUMSEGE)
#define SEGF      (1 << NUMSEGF)
#define SEGG      (1 << NUMSEGG)

/***********************************************************************
 * configuration standard pour IRQ si broche activee           
 ***********************************************************************/

#define IRQ_STANDARD  (IRQ_FILTER | IRQ_FEDGE)

extern const unsigned int _hex_to_7seg [];
