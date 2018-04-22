.text
main:	li $v0, 5
	syscall
	or $t1, $v0, $0
	addiu $t3, $0, 1
	slti $t2, $t1, 1
	beq $t2, 1, endF
FactL:	mul $t3, $t3, $t1
	addiu $t1, $t1, -1
	bnez $t1, FactL

endF:   li $v0, 1
	or $a0, $t3, $0
	syscall