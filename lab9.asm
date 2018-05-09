.text
main:	li $v0, 4
	la $a0, welcomeStr
	syscall
	li $v0, 8
	la $a0, sparseVector
	li $a1, 31
	syscall
	la $t1, sparseVector
	add $t5, $0, $0   # $t5 is the counter for order vector
	add $t7, $0, $0	  # $t7 is the counter for value vector
	add $t8, $0, $0
PrsV:	lb $t8, ($t1)
	beqz $t8, DotPr   # if $t1 == 0, we're at the terminator
	beq $t8, 44, MidSt # if meet "," - advance the counter and continue 
	beq $t8, 48, WrZero # if meet "0" - write zero at the order vector
	bne $t8, 10, WrOne    # if meet "1" - write one at the order vector and the value at the valueVector
	addi $t1, $t1, 1  # increment the counter 
	b PrsV
	
	
MidSt:  addi $t1, $t1, 1
	b PrsV

WrZero:	la $a0, orderVector
	add $a0, $a0, $t5
	add $t9, $0, $0
	addi $t9, $t9, 48
	sb $t9, ($a0)	# orderVector[counter] = 0
	add $t9, $0, $0
	add $t3, $0, $0
	addi $t3, $t3, 44
	sb $t3, 1($a0)
	and $a0, $a0, $0
	addi $t5, $t5, 2
	addi $t1, $t1, 1
	b PrsV	
	
WrOne:	la $a0, orderVector
	add $a0, $a0, $t5
	add $t6, $0, $0
	addi $t6, $t6, 49
	sb $t6, ($a0)	# orderVector[counter] = 1
	add $t6, $0, $0
	addi $t6, $0, 44
	sb $t6, 1($a0)
	add $t6, $0, $0
	addi $t5, $t5, 2
	#la $a0, sparseVector
	lb $t6, ($t1)
	la $a1, valueVector
	add $a1, $a1, $t7
	sb $t6, ($a1)	# orderVector[counter] = 1
	add $t6, $0, $0
	addi $t6, $t6, 44
	sb $t6, 1($a1)
	add $t6, $0, $0
	addi $t7, $t7, 2
	addi $t1, $t1, 1
	
	b PrsV	
	
DotPr:  la $a0, orderVector
	add $a0, $a0, $t5
	sb $0, -1($a0)	# orderVector[counter] = 1
	la $a1, valueVector
	add $a1, $a1, $t7
	sb $0, -1($a1)	# orderVector[counter] = 1
	add $t9, $0, $0
	la $a0, orderVector
	la $a1, valueVector
DotLp:  add $t3, $0, $0
	add $t4, $0, $0
	lb $t3, ($a1)
	beqz $t3, EndLp
	addi $t3, $t3, -48
	lb $t4, ($a0)
	addi $t4, $t4, -48
	mult $t3, $t4
	mflo $t3
	add $t9, $t9, $t3
	addi $a1, $a1, 2
	addi $a0, $a0, 2
	b DotLp
	


EndLp:  li $v0, 1
	add $a0, $t9, $0
	syscall
	


.data
welcomeStr: .asciiz "Enter a sparse vector: "
goodbyeStr: .asciiz "GGWP"
sparseVector: .space 32
#sparseVector: .asciiz "0,2,4,2"
orderVector: .space 32
valueVector: .space 16
notZFound: .asciiz "Found not zero \n"
