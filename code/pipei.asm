.data
	str: .space 800
	pat: .space 800
.text 
	#li $t0, 0
	#for_t0_begin1:
	#li $v0, 12
	#syscall
	#beq $v0, '\n', for_t0_end1
	#sb $v0, str($t0)
	
	#addi $t0, $t0, 1
	#j for_t0_begin1
	#for_t0_end1:
	
	li $v0, 8
	la $a0, str
	li $a1, 100
	syscall
	
	li $v0, 8
	la $a0, pat
	li $a1, 100
	syscall
	
	li $s0, 0
	li $t0, 0
	for_t0_begin:nop
	lb $t1, str($t0)
	beq $t1, '\n', for_t0_end
		move $t2, $t0 #j = i
		li $t3, 0 #k = 0
		for_t2t3_begin:nop
		lb $t4, pat($t3)
		lb $t5, str($t2)
		sne $t6, $t4, '\n'
		seq $t7, $t5, $t4
		and $t8, $t6, $t7
		beq $0, $t8, for_t2t3_end
		
		addi $t2, $t2, 1
		addi $t3, $t3, 1
		j for_t2t3_begin
		for_t2t3_end:
		
		lb $t9, pat($t3)
		beq $t9, '\n', if
		j endif
		if:
			move $s0, $t0
			j end
		endif:
		
	addi $t0, $t0, 1
	j for_t0_begin
	for_t0_end:
	li $s0, 23333
	end:
	li $v0, 1
	move $a0, $s0
	syscall
	
	
	
	
