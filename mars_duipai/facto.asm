.macro get_addr (%ireg)
.end_macro 
.data
	res:	.space 10000
	zero6: .asciiz "000000"
	zero5: .asciiz "00000"
	zero4: .asciiz "0000"
	zero3: .asciiz "000"
	zero2: .asciiz "00"
	zero1: .asciiz "0"
.text
	li $v0, 5
	syscall
	move $s0, $v0
	li $t0, 1
	sw $t0, res
	li $s1, 0
	#s0 as n, s1 as high, t0 as i, t2 as j
	li $t9, 1
	for_t9_begin:
	sle $t8, $t9, $s0
	beq $t8, $0 for_t9_end
					li $t2, 0
					for_t2_begin:
					sle $t3, $t2, $s1
					beq $t3, $0, for_t2_end
					
					#t4 as i*res[j], t5 as addr
					sll $t5, $t2, 2
					lw $t4, res($t5)
					mul $t4, $t4, $t9
					sw $t4, res($t5)
					
					addi $t2, $t2, 1
					j for_t2_begin
					for_t2_end:

					#carry as s2, high as s1, s0 as n
					li $t0, 0
					for_t0_begin1:
					sle $t1, $t0, $s1
					beq $t1, $0, for_t0_end1
	
					#res[j] as t2, addr as t3, 
					sll $t3, $t0, 2
					lw $t2, res($t3)
					add $t4, $s2, $t2
					li $t5, 1000000
					div $t4, $t5
					mfhi $t6
					sw $t6, res($t3)
					mflo $s2
		
					addi $t0, $t0, 1
					j for_t0_begin1
					for_t0_end1:
	
					#carry as s2, t0 as j before, high as s1, s0 as n
					while_s2_begin:
					beq $s2, $0, while_s2_end
					li $t3, 1000000
					div $s2, $t3
					mfhi $t2 #t2 = carry%10

					sll $t1, $t0, 2
					sw $t2, res($t1)
					addi $t0, $t0, 1
	
					mflo $s2	 #s2 = carry/10
					addi $s1, $s1, 1
					j while_s2_begin# while !!!must jump back
					while_s2_end:
	
	addi $t9, $t9, 1
	j for_t9_begin
	for_t9_end:
	
	
	move $t0, $s1
	
	sll $t2, $t0, 2
	lw $t2, res($t2)
	li $v0, 1
	move $a0, $t2
	syscall
	subi $t0, $t0, 1
	for_t0_begin2:
	sge $t1, $t0, $0
	beq $0, $t1, for_t0_end2
	
	sll $t2, $t0, 2
	
	
	
	lw $t2, res($t2)
	bge $t2, 10, passs
	li $v0, 4
	la $a0, zero5
	bge $t2, 100, passs
	li $v0, 4
	la $a0, zero4
	bge $t2, 1000, passs
	li $v0, 4
	la $a0, zero3
	bge $t2, 10000, passs
	li $v0, 4
	la $a0, zero2
	bge $t2, 100000, passs
	li $v0, 4
	la $a0, zero1
	#printf("%d", res[i])
	passs:
	li $v0, 1
	move $a0, $t2
	syscall
	
	subi $t0, $t0, 1
	j for_t0_begin2
	for_t0_end2:
	li $v0, 10
	syscall
