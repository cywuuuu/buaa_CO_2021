import os
os.chdir(r"C:\Users\11069\Documents\program\P7")
for i in range(0,5):
    ## dump text
    print("dump%d"%i)
    os.system(r"java -jar F:\Mars_perfect.jar nc a db mc  CompactDataAtZero dump 0x00003000-0x0000417c HexText C:\Users\11069\Documents\program\P7\text.txt C:\Users\11069\Documents\program\P7\testpoint\wzm\testdata%d\testdata%d.asm"%(i,i))
    ## dump ktext
    os.system(r"java -jar F:\Mars_perfect.jar nc a db mc  CompactDataAtZero dump 0x00004180-0x00004f00 HexText C:\Users\11069\Documents\program\P7\ktext.txt C:\Users\11069\Documents\program\P7\testpoint\wzm\testdata%d\testdata%d.asm"%(i,i))
    with open(r"text.txt","r") as textfile:
        with open(r"ktext.txt","r") as ktextfile:
            with open(r"C:\Users\11069\Documents\program\P7\testpoint\wzm\testdata%d\code.txt"%(i),"w") as codefile:
                for i in range(0x3000,0x4180,4) :
                    ret1 =textfile.readline()
                    if(ret1):
                        codefile.write(ret1)
                    else:
                        codefile.write("00000000\n")
                codefile.write(ktextfile.read())