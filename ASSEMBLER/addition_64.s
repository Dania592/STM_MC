.data
const1_64bits_p1: .word 0xFFFFFFFE //Poids faibles mot 1 [31:0]
const1_64bits_p2: .word 0x02000000 //Poids forts mot 1 [63:32]
const2_64bits_p1: .word 0x00000011 //Poids faibles mot 2 [31:0]
const2_64bits_p2: .word 0x02000000 //Poids forts mot 2 [31:0]
const3_64bits: .skip 8
VAL: .word 0x87654321

.text
.global main
.type main, %function

main:
	MOV R0, #0x3A
	MOV R1, #0x0F
	MOV R2, #0x10
	AND R1, R0, R1
	AND R0, R0, R2
	ORR R0, R1, R0
	BIC R0, R0, R2

	LDR R0, =const1_64bits_p1
	LDR R0, [R0]

	LDR R1, =const1_64bits_p2
	LDR R1, [R1]

	LDR R2, =const2_64bits_p1
	LDR R2, [R2]

	LDR R3, =const2_64bits_p2
	LDR R3, [R3]
		
	ADD R0, R0, R2

	BVS add_one

	B seconde_part


	add_one:
		ADD R1, R1, #1
		B seconde_part

	seconde_part:
		ADD R3, R3, R1
		MOV R6, #0
		LDR R4, =const3_64bits
		STRB R1, [R4, R6]
		MOV R6, #1
		STRB R3, [R4, R6]


stop:   B stop
		BX LR
.end



