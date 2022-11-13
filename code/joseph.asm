.macro readi(%reg)
	li $v0, 5
	syscall
	move %reg, $v0
.end_macro 
.macro printi(%reg)
	li $v0, 1
	move $a0, %reg
	syscall
.end_macro
.macro prints(%saddr)
	li $v0, 4
	la $a0, %saddr
	syscall
.end_macro
.data 
	person: .space 800
	is_del: .space 800
	space: .asciiz " "
	enter: .asciiz "\n"
.text
	#s0 n; s1  start; gap s2; m s3; cntm s4; 
	#s5 cntgap; s6 cnt_del
	readi($s0)
	readi($s1)
	readi($s2)
	readi($s3)
	li $t0, 1
	for_t0_begin:
	sle $t1, $t0, $s0
	beq $t1, $0, for_t0_end
	
	printi($t0)
	prints(space)
	#li $t2, 1
	#sll $t3, $t0, 2
	#sw $t2, is_del($t3)
	addi $t0, $t0, 1
	j for_t0_begin
	for_t0_end:
	prints(enter)
	subi $s5, $s2, 1
	subi $s4, $s3, 1
	move $t0, $s1
	for_t0_begin1:
	sle $t1, $t0, $s0 # be careful with sle slt!!!
	beq $0, $t1, for_t0_end1 
	
	if1:
	bne $s6, $s0, ifend1
	j for_t0_end1
	ifend1:
	
	
	sll $t2, $t0, 2
	lw $t3, is_del($t2)
	
	if2:
	bne $0, $t3, if2else
	addi $s5, $s5, 1
		if21: 
		bne $s5, $s2, if21else
		addi $s4, $s4, 1
			if211:
			bne $s3, $s4, if211else
			printi($t0)
			prints(space)
			li $t5, 1
			sw $t5, is_del($t2)
			addi $s6, $s6, 1
			li $s4, 0
			
			j if211end
			if211else:
			if211end:
			li $s5, 0 ###if {} else {} xxx, xxx must be at the ifends!!!!!!!!!
		j if21end
		if21else:
		if21end:
		
		iff: #t0 >= s0
		blt $t0, $s0, elseiff
		li $t0, 1
		j iffend
		elseiff:#t0 < s0
		addi $t0, $t0, 1
		iffend:
	
	j if2end
	if2else:
	
		ifff: #t0 >= s0
		blt $t0, $s0, elseifff
		li $t0, 1
		j ifffend
		elseifff:#t0 < s0
		addi $t0, $t0, 1
		ifffend:
		j for_t0_begin1
	
	if2end:
	
	
	
	j for_t0_begin1
	for_t0_end1: 
	
	
	li $v0, 10 
	syscall