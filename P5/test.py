# -*- coding = utf-8 -*-
# @Time : 2021-11-14 11:24
# @Author : cyw
# @File : test.py
# @Software : PyCharm
import os
os.system("java -jar mars.jar db a dump .text HexText code.txt basic.asm mc CompactDataAtZero ")
os.system("java -jar mars.jar db mips_code.asm nc mc CompactDataAtZero >std_ans.txt")
path = os.path.dirname(os.path.abspath(__file__))
str = ""
sub_str = "Verilog work "
for root, dirs, files in os.walk(path, topdown=False):
    for name in files:
        if name[-1] == 'v':
            str += "Verilog work "+'"'+os.path.join(root, name) + '"' +"\n"

with open("mips.prj", "w+") as f1:
    f1.write(str)
with open("mips.tcl", "w+") as f2:
    strr = "run 16us;\n" \
           "exit"
    f2.write(strr)
f1.close()
f2.close()
xilinx_path = "D:\\XilinxISE\\14.7\\ISE_DS\\ISE"
os.environ['XILINX'] = xilinx_path
os.system(xilinx_path + '\\bin\\nt64\\fuse -nodebug -prj mips.prj -o mips.exe tb>log.txt')
os.system('mips.exe -nolog -tclbatch mips.tcl> test_ans.txt')
