.data
N:		.byte 5  /*Taille */
tab:	.byte 14, 25, 2, 16, 5 /*déclaration d'un tableau tab  */

.text
.global main
.type main, %function

main:
		LDR R0,=N /*taille*/
		LDRB R0, [R0]
		/*----ZONE A COMPLETER*/
		LDR R1, =tab
		MOV R2, #0 // indice de parcours i
		MOV R3, #1 // indice i+1

		while_loop:
			LDRB R4, [R1, R2] //tab[i]
			LDRB R5, [R1, R3] //tab[i+1]
			CMP R5, R4
			BLT permute // tab[i+1] < tab[i]
			ADD R2, R2, #1
			ADD R3, R3, #1
			CMP R2, R0
			BLT while_loop


		permute:
			MOV R6, #0
			STRB R5, [R1, R2] // tab[i+1] = tab[i]
			STRB R4, [R1, R3] //tab[i] = tmp
			CMP R2, R6
			BGT decrement
			B while_loop

		decrement:
				SUB R2, R2, #1
				SUB R3, R3, #1
				B while_loop



stop:   B stop
		BX LR
.end



