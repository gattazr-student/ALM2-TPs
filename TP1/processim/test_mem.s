****************** test_mem *******************

;adr code
;           démarrage
            *************************
00  a07E    *   b 0x7E (-> 0x80)    *
            *************************

;           principal qui démarre à l adresse 0x80
            *************************
            *                       * /* Test1: sans depl */
80  1d01    *   mov sp, #0          * /* Initialisation de la pile à FF (pour ne pas l'utiliser) */
82  1011    *   sub sp, #1          *
84  1d48    *   mov r8, #4          * /* Mise en place d'une valeur dans r8 */
86  1dd9    *   mov r9, #d          * /* Mise en place d'une valeur différente dans r9 */
88  1011    *   sub sp, #1          *
8a  7801    *   str r8, [sp,#0]     * /* R8 est enregistré sur la pile à l'adresse 0xFF*/
8c  5901    *   ldr r9, [sp,#0]     * /* Recharge la valeur de la pile dans r9. */
8e  1c11    *   add sp, #1          * /* On doit avoir r9 = r8 */
            *                       *
            *                       *
            *                       * /* Test2: avec depl une valeur non nulle directe */
90  1dd8    *   mov r8, #d          * /* Mise en place d'une nouvelle valeur dans r8 */
92  78d1    *   str r8, [sp,#d]     * /* R8 est enregistré sur la pile à l'adresse 0x0c */
94  59d1    *   ldr r9, [sp,#d]     * /* On doit avoir r8 = r9 */
            *                       *
            *                       *
            *                       * /* Test3: avec depl une valeur négative non directe */
96  1dc8    *   mov r8, #c          * /* Mise en place d'une nouvelle valeur dans r8 */
98  1d0a    *   mov r10, #0         *
9a  102a    *   sub r10, #2         * /* r10 = 0 - 2 = FE */
9c  68a1    *   str r8, [sp,r10]    * /* r8 est enregistré sur la pile à l'adresse 0xfd */
9e  49a1    *   ldr r9, [sp,r10]    * /* On doit avoir r8 = r9 */
            *****************************
