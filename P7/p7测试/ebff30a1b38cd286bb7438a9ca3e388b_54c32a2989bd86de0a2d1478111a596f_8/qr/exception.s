.text# 0x00004180
mfc0 $11,$13 #��cause
ori $10,$0,0x007c
and $11,$11,$10 
sra $11,$11,2 #11<=exccode
ori $12,$0,4 #pc��ȡ����
ori $13,$0,5 #������
ori $14,$0,10 #�Ƿ�ָ��
ori $15,$0,12 #���
if:
beq $11,$12,ADEL #ADEL
nop
beq $11,$13,ADES #ADES
nop
beq $11,$15,Ov #Ov
nop
beq $11,$14,RI
nop
RI:
mfc0 $10,$14 #10<=EPC
addi $10,$10,4 
mtc0 $10,$14 #��PC+4�浽EPC��
eret

Ov:
ori $4,$0,1
ori $5,$0,2
eret


ADES:
ori $3,$0,0  #��store��ַ�ĳ�0
eret
ADEL:
mfc0 $10,$14 #10<=EPC
slti $17,$10,0x3000 #EPC<3000
bne $17,$0,PCLESS
nop
ori $18,$0,0x4fff
slt $17,$18,$10 #EPC>4FFF
bne $17,$0,PCMORE
nop
ori $17,$0,0x0003
and $17,$17,$10
bne $17,$0,ALIGN
nop


LOADWORNG:
ori $2,$0,0
eret  #��load�ĵ�ַ�ĳ�0

ALIGN:
ori $10,$0,0x3040 #��PC��ַ�ĵ�3040
mtc0 $10,$14
eret

PCMORE:
ori $10,$0,0x302c   #PC����,��PC�ĳ�302c
mtc0 $10,$14
eret

PCLESS:#��PC��<3000
ori $10,$0,0x3010 #��PC�ĳ�3010
mtc0 $10,$14
eret



