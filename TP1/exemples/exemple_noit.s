******************  exemple_noit *******************

;adr code
;           démarrage
            ***************************
00  a086    *  b    0x86 (-> 0x88)    *   
            ***************************
                             
;           programme de test : deux routines (xmy et ymx) et un programme
;           principal qui démarre à l adresse 0x88
            *************************** 
80  0098    *  sub  r8, r9            *  void  xmy () { x = x-y;}
82  0d30    *  mov  pc, lr            *
84  0089    *  sub  r9, r8            *  void  ymx () { y = y-x;}
86  0d30    *  mov  pc, lr            *
88  1df8    *  mov  r8, #0xF          *               x = 15;
8a  1da9    *  mov  r9, #0xa          *               y = 10;
8c  a00c    *  b    0xc  (+6i)        *               goto test
8e  0d8a    *  mov  r10,r8            *       corps:  if (x >= y) goto alors
90  209a    *  subS r10,r9            *
92  a404    *  bcs  0x4  (+2i)        *
94  80ee    *  bl   0xee (-9i)        *       sinon:  ymx ();
96  a002    *  b    0x2  (+1i)        *               goto fin_si;
98  80e6    *  bl   0xe6 (-13i)       *       alors:  xmy ();
9a  0d8a    *  mov  r10,r8            * fin_si/test:  if (x == y) goto suite;
9c  209a    *  subS r10,r9            *
9e  a802    *  beq  0x2  (+1i)        *
a0  a0ec    *  b    0xec (-10i)       *               goto corps;
a2  0000    *  ldr  r10, [r0,#e]      *       suite:  res = x;   TODO: faire l'encodage de l'instruction
a4  0000    *  str  r8,  [r10,#0]     *                          TODO: faire l'encodage de l'instruction
a6  a0fe    *  b    0xfe (-1i)        *      boucle:  goto boucle;
            ***************************

            .ltorg
            ***************************
b2  C0      * C0                      *               .word   res
            ***************************
