.macro save_reg(%reg) 
	subi $sp, $sp, 4
	sw %reg, ($sp)  
.end_macro 

.macro restore(%reg) 
	lw %reg, ($sp)
	addi $sp, $sp, 4 
.end_macro 
.data
	a: .space 800
	stack: .space 800
	
.text 
	main:
	la $sp, stack+800
	li $t1, 4 
	sw $t1, a
	li $t1, 2
	sw $t1, a+4
	li $t1, 3
	sw $t1, a+8
	li $t1, 1
	sw $t1, a+12
	li $t1, 10
	sw $t1, a+16
	li $t1, 10
	sw $t1, a+20
	li $a0, 3 #a0 is key
	li $a1, 5 #a1 is high
	li $a2, 0 #a2 is low
	jal bin_search
	
	
	
	
	
	li $s0, 6
	for_t0_begin:
	slt $t1, $t0, $s0 
	beq $t1, 0, for_t0_end
	
	addi $t0, $t0, 1
	j for_t0_begin
	for_t0_end:
	j end 
	

	bin_search:
	save_reg($ra) 
	move $t1, $a0 # key 
	move $t0, $a2 # low 
	move $t2, $a1 # high 
	ble $t0, $t2, iflowhigh
	j end
	iflowhigh:
		add $t3, $t0, $t2 
		srl $t3, $t3, 1 #t3 is mid
	
		sll $t5, $t3, 2 # get for byteAddr 
		lw $t4, a($t5)
		beq  $t4, $t1, ifequal
		blt  $t4, $t1, ifless
		bgt  $t4, $t1, ifgt
		ifequal:
			move $v0, $t3
			restore($ra)
			jr $ra
		ifless: # a[mid] < key
		
			addi $a0, $t1, 0 #a0 is key
			addi $a1, $t2, 0 #a1 is high
			addi $a2, $t3, 1 #a2 is low
			jal bin_search
			restore($ra)
			jr $ra 
		ifgt: # a[mid] > key
			addi $a0, $t1, 0 #a0 is key
			addi $a1, $t3, -1 #a1 is high
			addi $a2, $t2, 0 #a2 is low
			jal bin_search
			restore($ra)
			jr $ra 
	 
	end:
		li $v0, -1
		restore($ra)
		jr $ra 
		