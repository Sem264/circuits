.text
main:	li $v0, 4
	la $a0, prompt1
	syscall
	li $v0, 8
	la $a0, matrix1
	li $a1, 128
	syscall
Mat1:	la $a0, matrix1
	add $t1, $0, $0
	add $t0, $0, $0
CntCl:	lb $t0, ($a0)
	beq $t0, 10, GetM1_
	beq $t0, 65, RefM1
	beq $t0, 44, Skip1
	addi $t1, $t1, 1
	addi $a0, $a0, 1
	b CntCl
Skip1:	addi $a0, $a0, 1
	b CntCl
GetM1_:	sb $t1, numColumns1
GetM1:	sb $0, ($a0)
	add $a1, $0, $0
	add $a1, $a0, $0
	li $v0, 4
	la $a0, prompt1_1
	syscall
	li $v0, 1
	lb $a0, numColumns1
	syscall
	li $v0, 4
	la $a0, prompt1_2
	syscall
	li $v0, 8
	add $a0, $0, $0
	add $a0, $a1, $0
	li $a1, 128
	syscall
	add $t0, $0, $0
	lb $t0, ($a0)
	add $a0, $a0, $t1
	add $a0, $a0, $t1
	addi $a0, $a0, -1
	beq $t0, 65, RefM1
	b GetM1

RefM1:	sub $a0, $a0, $t1
	sub $a0, $a0, $t1
	addi $a0, $a0, 1
	sb $0, ($a0)
	sb $0, 1($a0)
	la $a0, matrix1
	la $a1, refinedMatrix1
	add $t0, $0, $0
RefLp1:	lb $t0, ($a0)
	beqz $t0, GetM2_
	beq $t0, 44, SkipR1
	sb $t0, ($a1)
	addi $a1, $a1, 1
SkipR1:	addi $a0, $a0, 1
	b RefLp1
	
GetM2_:	li $v0, 4
	la $a0, prompt2
	syscall
	li $v0, 8
	la $a0, matrix2
	li $a1, 128
	syscall
Mat2:	la $a0, matrix2
	add $t1, $0, $0
	add $t0, $0, $0
CntCl2:	lb $t0, ($a0)
	beq $t0, 10, GetM2__
	beq $t0, 65, RefM2
	beq $t0, 44, Skip2
	addi $t1, $t1, 1
	addi $a0, $a0, 1
	b CntCl2
Skip2:	addi $a0, $a0, 1
	b CntCl2
GetM2__:sb $t1, numColumns2
GetM2:	sb $0, ($a0)
	add $a1, $0, $0
	add $a1, $a0, $0
	li $v0, 4
	la $a0, prompt2_1
	syscall
	li $v0, 1
	lb $a0, numColumns2
	syscall
	li $v0, 4
	la $a0, prompt2_2
	syscall
	li $v0, 8
	add $a0, $0, $0
	add $a0, $a1, $0
	li $a1, 128
	syscall
	add $t0, $0, $0
	lb $t0, ($a0)
	add $a0, $a0, $t1
	add $a0, $a0, $t1
	addi $a0, $a0, -1
	beq $t0, 65, RefM2
	b GetM2

RefM2:	sub $a0, $a0, $t1
	sub $a0, $a0, $t1
	addi $a0, $a0, 1
	sb $0, ($a0)
	sb $0, 1($a0)
	la $a0, matrix2
	la $a1, refinedMatrix2
	add $t0, $0, $0
RefLp2:	lb $t0, ($a0)
	beqz $t0, TranM2
	beq $t0, 44, SkipR2
	sb $t0, ($a1)
	addi $a1, $a1, 1
SkipR2:	addi $a0, $a0, 1
	b RefLp2

TranM2:	add $t0, $0, $0
	lb $t0, numColumns2
	add $t1, $0, $0
	lb $t1, numColumns1
	la $a0, refinedMatrix2
	la $a1, transposeMatrix2
	add $t2, $0, $0
	add $t3, $0, $0
	add $t4, $0, $0
TranLp:	beq $t3, $t1, RstLp
	lb $t2, ($a0)
	sb $t2, ($a1)
	addi $a1, $a1, 1
	add $a0, $a0, $t0
	addi $t3, $t3, 1
	b TranLp
RstLp:	addi $t4, $t4, 1
	beq $t4, $t0, MulMs
	la $a0, refinedMatrix2
	add $a0, $a0, $t4
	add $t3, $0, $0
	b TranLp
	#Now goes multiplication
MulMs:	la $a0, refinedMatrix1
	la $a1, transposeMatrix2
	la $a2, resultMatrix
	add $t0, $0, $0
	lb $t0, numColumns1
	add $t1, $0, $0
	lb $t1, numColumns2
	add $t4, $0, $0
	add $t5, $0, $0
	add $t6, $0, $0
MulLp:	beq $t5, $t0, RstMLp
	add $t2, $0, $0
	add $t3, $0, $0
	lb $t2, ($a0)
	lb $t3, ($a1)
	addi $t2, $t2, -48
	addi $t3, $t3, -48
	mul $t3, $t3, $t2
	add $t4, $t4, $t3
	addi $t5, $t5, 1
	addi $a0, $a0, 1
	addi $a1, $a1, 1
	b MulLp
RstMLp:	sb $t4, ($a2)
	addi $a2, $a2, 1
	add $t4, $0, $0
	add $t5, $0, $0
	addi $t6, $t6, 1
	beq $t6, $t1, RRstMLp
	sub $a0, $a0, $t0
	b MulLp
RRstMLp: add $t6, $0, $0
	lb $t2, ($a0)
	beqz $t2, ShwRes
	la $a1, transposeMatrix2
	b MulLp
	
ShwRes:	lb $t0, numColumns2
	la $a1, resultMatrix
	add $t2, $0, $0
	add $t4, $0, $0
	add $t3, $0, $0
ShwLp:	lb $t2, ($a1)
	beqz $t2, FinMul_
RetF:	li $v0, 1
	add $a0, $0, $0
	add $a0, $t2, $0
	syscall
	li $v0, 4
	la $a0, space
	syscall
	addi $a1, $a1, 1
	addi $t3, $t3, 1
	bne $t3, $t0, ShwLp
	li $v0, 4
	la $a0, newLine
	syscall
	add $t3, $0, $0
	b ShwLp
FinMul_:lb $t2, 1($a1)
	beqz $t2, FinMul
	lb $t2, ($a1)
	b RetF
FinMul:

.data
prompt1: .asciiz "Input by row the first matrix: "
prompt1_1: .asciiz "Input the next row of "
prompt1_2: .asciiz " elements or A to finish: "
prompt2: .asciiz "\nInput by row the second matrix: "
prompt2_1: .asciiz "Input the next row of "
prompt2_2: .asciiz " elements or A to finish"
matrix1: .space 128
refinedMatrix1: .space 128
matrix2: .space 128
refinedMatrix2: .space 128
transposeMatrix2: .space 128
.align 0
resultMatrix: .space 256
.align 0
numColumns1: .byte 0
.align 0
numColumns2: .byte 0
space: .asciiz " "
newLine: .asciiz "\n"