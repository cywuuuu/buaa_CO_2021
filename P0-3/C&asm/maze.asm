.macro get_addr(%ireg, %jreg, %addrreg, %mreg)
	mul %addrreg, %ireg, %mreg
	add %addrreg, %addrreg, %jreg
	sll %addrreg, %addrreg, 2
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
	vis:		.space 800
	maze:	.space 800
	stack:	.space 800
.text
	li $t9, 0 #t9 as cnt
	la $sp, stack+800
	li $v0, 5
	syscall
	li $t8, 0 #t8 as num
	move $s0, $v0 #s0 as n
	li $v0, 5
	syscall
	move $s1, $v0 #s1 as m	
	# i=1; i<=n; i++. t0 as i, t1 as flag
	li $t0, 1
	for_t0_begin:
	bgt $t0, $s0, for_t0_end
	
		# j=1; j<=m;j++, t2 as j, t3 as flag
		li $t2, 1
		for_t2_begin:
		bgt $t2, $s1, for_t2_end
			
			# s2 as addrreg
			get_addr($t0, $t2, $s2, $s1)
			li $v0, 5
			syscall
			sw $v0, maze($s2)
			
		addi $t2, $t2, 1
		j for_t2_begin
		for_t2_end:
		
	addi $t0, $t0, 1
	j for_t0_begin
	for_t0_end:
	#s0s1 n,m; s2,addr; 
	
	# read s3s4 x1,y1; s5s6 x2,x2; t9 cnt
	li $v0, 5
	syscall
	move $s3, $v0
	li $v0, 5
	syscall
	move $s4, $v0
	li $v0, 5
	syscall
	move $s5, $v0
	li $v0, 5
	syscall
	move $s6, $v0
	
	move $a0, $s3
	move $a1, $s4
	jal dfs
	
	li $v0, 1
	move $a0, $t9
	syscall
	li $v0, 10
	syscall
dfs:
#a0 as x, a1 as y, t8 as num
	save_reg($ra)
	#move $s3, $a0
	#move $s4, $a1
	# push num
	# save_reg($t8)
	#t0 as addr_vis
	get_addr($a0, $a1, $t0, $s1)
	li $t1, 1
	sw $t1, vis($t0)
	#addi $t8, $t8, 1
	
	#ble $t0, $s3, 0# t0 as flag, s3 as x, s4 as y,
	#slt $t1, $s0, $s3# s0 as n, s1 as m, s2 addrreg/maze[x][y]
	#or $t0, $t1, $t0
	
	#sle $t1, $s4, 0
	#or $t0, $t0, $t1
	
	#slt $t1, $s1, $s4
	#or $t0, $t0, $t1
	
	#get_addr($s3, $s4, $s2, $s1)
	#lw $s2, maze($s2)
	#slt $t1, $0, $s2
	#or $t0, $t0, $t1
	#beq $t0, $0, pass # if( x <= 0 || x > n || y <= 0 || y > m || maze[x][y] )
	#********************************************
	#	if( x <= 0 || x > n || y <= 0 || y > m || maze[x][y] ){
	#	//num--;
	#	//vis[num][0] = vis[num][1] = 0;
	#	return 0;
	#	}
	#********************************************
	ble $a0, 0, if1
	blt $s0, $a0, if1
	ble $a1, 0, if1
	blt $s1, $a1, if1
	get_addr($a0, $a1, $s2, $s1)
	lw $s2, maze($s2)
	blt $0, $s2, if1
	j pass
	if1:
	#subi $t8, $t8, 1
	
	#get_vis_addr($t8, $t1, 0)#t1 addr_vis
	#sw $0, vis($t1)
	#get_vis_addr($t8, $t1, 1)
	#sw $0, vis($t1)	# vis[num][0] = vis[num][1] = 0;
	get_addr($a0, $a1, $t0, $s1)
	sw $0, vis($t0)
	restore_reg($ra)
	jr $ra	# return 
	
	pass:
	#****************************************
	#	if(x == x2 && y == y2) {
	#		num--;
	#		//vis[num][0] = vis[num][1] = 0;
	#		cnt++;
	#		return 1;
	#	}
	#****************************************
	#s5s6 as x2, y2, s3 x, s4 y
	bne $a0, $s5, pass2
	bne $a1, $s6, pass2
	#subi $t8, $t8, 1
	#t4 as vis[num][0], t5 as vis[num][1]
	#get_vis_addr($t8, $t4, 0)
	#get_vis_addr($t8, $t5, 1)
	#sw $0, vis($t4)
	#sw $0, vis($t5)
	addi $t9, $t9, 1
	get_addr($a0, $a1, $t0, $s1)
	sw $0, vis($t0)
	restore_reg($ra)
	jr $ra
	pass2:
	#*****************************************
	#	else {
	#	
	#		//vis[num][0] = x;
	#		//vis[num][1] = y;
	#		num++; 
	#		dfs(x+1, y);
	#		dfs(x, y+1);
	#		dfs(x-1, y);
	#		dfs(x, y-1);
	#		num--;
	#		//vis[num][0] = vis[num][1] = 0;
	#		return 1;
	#	}
	#*****************************************
	#t0 x+1, t1 x-1, t2 y+1, t3 y-1, s3 x, s4 y
	addi $t8, $t8, 1
	#subi $sp, $sp, 4
	#sw $s4, ($sp)
	#subi $sp, $sp, 4
	#sw $s3, ($sp)
	
	addi $t2, $a0, 1
	addi $t3, $a1, 0
	get_addr($t2, $t3, $t0, $s1)
	lw $t1, vis($t0)
	bne $0, $t1, p1
	save_reg($a0)
	save_reg($a1)# becareful with sequence!!!
	addi $a0, $a0, 1
	#addi $a1, $a1, 0
	jal dfs
	restore_reg($a1)
	restore_reg($a0)
	p1:
	#lw $s4, 4($sp)
	#lw $s3, 8($sp)
	addi $t2, $a0, 0
	addi $t3, $a1, 1
	get_addr($t2, $t3, $t0, $s1)
	lw $t1, vis($t0)
	bne $0, $t1, p2
	save_reg($a0)
	save_reg($a1)
	#addi $a0, $a0, 0
	addi $a1, $a1, 1
	jal dfs
	restore_reg($a1)
	restore_reg($a0)
	p2:
	#lw $s4, 4($sp)
	#lw $s3, 8($sp)
	addi $t2, $a0, -1
	addi $t3, $a1, 0
	get_addr($t2, $t3, $t0, $s1)
	lw $t1, vis($t0)
	bne $0, $t1, p3
	save_reg($a0)
	save_reg($a1)
	addi $a0, $a0, -1
	#addi $a1, $a1, 0
	jal dfs
	restore_reg($a1)
	restore_reg($a0)
	p3:
	#lw $s4, 4($sp)
	#lw $s3, 8($sp)
	addi $t2, $a0, 0
	addi $t3, $a1, -1
	get_addr($t2, $t3, $t0, $s1)
	lw $t1, vis($t0)
	bne $0, $t1, p4
	save_reg($a0)
	save_reg($a1)
	#addi $a0, $a0, 0
	addi $a1, $a1, -1
	jal dfs
	restore_reg($a1)
	restore_reg($a0)
	p4:
	subi $t8, $t8, 1
	#get_vis_addr($t8, $t4, 0)
	#get_vis_addr($t8, $t5, 1)
	#sw $0, vis($t4)
	#sw $0, vis($t5)
	get_addr($a0, $a1, $t0, $s1)
	sw $0, vis($t0)
	restore_reg($ra)
	jr $ra
