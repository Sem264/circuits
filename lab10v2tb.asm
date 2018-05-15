.text
main:	li $v0, 4
	la $a0, welcomeStr
	syscall
	li $v0, 8
	la $a0, input
	li $a1, 31
	syscall
	la $a1, input
	jal bbSort
	b EndEx
	
bbSort:	addi $sp, $sp, -8
	sw $ra, 4($sp)
	sw $a1, ($sp)
	
	add $t1, $0, $0
	add $t2, $0, $0
	addi $t2, $0, 44
	lw $a1, ($sp)
	add $t3, $0, $0   # $t3 = counter of elements in input
Count:  lb $t1, ($a1)
	beqz $t1, AftCnt
	beq $t1, $t2, NotCnt
	sb $t1, ($a1)
	addi $a1, $a1, 1
	addi $t3, $t3, 1
NotCnt:	addi $a1, $a1, 1
	b Count
	
AftCnt:	addi $a1, $a1, -1
	addi $t3, $t3, -1
	sb $0, ($a1)
	add $t1, $0, $0
	add $t0, $0, $0
	add $t4, $0, $0
	add $t5, $0, $0
	lw $a0, ($sp)
Sort1:	beq $t4, $t3, newIt
	lb $t0, ($a0)
	lb $t1, 2($a0)
	slt $t5, $t0, $t1
	bnez $t5, ContS1
	
	#add $sp, $sp, 4
	add $t6, $0, $0
	add $t6, $t1, $0
	add $t7, $0, $0
	add $t7, $t0, $0
	add $sp, $sp, -8
	sw $t6, 4($sp)
	sw $t7, ($sp)
	jal Swap
	
ContS1:	addi $a0, $a0, 2
	addi $t4, $t4, 1
	b Sort1
	
ClSwap:	
	
Swap: 	lw $t6, 4($sp)
	lw $t7, ($sp)
	sb $t6, ($a0)
	sb $t7, 2($a0)
	addi $sp, $sp, 8
	jr $ra
		
newIt: 	beqz $t3, ResSh
	add $t4, $0, $0
	addi $t3, $t3, -1
	la $a0, input
	b Sort1
	
ResSh:	li $v0, 4
	la $a0, resultStr
	syscall
	li $v0, 4
	la $a0, divideStr
	syscall
	lw $ra, 4($sp)
	addi $sp, $sp, 8
	jr $ra

EndEx:	li $v0, 4
	la $a0, exitStr
	syscall

.data
welcomeStr: .asciiz "Enter the sequence of numbers to sort: "
resultStr: .ascii "Result of the bubble sort is: "
input: .space 32
divideStr: .asciiz "\n"
exitStr: .asciiz "Thanks for playing"


