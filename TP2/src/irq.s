			.text

			.global _irq_handler
_irq_handler:		stmfd sp!,{r0-r12,lr}
			bl  traiter_interruption
			ldmfd sp!,{r0-r12,lr}
			subS pc, lr, #4

			.global _fiq_handler
_fiq_handler:		stmfd sp!,{r0-r12,lr}
			bl  bp
			ldmfd sp!,{r0-r12,lr}
			subS pc, lr, #4

                        .weak bp
                        @ default bp function if no other provided
bp:			mov pc,lr
