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
	beqz $t8, Rd2nd   # if $t1 == 0, we're at the terminator
	beq $t8, 44, MidSt # if meet "," - advance the counter and continue 
	beq $t8, 48, WrZero # if meet "0" - write zero at the order vector
	bne $t8, 10, WrOne    # if meet not "0" - write one at the order vector and the value at the valueVector
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
	
Rd2nd:	la $a0, orderVector
	add $a0, $a0, $t5
	sb $0, -1($a0)	# orderVector[counter] = 1
	la $a1, valueVector2
	add $a1, $a1, $t7
	sb $0, -1($a1)	# orderVector[counter] = 1
	li $v0, 4
	la $a0, welcomeStr2
	syscall
	li $v0, 8
	la $a0, sparseVector2
	li $a1, 31
	syscall
	la $t1, sparseVector2
	add $t5, $0, $0   # $t5 is the counter for order vector
	add $t7, $0, $0	  # $t7 is the counter for value vector
	add $t8, $0, $0
PrsV2:	lb $t8, ($t1)
	beqz $t8, DotPr   # if $t1 == 0, we're at the terminator
	beq $t8, 44, MidSt2 # if meet "," - advance the counter and continue 
	beq $t8, 48, WrZero2 # if meet "0" - write zero at the order vector
	bne $t8, 10, WrOne2    # if meet not "0" - write one at the order vector and the value at the valueVector
	addi $t1, $t1, 1  # increment the counter 
	b PrsV2
	
	
MidSt2:  addi $t1, $t1, 1
	b PrsV2

WrZero2: la $a0, orderVector2
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
	b PrsV2	
	
WrOne2:	la $a0, orderVector2
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
	la $a1, valueVector2
	add $a1, $a1, $t7
	sb $t6, ($a1)	# orderVector[counter] = 1
	add $t6, $0, $0
	addi $t6, $t6, 44
	sb $t6, 1($a1)
	add $t6, $0, $0
	addi $t7, $t7, 2
	addi $t1, $t1, 1
	b PrsV2
	

	
DotPr:  la $a0, orderVector
	la $a1, valueVector
	la $a2, orderVector2
	la $a3, valueVector2
#0,5,1,1,0,0,0    -   0,1,1,1,0,0,0 & 5,1,1
#0,0,0,5,1,1,0    -   0,0,0,1,1,1,0 & 5,1,1
#=>5

	add $a2, $a2, $t5
	sb $0, -1($a2)	# orderVector[counter] = 1
	add $a3, $a3, $t7
	sb $0, -1($a3)	# orderVector[counter] = 1
	la $a2, orderVector2
	la $a3, valueVector2
	add $t9, $0, $0
	add $t0, $0, $0
	add $t1, $0, $0
	add $t2, $0, $0
DotLp:  add $t3, $0, $0
	add $t4, $0, $0
	lb $t3, ($a0)
	lb $t4, ($a2)
	beqz $t3, EndLp
	beq $t3, 48, Skip2
	beq $t3, 44, Skip2
	beq $t4, 48, Skip2
	beq $t4, 44, Skip2
	beq $t3, $t4, Sum2
Skip2:	addi $a0, $a0, 1
	addi $a2, $a2, 1
	addi $a1, $a1, 1
	addi $a3, $a3, 1
	b DotLp
	
	
Sum2:	lb $t0, ($a1)
	lb $t1, ($a3)
	add $t8, $0, $0
	addi $t0, $t0, -48
	addi $t1, $t1, -48
	mul $t8, $t0, $t1
	add $t2, $t2, $t8
	addi $a0, $a0, 1
	addi $a2, $a2, 1
	addi $a1, $a1, 1
	addi $a3, $a3, 1
	b DotLp

EndLp:  li $v0, 1
	add $a0, $t2, $0
	syscall
	


.data
welcomeStr: .asciiz "Enter a sparse vector: "
welcomeStr2: .asciiz "Enter the second sparse vector: "
goodbyeStr: .asciiz "GGWP"
orderVector: .space 32
valueVector: .space 16
sparseVector: .space 32
orderVector2: .space 32
valueVector2: .space 16
sparseVector2: .space 32