****************** test_it *******************
* Excution d'un programme pendant lequel on va effectuer une intéruptions logicielle et une
* interruption matérielle pendant l'execution du programme principal.
;adr code
;           démarrage
            *************************
00  a07e    *   b 0x7e (-> 0x80)    *
02  a01c    *   b 0x3c (-> 0x40)    * /* Il s'agit d'un déplacement */
04  a03A    *   b 0x3A (-> 0x40)    *
            *************************


;           Traitant intéruptions matérielle et logicielles (facilite les tests)
            *************************
40  1041    *  sub sp, #4           * /* Sauvegarde des registres r8-r11 */
42  7831    *  str r8, [sp,#3]      *
44  7921    *  str r9, [sp,#2]      *
46  7a11    *  str r10, [sp,#1]     *
48  7b01    *  str r11, [sp,#0]     *
            *                       *
4a  1df8    *  mov r8, #f           * /* Traitant it (ici une instruction simple pour prouver le principe) */
4c  F800    *  swi                  * /* L'instruction est ignoré puisque au milieu d'un traitant */
            *                       * /* On peut également tester de lancer une it matérielle qui sera ignoré aussi */
4e  5b01    *  ldr r11, [sp,#0]     * /* Recharge des registres r8-r11 */
50  5a11    *  ldr r10, [sp,#1]     *
52  5921    *  ldr r9, [sp,#2]      *
54  5831    *  ldr r8, [sp,#3]      *
56  1c41    *  add sp, #4           *
58  F000    *  rti                  * /* Retour execution normale */
            *************************

;           principal qui démarre à l adresse 0x80
            *************************
80  e800    *   clri                * /* Autorise les interruptions(comme en fin de traitant reset) */
82  1d01    *   mov sp, #0          * /* Initialise la pile à FF */
84  1d18    *   mov r8, #1          * /* r8 = 1 */
86  1dd9    *   mov r9, #d          * /* r9 = d */
88  F800    *   swi                 * /* Interruption logicielle */
8a  1c89    *   add r9, r8          * /* r9 = d + 1 = E */
8c  1c29    *   add r9, #2          * /* r9 = E + 2 = F */
            *****************************