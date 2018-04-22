.text
main:	lw $t1, a
	lw $t2, b
	add $t3, $t2, $t1
	and $t2, $t2, $0
	and $t1, $t1, $0
	lw $t1, c
	lw $t2, d
	sub $t4, $t1, $t2
	and $t2, $t2, $0
	and $t1, $t1, $0
	sub $t5, $t3, $t4
	li $v0, 1
	or $a0, $t5, $0
	syscall



.data
a: .word 5
b: .word 3
c: .word 9
d: .word 7