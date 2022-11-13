import os
import re
import random 

     
machine=[]
hex_to_bi={"0":"0000","1":"0001","2":"0010","3":"0011",
           "4":"0100","5":"0101","6":"0110","7":"0111",
           "8":"1000","9":"1001","a":"1010","b":"1011",
           "c":"1100","d":"1101","e":"1110","f":"1111"}
reg={"0":"$0",  "1":"$at", "2":"$v0", "3":"$v1",
     "4":"$a0", "5":"$a1", "6":"$a2", "7":"$a3",
     "8":"$t0", "9":"$t1", "10":"$t2", "11":"$t3",
     "12":"$t4", "13":"$t5", "14":"$t6", "15":"$t7",
     "16":"$s0", "17":"$s1", "18":"$s2", "19":"$s3",
     "20":"$s4", "21":"$s5", "22":"$s6", "23":"$s7",
     "24":"$t8", "25":"$t9", "26":"$k0", "27":"$k1",
     "28":"$gp", "29":"$sp", "30":"$fp", "31":"$ra"}
def bi_to_hex(a):
    bcode = ""
    for char in a:
        if not(char==" "):
            bcode += char
    return hex(int(str(int(bcode,2))))


def dasm(hexcode):
    out=["" for i in range(200)]
    labelcount=1
    label={}
    mipscount=0
    bicode=""
    for char in hexcode:
        if not(char==" "):
            bicode += char
        
    op=bicode[0:6]
    func=bicode[26:32]
    rs=reg[str(int(bicode[6:11],2))]
    rt=reg[str(int(bicode[11:16],2))]
    rd=reg[str(int(bicode[16:21],2))]
    shamt=bicode[21:26]
    imm=bi_to_hex(bicode[16:32])
    mips=""
    
    if op=='000000':
        itype="R"
    elif op=='000010' or op=='000011':
        itype="J"
    else:
        itype="I"
    
    if itype=="J":
        if op=='000010':
            mips="j "
        elif op=='000011':
            mips="jal "
        mips += imm
            
    elif itype=="R":
        if bicode=='00000000000000000000000000000000':
            mips="nop"
        elif func=='100000':
            mips="add "+rd+", "+rs+", "+rt
        elif func=='100001':
            mips="addu "+rd+", "+rs+", "+rt
        elif func=='100100':
            mips="and "+rd+", "+rs+", "+rt
        elif func=='001101':
            mips="break"
        elif func=='011010':
            mips="div "+rs+", "+rt
        elif func=='011011':
            mips="divu "+rs+", "+rt
        elif func=='001001':
            mips="jalr "+rd+", "+rs
        elif func=='001000':
            mips="jr "+rs
        elif func=='010000':
            mips="mfhi "+rd
        elif func=='010010':
            mips="mflo "+rd
        elif func=='010001':
            mips="mthi "+rd
        elif func=='010011':
            mips="mtlo "+rd
        elif func=='011000':
            mips="mult "+rs+", "+rt
        elif func=='011001':
            mips="multu "+rs+", "+rt
        elif func=='100111':
            mips="nor "+rd+", "+rs+", "+rt 
        elif func=='100101':
            mips="or "+rd+", "+rs+", "+rt 
        elif func=='000000':
            mips="sll "+rd+", "+rt+", "+shamt
        elif func=='000100':
            mips="sllv "+rd+", "+rt+", "+rs
        elif func=='101010':
            mips="slt "+rd+", "+rs+", "+rt
        elif func=='101011':
            mips="sltu "+rd+", "+rs+", "+rt
        elif func=='000011':
            mips="sra "+rd+", "+rt+", "+shamt
        elif func=='000111':
            mips="srav "+rd+", "+rt+", "+rs
        elif func=='000010':
            mips="srl "+rd+", "+rt+", "+shamt
        elif func=='000110':
            mips="srlv "+rd+", "+rt+", "+rs
        elif func=='100010':
            mips="sub "+rd+", "+rs+", "+rt
        elif func=='100011':
            mips="subu "+rd+", "+rs+", "+rt
        elif func=='001100':
            mips="syscall"
        elif func=='100110':
            mips="xor "+rd+", "+rs+", "+rt
    
    elif itype=="I":
        if op=='001000':
            mips="addi "+rt+", "+rs+", "+imm
        elif op=='001001':
            mips="addiu "+rt+", "+rs+", "+imm
        elif op=='001100':
            mips="andi "+rt+", "+rs+", "+imm
        elif op=='000100':
            mips="beq "+rs+", "+rt+", "+imm
        elif op=='000001' and bicode[11:16]=='00001':
            mips="bgez "+rs+", "+imm
        elif op=='000111':
            mips="bgtz "+rs+", "+imm
        elif op=='000110':
            mips="blez "+rs+", "+imm
        elif op=='000001' and bicode[11:16]=='00000':
            mips="bltz "+rs+", "+imm
        elif op=='000101':
            mips="bne "+rs+", "+rt+", "+imm
        elif op=='010000' and func=='011000':
            mips="eret"
        elif op=='100000':
            mips="lb "+rt+", "+imm+"("+rs+")"
        elif op=='100100':
            mips="lbu "+rt+", "+imm+"("+rs+")"
        elif op=='100001':
            mips="lh "+rt+", "+imm+"("+rs+")"
        elif op=='100101':
            mips="lhu "+rt+", "+imm+"("+rs+")"
        elif op=='001111':
            mips="lui "+rt+", "+imm
        elif op=='100011':
            mips="lw "+rt+", "+imm+"("+rs+")"
        elif op=='010000' and bicode[6:11]=='00000':
            mips="mfc0 "+rt+", "+rd
        elif op=='010000' and bicode[6:11]=='00100':
            mips="mtc0 "+rt+", "+rd
        elif op=='001101':
            mips="ori "+rt+", "+rs+", "+imm
        elif op=='101000':
            mips="sb "+rt+", "+imm+"("+rs+")"
        elif op=='101001':
            mips="sh "+rt+", "+imm+"("+rs+")"
        elif op=='001010':
            mips="slti "+rt+", "+rs+", "+imm
        elif op=='001011':
            mips="sltiu "+rt+", "+rs+", "+imm
        elif op=='101011':
            mips="sw "+rt+", "+imm+"("+rs+")"
        elif op=='001110':
            mips="xori "+rt+", "+rs+", "+imm
    out[mipscount] += mips
    mipscount += 1
    return out[0]


asmfilename="test.asm"
xlinx="D:\\PROGRAM\\14.7\\ISE_DS\\ISE" 
time="10us"
os.environ['XILINX']=xlinx
path=os.path.dirname(os.path.realpath(__file__))
os.chdir(path)
filelist=os.walk(path)
with open("mips.prj","w") as prj:
    for folder in filelist:
        for file in folder[2]:
            if(len(file.split("."))>1 and file.split(".")[1]=="v"):
                prj.write("verilog work \""+folder[0]+"\\"+file+"\"\n")
with open("mips.tcl","w") as tcl:
    tcl.write("run "+time+";\nexit;\n")

print("start running")
    #"java -jar Mars.jar test.asm nc mc CompactTextAtZero a dump .text HexText "+rom_name
    # problem: can not exit mars
os.system("java -jar Mars.jar db a nc mc CompactDataAtZero dump .text HexText data0.txt 1000000 "+asmfilename)
os.system("java -jar Mars.jar db nc mc CompactDataAtZero dump .text HexText data0.txt >out_std.txt 1000000 "+asmfilename)
print("std done")
os.system(xlinx+"\\bin\\nt64\\fuse "+"--nodebug  --prj mips.prj -o mips.exe mips_tb >log.txt")
os.system("mips.exe -nolog -tclbatch mips.tcl >out_source.txt")
print("source done")

process=0
with open("out_source.txt","r") as my:
    lines=my.readlines()
    if(len(lines)==0):
        print("fail to simulate")
        os._exit(1)
    if(lines[0][0]=='I'):
        process=1
n=0
while(1):
    if(lines[n][0]=="@"): 
        break
    else: 
        n=n+1
if(process):
    with open("out_source.txt","w") as my:
        my.writelines(lines[n:])
i=0
biao=0
instr = open("Instr.txt","r")
with open("out_source.txt","r") as source:
    with open("out_std.txt","r") as std:
        while(1):
            i+=1
            l1=source.readline().strip()
            l2=std.readline().strip()
            Instr = instr.readline().strip()
            asm = dasm(Instr)
            if((l1== "" or l1==None) and (l2=="" or l2==None)):
                break
            elif l1==l2:
                print("AC at line:%d "%(i)+"    source::"+l1+"  asm::"+asm)
            elif l1!=l2 and not "$ 0"in l2 and not "$ 0" in  l1:
                biao=1
                print("WA at line:%d "%(i)+"    source::"+l1+"  std::"+l2+" asm::"+asm)
                '''
                if l2=="" or l2 == None:
                    print("Wrong answer occur in line %d of code: "%(i)+"we got "+l1+" when we expected Nothing")
                else:
                    print("Wrong answer occur in line %d of code: "%(i)+"we got "+l1+" when we expected "+l2)
                '''
if biao==0:
    print("Accept on the point ")
else:
    os._exit(1)