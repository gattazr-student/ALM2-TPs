

#define  IRQ_CPSR	(1 << 7)
#define  FIQ_CPSR	(1 << 6)

/* Liste de commandes applicables dans traiter_cpsr_IT */

#define ENABLE_IRQ      IRQ_CPSR
#define DISABLE_IRQ     (-IRQ_CPSR)

#define ENABLE_FIQ      FIQ_CPSR
#define DISABLE_FIQ     (-FIQ_CPSR)

/* Liste de commandes applicables dans traiter_source_IT */

#define MASQUER_IT      1
#define DEMASQUER_IT    2
#define MODE_FIQ        3
#define MODE_IRQ        4
#define ACQUITTER_IT    5


extern int masque, mode, pending;

/* Traiter_source gère une liste de sources terminée par 0             */
/* Exemple : traiter_sources_IT (DEMASQUER_IT,NUMUART1X, NUMxIRQ0, 0)  */ 
/* active 2 sources : bouton poussoir/IRQ0 et émission ligne série 1   */

extern void traiter_sources_IT (int commande,...);

void clear_pending (int liste);

extern void afficher_IT(void);

extern void traiter_cpsr_IT (int irq_command, int fiq_command);



