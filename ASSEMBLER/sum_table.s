/*Section de déclaration zone de données */
.section .data
SUM: .byte 0 // déclaration de la variable avec une initialisation à 0
RES: .byte 0
tab1: .byte 1, 12, 28, 4, 3 // initialiser le tableau en mémoire
tab2: .byte 1, 2, 3, 4, 5
VALEUR_SUP30: .byte 0

/* Section code principal */
.text
.global main
.type main, %function


/*main:
	// adressage indirect
	LDR R0, =tab1 // charge l'adresse du tableau
	LDRB R1, =RES // charge l'adresse de la variable SUM
	MOV R2, #5 // compteur initialisé au nombre d'élement du tableau
	MOV R4, #0 //indice utiliser pour les cases du tableau
	MOV R5, #0 //registre intermediaire pour la somme

	Loop_Sum:
		LDRB R3, [R0, R4] // chage la valeur du tableau dans R3

		ADD R5, R5, R3 // ajoute la valeur à la somme globale
		ADD R4, R4, #1 // indice de tableau
		SUB R2, R2, #1 // décrémentation du compteur
		BNE Loop_Sum // boucler dans que le compteur est non nul

	STRB R5, [R1]

	// branchement conditionnel
	LDRB R1, =VALEUR_SUP30
	CMP R5, #30
	BGE great30
	MOV R2, #0
	B save

	great30: MOV R2, #1

	save: LDRB R2, [R1]


stop:   B stop
		BX LR

.end
*/


