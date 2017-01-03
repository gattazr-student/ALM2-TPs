/***********************************************************************
 * samsung.h
 *
 * Regenerer crt0e7t.o (make) apres toute modification
 *
 * Auteur : Pierre Habraken
 * Modifie le 6/07/2009 par Ph Waille : 
 *     ajout du port serie     
 *     introduction de samsung.c et de extern volatile xxx * const
 **********************************************************************/

#ifndef SAMSUNG_H
#define SAMSUNG_H

typedef volatile unsigned int vuint;
typedef vuint * const cvuintp;

/**********************************************************************
 * Use the following syntax for constant pointer definitions :
 * extern cvuintp NAME;    // = (cvuintp) 0xVALUE;  // comment  
 **********************************************************************/


/* Timers */

extern cvuintp TMOD;	// = (cvuintp) 0x3ff6000; // Timer mode register

#define TE0       (1 << 0)    // Timer 0 enable
#define TMD0      (1 << 1)    // Timer 0 mode selection
#define TCLR0     (1 << 2)    // Timer 0 initial TOUT0 value
#define TE1       (1 << 3)    // Timer 1 enable
#define TMD1      (1 << 4)    // Timer 1 mode selection
#define TCLR1     (1 << 5)    // Timer 1 initial TOUT0 value

extern cvuintp TDATA0;	// = (cvuintp)  0x3ff6004; // Timer 0 data register
extern cvuintp TDATA1;	// = (cvuintp)  0x3ff6008; // Timer 1 data register
extern cvuintp TCNT0;	// = (cvuintp)  0x3ff600c; // Timer 0 count register
extern cvuintp TCNT1;	// = (cvuintp)  0x3ff6010; // Timer 1 count register

/* RS232 lines */

extern cvuintp ULCON0;	// = (cvuintp)  0x3ffd000; // UART 0 line control register
extern cvuintp ULCON1;	// = (cvuintp)  0x3ffe000; // UART 1 line control register

extern cvuintp UCON0;	// = (cvuintp)  0x3ffd004; // UART 0 control register
extern cvuintp UCON1;	// = (cvuintp)  0x3ffe004; // UART 1 control register

extern cvuintp USTAT0;	// = (cvuintp)  0x3ffd008; // UART 0 status register
extern cvuintp USTAT1;	// = (cvuintp)  0x3ffe008; // UART 1 status register

extern cvuintp UTXBUF0;	// = (cvuintp)  0x3ffd00c; // UART 0 transmit buffer register
extern cvuintp UTXBUF1;	// = (cvuintp)  0x3ffe00c; // UART 1 transmit buffer register

extern cvuintp URXBUF0;	// = (cvuintp)  0x3ffd010; // UART 0 receive buffer register
extern cvuintp URXBUF1;	// = (cvuintp)  0x3ffe010; // UART 1 receive buffer register

extern cvuintp UBRDIV0;	// = (cvuintp)  0x3ffd014; // UART 0 baud rate divisor register
extern cvuintp UBRDIV1;	// = (cvuintp)  0x3ffe014; // UART 1 baud rate divisor register

extern cvuintp BRDCNT0;	// = (cvuintp)  0x3ffd018; // UART 0 baud rate count register
extern cvuintp BRDCNT1;	// = (cvuintp)  0x3ffe018; // UART 1 baud rate count register

extern cvuintp UBRCLK0;	// = (cvuintp)  0x3ffd01c; // UART 0 baud rate clock monitor
extern cvuintp UBRCLK1;	// = (cvuintp)  0x3ffe01c; // UART 1 baud rate clock monitor

#define ULCON_WL_POS_HIGH	1
#define ULCON_WL_POS_LOW 	0
#define ULCON_WL_5	0		// word length in bits
#define ULCON_WL_6	1
#define ULCON_WL_7	2
#define ULCON_WL_8	3

#define ULCON_NB_STOP_BITS_POS   2
#define ULCON_NB_STOP_1          0       // nb stop bits
#define ULCON_NB_STOP_2          1

#define ULCON_PMD_POS_HIGH	5
#define ULCON_PMD_POS_LOW 	3
#define ULCON_PMD_NO		0      // parity mode
#define ULCON_PMD_ODD		4
#define ULCON_PMD_EVEN		5
#define ULCON_PMD_FORCED_CHECKED_1		5
#define ULCON_PMD_FORCED_CHECKED_0		7

#define ULCON_SERIAL_CLOCK_SELECTION_POS 6
#define ULCON_SERIAL_CLOCK_INTERNAL_MCLK	0  // clock source
#define ULCON_SERIAL_CLOCK_EXTERNAL_UCLK	1

#define ULCON_INFRA_RED_MODE_POS 7
#define ULCON_INFRA_RED_NORMAL   0      // infra red mode
#define ULCON_INFRA_RED_IR	1

#define UCON_RECEIVE_MODE_POS_HIGH	1
#define UCON_RECEIVE_MODE_POS_LOW	0
#define UCON_RECEIVE_MODE_DISABLE	0   // Rx : it/polled or dma
#define UCON_RECEIVE_MODE_IRQ		1
#define UCON_RECEIVE_MODE_GDMA0		2
#define UCON_RECEIVE_MODE_GDMA1		3

#define UCON_RX_STATUS_IT_ENABLE_POS	2
#define UCON_RX_STATUS_IT_DISABLE	0
#define UCON_RX_STATUS_IT_ENABLE	1

#define UCON_TRANSMIT_MODE_POS_HIGH	4
#define UCON_TRANSMIT_MODE_POS_LOW	3
#define UCON_TRANSMIT_MODE_DISABLE	0   // Tx : it/polled or dma
#define UCON_TRANSMIT_MODE_IRQ		1
#define UCON_TRANSMIT_MODE_GDMA0	2	
#define UCON_TRANSMIT_MODE_GDMA1	3

#define UCON_DATA_SET_READY_POS		5 
#define UCON_DATA_SET_READY_OFF		0   // DSR signal
#define UCON_DATA_SET_READY_ON		1

#define UCON_DATA_SEND_BREAK_POS	6 
#define UCON_DATA_SEND_BREAK_OFF	0   // Break (to time frame)
#define UCON_DATA_SEND_BREAK_ON		1

#define UCON_LOOP_BACK_MODE_POS		7
#define UCON_LOOP_BACK_MODE_OFF		0   // loopback tx to rx for test
#define UCON_LOOP_BACK_MODE_ON		1

#define USTAT_OVERUN_ERROR_POS		0
#define USTAT_PARITY_ERROR_POS		1
#define USTAT_FRAME_ERROR_POS		2
#define USTAT_BREAK_INTERRUPT_POS	3
#define USTAT_DTR_POS			4   // data terminal ready
#define USTAT_RDR_POS			5   // receive data ready
#define USTAT_TX_BUFFER_EMPTY_POS	6
#define USTAT_TRANSMIT_COMPLETE_POS	7

#define UBRDIV_CNT1_POS_HIGH		3
#define UBRDIV_CNT1_POS_LOW 		0
#define UBRDIV_CNT0_POS_HIGH		15	
#define UBRDIV_CNT0_POS_LOW 		4

#define UBRDIV_CNT1_NODIV               0   // Baud = (cvuintp) ck/(cnt0+1)/(16^CNT1)/16
#define UBRDIV_CNT1_DIV16               1

// 25 Mhz clock, CNT1=1
#define UBRDIV_CNT0_50                 1953 
#define UBRDIV_CNT0_75                 1302  
#define UBRDIV_CNT0_110                 888  
#define UBRDIV_CNT0_134                 729
#define UBRDIV_CNT0_150                 651  
#define UBRDIV_CNT0_200                 488  
#define UBRDIV_CNT0_300                 326  

// 25 Mhz clock, CNT1=0
#define UBRDIV_CNT0_600                 2602 
#define UBRDIV_CNT0_1200                1301 
#define UBRDIV_CNT0_2400                650
#define UBRDIV_CNT0_4800                324
#define UBRDIV_CNT0_9600                162
#define UBRDIV_CNT0_19200               80
#define UBRDIV_CNT0_38400               40
#define UBRDIV_CNT0_57600               26
#define UBRDIV_CNT0_115200              13
#define UBRDIV_CNT0_230400              6
#define UBRDIV_CNT0_460860              2

/* Ports d'entree-sortie */

extern cvuintp IOPMOD;	// = (cvuintp)  0x3ff5000; // I/O port mode register

extern cvuintp IOPDATA;	// = (cvuintp)  0x3ff5008; // I/O port data register

extern cvuintp IOPCON;	// = (cvuintp)  0x3ff5004; // I/O port control register

#define CONxIRQ0  0           // External interrupt request 0 (port 8)
#define CONxIRQ1  5           // External interrupt request 1 (port 9)
#define CONxIRQ2  10          // External interrupt request 2 (port 10)
#define CONxIRQ3  15          // External interrupt request 3 (port 11)
#define CONDRQ0   20          // External DMA request 0 (port 12)
#define CONDRQ1   23          // External DMA request 1 (port 13)
#define CONDAK0   26          // External DMA acknowledge 0 (port 14)
#define CONDAK1   28          // External DMA acknowledge 1 (port 15)
#define CONTOEN0  30          // Timeout 0 (port 16)
#define CONTOEN1  31          // Timeout 1 (port 17)

#define IRQ_ACTIVE  (1<<4)      /* activer fonction IRQ de la broche */
#define IRQ_HIGH    (1<<3)      /* si niveau : IRQ si signal == (cvuintp) 1    */
#define IRQ_FILTER  (1<<2)      /* activation antirebond             */
#define IRQ_LEVEL   0           /* IRQ sur signal == (cvuintp) niveau          */
#define IRQ_REDGE   1           /* IRQ front montant                 */
#define IRQ_FEDGE   2           /* IRQ front descendant              */
#define IRQ_BEDGE   3           /* IRQ fronts montant et descendant  */

#define DRQ_ACTIVE  (1 << 2)     /* activer fonction DRQ de la broche  */
#define DRQ_FILTER  (1 << 1)     /* activation antirebond             */
#define DRQ_HIGH    (1 << 0)     /* DRQ si signal == (cvuintp) 1                */

#define DAK_ACTIVE  (1 << 2)     /* activer contion DAK de la broche  */
#define DAK_FILTER  (1 << 1)     /* activation antirebond             */
#define DAK_HIGH    (1 << 0)     /* DAK si signal == (cvuintp) 1                */

#define TOEN_ACTIVE (1 << 0)     /* activation sortie temporisateur   */

#define IRQ0_ACTIVE (IRQ_ACTIVE << CONxIRQ0)
#define IRQ1_ACTIVE (IRQ_ACTIVE << CONxIRQ1)
#define IRQ2_ACTIVE (IRQ_ACTIVE << CONxIRQ2)
#define IRQ3_ACTIVE (IRQ_ACTIVE << CONxIRQ3)

#define DRQ0_ACTIVE (DRQ_ACTIVE << CONDRQ0)
#define DRQ1_ACTIVE (DRQ_ACTIVE << CONDRQ1)
#define DAK0_ACTIVE (DAK_ACTIVE << CONDAK0)
#define DAK1_ACTIVE (DAK_ACTIVE << CONDAK1)

#define TOEN0_ACTIVE (TOEN_ACTIVE << CONTOEN0)
#define TOEN1_ACTIVE (TOEN_ACTIVE << CONTOEN1)

/* Controleur d'interruptions */

extern cvuintp INTMOD;	// = (cvuintp)  0x3ff4000; // Interrupt mode register
#define NUMxIRQ0  0           // External interrupt 0
#define NUMxIRQ1  1           // External interrupt 1
#define NUMxIRQ2  2           // External interrupt 2
#define NUMxIRQ3  3           // External interrupt 3
#define NUMUART0X 4           // UART0 transmit interrupt
#define NUMUART0R 5           // UART0 receive and error interrupt
#define NUMUART1X 6           // UART1 transmit interrupt
#define NUMUART1R 7           // UART1 receive and error interrupt
#define NUMGDMA0  8           // GDMA channel 0 interrupt
#define NUMGDMA1  9           // GDMA channel 1 interrupt
#define NUMTIMER0 10          // Timer 0 interrupt
#define NUMTIMER1 11          // Timer 1 interrupt
#define NUMHDLCAX 12          // HDLC channel A Tx interrupt
#define NUMHDLCAR 13          // HDLC channel A Rx interrupt
#define NUMHDLCBX 14          // HDLC channel B Tx interrupt
#define NUMHDLCBR 15          // HDLC channel B Rx interrupt
#define NUMETHBDX 16          // Ethernet controller BDMA Tx interrupt
#define NUMETHBDR 17          // Ethernet controller BDMA Rx interrupt
#define NUMETHMCX 18          // Ethernet controller MAC Tx interrupt
#define NUMETHMCR 19          // Ethernet controller MAC Rx interrupt
#define NUMI2C    20          // I2C interrupt
#define NUMGLOBAL 21          // Global (INTMSK only)
#define INTxIRQ0  (1 << NUMxIRQ0)
#define INTxIRQ1  (1 << NUMxIRQ1)
#define INTxIRQ2  (1 << NUMxIRQ2)
#define INTxIRQ3  (1 << NUMxIRQ3)
#define INTUART0X (1 << NUMUART0X)
#define INTUART0R (1 << NUMUART0R)
#define INTUART1X (1 << NUMUART1X)
#define INTUART1R (1 << NUMUART1R)
#define INTGDMA0  (1 << NUMGDMA0)
#define INTGDMA1  (1 << NUMGDMA1)
#define INTTIMER0 (1 << NUMTIMER0)
#define INTTIMER1 (1 << NUMTIMER1)
#define INTHDLCAX (1 << NUMHDLCAX)
#define INTHDLCAR (1 << NUMHDLCAR)
#define INTHDLCBX (1 << NUMHDLCBX)
#define INTHDLCBR (1 << NUMHDLCBR)
#define INTETHBDX (1 << NUMETHBDX)
#define INTETHBDR (1 << NUMETHBDR)
#define INTETHMCX (1 << NUMETHMCX)
#define INTETHMCR (1 << NUMETHMCR)
#define INTI2C    (1 << NUMI2C)
#define INTGLOBAL (1 << NUMLGLOBAL)

extern cvuintp INTPND;	// = (cvuintp)  0x3ff4004; // Interrupt pending register

extern cvuintp INTMSK;	// = (cvuintp)  0x3ff4008; // Interrupt mask register
#define GBLINTMSK (1 << 21)   // Global interrupt mask bit

extern cvuintp INTPRI0;	// = (cvuintp)  0x3ff400C; // Int. priority register 0
#define NUMPRI0   0
#define NUMPRI1   8
#define NUMPRI2   16
#define NUMPRI3   24

extern cvuintp INTPRI1;	// = (cvuintp)  0x3ff4010; // Int. priority register 1
#define NUMPRI4   0
#define NUMPRI5   8
#define NUMPRI6   16
#define NUMPRI7   24

extern cvuintp INTPRI2;	// = (cvuintp)  0x3ff4014; // Int. priority register 2
#define NUMPRI8   0
#define NUMPRI9   8
#define NUMPRI10  16
#define NUMPRI11  24

extern cvuintp INTPRI3;	// = (cvuintp)  0x3ff4018; // Int. priority register 3
#define NUMPRI12  0
#define NUMPRI13  8
#define NUMPRI14  16
#define NUMPRI15  24

extern cvuintp INTPRI4;	// = (cvuintp)  0x3ff401C; // Int. priority register 4
#define NUMPRI16  0
#define NUMPRI17  8
#define NUMPRI18  16
#define NUMPRI19  24

extern cvuintp INTPRI5;	// = (cvuintp)  0x3ff4020; // Int. priority register 5
#define NUMPRI20  0

extern cvuintp INTOFFSET;	// = (cvuintp)  0x3ff4024; // Interrupt offset register
extern cvuintp INTOSET_FIQ;	// = (cvuintp)  0x3ff4030; // FIQ Int. offset register
extern cvuintp INTOSET_IRQ;	// = (cvuintp)  0x3ff4034; // IRQ Int. offset register

#endif
