.data /*mot clé de déclaration d'une zone de données */
SIZE:		.byte 7 /*Taille chaine -1 */
Hello: 		.asciz "Bonjour"
Hello2: 	.asciz "Bonj0ur"
SAME:   	.byte 1

.text
.global main
.type main, %function

main:
	MOV R0, #0
	LDR R1, =Hello
	LDR R2, =Hello2
	LDR R3, =SIZE
	LDRB R3, [R3]
	LDR R4, =SAME
	MOV R5, #1

	loop:
		LDRB R6, [R1, R0]
		LDRB R7, [R2, R0]
		CMP R6, R7
		BNE not_same
		ADD RO, RO, #1
		CMP R0, R3
		BLT loop

	not_same:
		MOV R5, #0
		STRB R5, [R4]


stop:   B stop
		BX LR
.end











