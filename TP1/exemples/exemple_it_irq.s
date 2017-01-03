**************** exemple_it *************************

;adr code
            ***************************  vecteurs
00  a07c    *  b    0x7c (-> 0x7E)    *  reset
02  a03c    *  b    0x3c (-> 0x40)    *  irq
            ***************************

;           zone des variables du traitant
            ***************************
0E  0a      *  0a                     *  unsigned char z = 10;
            ***************************

;           traitant irq
            ***************************
40  1011    *  sub  sp, #1            *  /* sauve des regs modifiés */
42  7801    *  str  r8, [sp,#0]       *
44  1011    *  sub  sp, #1            *
46  7901    *  str  r9, [sp,#0]       *
48  1de8    *  mov  r8, #E            *
4a  5908    *  ldr  r9, [r8, #0]      *
4c  3c19    *  addS r9, #5            *  z = z+5 /*modifie indicateurs */
4e  7908    *  str  r9, [r8,#0]       *
50  5901    *  ldr  r9, [sp,#0]       *  /* restaure regs */
52  1c11    *  add  sp,#1             *
54  5801    *  ldr  r8, [sp,#0]       *
56  1c11    *  add  sp,#1             *
58  F000    *  rti                    *
            ***************************

;           programme interrompu
            ***************************
7E  1d01    *  mov  sp, #0            *
80  1d18    *  mov  r8, #1            *        x = 1
82  3018    *  subS r8, #1            *  b1:   x = x - 1
84  a4fc    *  bcs  0xfc              *        if (x >= 0) goto b1
86  e000    *  cleari                 *  /* autoriser IT */
88  1d59    *  mov  r9, #5            *        y = 5
8a  3019    *  subS r9, #1            *  b2:   y = y - 1
8c  a4fc    *  bcs  0xfc              *        if (y >= 0) goto b2
8e  e800    *  seti                   *
90  3018    *  subS r8, #1            *  b3:   x = x - 1
92  a0fc    *  b    0xfc              *        goto b3
            ***************************
