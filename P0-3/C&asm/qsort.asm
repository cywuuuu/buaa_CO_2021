.macro printi(%reg)
	li $v0, 1
	move $a0, %reg
	syscall
.end_macro 
.macro readi(%reg)
	li $v0, 5
	syscall
	move %reg, $v0
.end_macro
.macro prints(%addr)
	li $v0, 4
	la $a0, %addr
	syscall
.end_macro
.macro save_reg(%reg)
	subi $sp, $sp, 4
	sw %reg, ($sp)
.end_macro 
.macro restore_reg(%reg)
	lw %reg, ($sp)
	addi $sp, $sp, 4
.end_macro
.data
	arr: .space 800
	stack: .space 800
	space: .asciiz " "
	enter: .asciiz "\n" 
.text
	la $sp, stack+800
	readi($s0)
	li $t0, 1
	for_t0_begin:
	sle $t1, $t0, $s0
	beq $t1, $0, for_t0_end
	
	sll $t2, $t0, 2
	readi($t3)
	sw $t3, arr($t2)
	
	addi $t0, $t0, 1
	j for_t0_begin
	for_t0_end:
	
	li $a0, 1
	move $a1, $s0
	save_reg($s0) #save temp for comeback like i
	jal qsort
	restore_reg($s0)
	
	li $t0, 1
	for_t0_begin1:
	sle $t1, $t0, $s0
	beq $t1, $0, for_t0_end1
	
	sll $t2, $t0, 2
	lw $t3, arr($t2)
	printi($t3)
	prints(space)
	
	addi $t0, $t0, 1
	j for_t0_begin1
	for_t0_end1:
	#again !!! no syscall makes you die
	li $v0, 10
	syscall
qsort:
	save_reg($ra)#save $ra for return 
	# save long term $s0 for go back
	
	move $t0, $a0 #i = l
	move $t1, $a1 #j = r
	add $t2, $t0, $t1
	div $t2, $t2, 2 # i+j/2
	sll $t2, $t2, 2        
	lw $t3, arr($t2)#a[i+j]/2
	while1:
	bge $t0, $t1, while1_end
		while11:
		sll $t4, $t0, 2
		lw $t4, arr($t4) #a[i]
		
		bge $t4, $t3, while11_end
		addi $t0, $t0, 1
		j while11
		while11_end:
		
		while12:
		sll $t4, $t1, 2
		lw $t4, arr($t4) #a[j]
		ble $t4, $t3, while12_end
		subi $t1, $t1, 1
		j while12
		while12_end:
		  
		ble $t0, $t1, if
		j endif
		if:
		sll $t4, $t0, 2
		lw $t5, arr($t4)
		
		sll $t6, $t1, 2
		lw $t7, arr($t6)
		
		sw $t7, arr($t4)
		sw $t5, arr($t6)
		
		addi $t0, $t0, 1
		subi $t1, $t1, 1  
		
		endif:
	
	j while1 
	while1_end:
	#a0 l, a1 r, t0 i, t1 j
	
	blt $a0, $t1, if1
	j if1end
	if1:
	save_reg($t0)
	save_reg($a1)
	save_reg($a0)
	save_reg($t1)
	move $a0, $a0
	move $a1, $t1
	jal qsort
	restore_reg($t1)
	restore_reg($a0)
	restore_reg($a1)
	restore_reg($t0)
	if1end:
	
	blt $t0, $a1, if2
	j if2end
	if2:
	save_reg($t0)
	save_reg($a1)
	save_reg($a0)
	save_reg($t1)	

	move $a0, $t0
	move $a1, $a1
	jal qsort
	restore_reg($t1)
	restore_reg($a0)
	restore_reg($a1)
	restore_reg($t0)
	if2end:
	
	restore_reg($ra)
	jr $ra










