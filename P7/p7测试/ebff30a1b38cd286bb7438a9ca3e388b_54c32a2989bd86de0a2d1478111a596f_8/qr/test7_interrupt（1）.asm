.text
ori $1,$0,0x0c01   
mtc0 $1,$12  #��SR����
ori $2,$0,0x7f00
ori $3,$0,0x7f10
ori $4,$0,21
sw $4,4($2)  #preset timer0
ori $4,$0,25   
sw $4,4($3)  #preset timer1
ori $4,$0,11
sw $4,0($2) #��timer0��ʱ
sw $4,0($3) #��timer1��ʱ



loop:
addu $3,$2,$1
ori $4,$0,0x1234
multu $1,$2
div $3,$4
j loop
nop


