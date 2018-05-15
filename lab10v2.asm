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
bbSort: addi $sp, $sp, -4
	sw $a1, ($sp)      # $a1 = &input[0]
	add $t1, $0, $0
	add $t2, $0, $0
	addi $t2, $0, 44
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
	sb $0, ($a1)	# now input contains input[]
	add $t1, $0, $0
	add $t0, $0, $0
	add $t4, $0, $0
	add $t5, $0, $0
	la $a0, input
Sort1:	beq $t4, $t3, newIt
	lb $t0, ($a0)
	lb $t1, 2($a0)
	slt $t5, $t0, $t1
	beq $t5, $0, Swap
	addi $a0, $a0, 2
	addi $t4, $t4, 1
	b Sort1
	
Swap: 	add $t6, $0, $0
	add $t6, $t1, $0
	add $t7, $0, $0
	add $t7, $t0, $0
	sb $t6, ($a0)
	sb $t7, 2($a0)
	addi $a0, $a0, 2
	addi $t4, $t4, 1
	b Sort1
		
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
	addi $sp, $sp, 4
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
