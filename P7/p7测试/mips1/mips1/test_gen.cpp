#include <cstdio>
#include <algorithm>
#include <queue>
#include <map>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <set>
#include <unordered_map>
#include <vector>
#include <ctime>
#define maxn 2048
typedef long long ll;
using namespace std;
unsigned int grf[32];
int reg[] = {0, 1, 2, 3, 4, 5, 30, 31, 29};
int dm[4096];
#define R reg[rand() % 8]
#define I (rand() + rand())
#define B (rand() % 30)
void addu(int rs, int rt, int rd)
{
	printf("addu $%d,$%d,$%d\n", rd, rt, rs);
	if (rd)
		grf[rd] = grf[rs] + grf[rt];
}
void _and(int rs, int rt, int rd)
{
	printf("and $%d,$%d,$%d\n", rd, rt, rs);
	if (rd)
		grf[rd] = grf[rs] & grf[rt];
}
void subu(int rs, int rt, int rd)
{
	printf("subu $%d,$%d,$%d\n", rd, rt, rs);
	if (rd)
		grf[rd] = grf[rs] - grf[rt];
}
void sll(int rs, int rt, int rd)
{
	int s = rand()%31;
	printf("sll $%d,$%d,%d\n", rd, rt, s);
	if (rd)
		grf[rd] = grf[rt] << s;
}
void slt(int rs, int rt, int rd)
{
	printf("slt $%d,$%d,$%d\n", rd, rs, rt);
	if (rd)
		grf[rd] = (grf[rs] < grf[rt]);
}
void ori(int rs, int rt, int imm)
{
	printf("ori $%d,$%d,%d\n", rt, rs, imm);
	if (rt)
		grf[rt] = grf[rs] | imm;
}
void lui(int rs, int rt, int imm)
{
	printf("lui $%d,%d\n", rs, imm);
	if (rs)
		grf[rs] = 1u * imm << 16;
}
void addiu(int rs, int rt, int imm)
{
	imm = rand()%65535;
	printf("addiu $%d,$%d,%d\n", rs, rt, imm);
	if (rs)
		grf[rs] = grf[rt] + imm;
}
void lw(int rs, int rt)
{
	int imm = rand() % 31 * 4;
	printf("lw $%d,%d($0)\n", rt, imm);
	grf[rt] = dm[imm / 4];
}
void sw(int rs, int rt)
{
	int imm = rand() % 31 * 4;
	printf("sw $%d,%d($0)\n", rt, imm);
	dm[imm / 4] = grf[rt];
}
void lb(int rs, int rt)
{
	int imm = rand() % 127;
	printf("lb $%d,%d($0)\n", rt, imm);
	int byte = imm%4;
	int mask = 0;
	for(int i=8*byte;i<=7+8*byte;i++) mask |= (1<<i);
	grf[rt] = dm[imm / 4] & mask;
}
void sb(int rs, int rt)
{
	int imm = rand() % 127;
	printf("sb $%d,%d($0)\n", rt, imm);
}

int jump[1010];
void beq(int rs, int rt, int k)
{
	int jaddr = k + rand()%50+1;
	while (jump[jaddr]||jaddr>=maxn)
		jaddr = k + rand()%50+1;
	printf("beq $%d,$%d,label%d\n", rs, rt, jaddr);
}
void j(int k)
{
	int jaddr = k + rand()%50+1;
	while (jump[jaddr]||jaddr>=maxn)
		jaddr = k + rand()%50+1;
	printf("j label%d\n", jaddr);
}
void jal(int k)
{
	int jaddr = k + rand()%50+1;
	while (jump[jaddr]||jaddr>=maxn)
		jaddr = k + rand()%50+1;
	printf("jal label%d\n", jaddr);
}
void jalr(int rd, int rs)
{
	printf("jalr $%d, $%d\n", rd, rs);
}
int jr(int rs, int rt, int k)
{
	int i;
	vector<int> can;
	can.clear();
	for (i = 0; i < 10; i++)
		if (reg[i] > (0x3000+(k<<2)) && reg[i] < 0x3000+((k+50)<<2) && reg[i] < 0x3000+(maxn<<2))
			can.push_back(reg[i]);
	if (can.size() == 0)
	{
		beq(rs, rt, k);
		return 0;
	}
	rs = can[rand() % can.size()];
	printf("jr $%d\n", rs);
	return 1;
}
void nop()
{
	printf("nop\n");
}
int main()
{
	int i;
	srand(time(NULL));
	freopen("test.asm", "w", stdout);
	printf("subu $31,$31,$31\n"); //���$sp
	int last = -1;
	int cnt = 0;
	for (i = 0; i < maxn; i++) {
		if(cnt==0){
			cnt++;
			printf("label%d: ", i);
			int instr = rand() % 16;
			while ((i < 90 || last == 1) && instr >= 6 && instr <= 9)
			{ //j+j
				instr = rand() % 17;
			}
			int rs = R, rt = R, rd = R, imm = I;
			if (instr == 0)
				addu(rs, rt, rd);
			else if (instr == 1)
				subu(rs, rt, rd);
			else if (instr == 2)
				ori(rs, rt, imm);
			else if (instr == 3)
				lui(rs, 0, imm);
			else if (instr == 4)
				lw(rs, rt);
			else if (instr == 5)
				sw(rs, rt);
			else if (instr == 6)
				beq(rs, rt, i);
			else if (instr == 7)
				j(i);
			else if (instr == 8)
				jal(i);
			//else if (instr == 14)
			//	_and(rs, rt, rd);
			else if (instr == 10)
				sll(rs, rt, rd);
			//else if (instr == 11)
			//	slt(rs, rt, rd);
			else if (instr == 12||instr == 14||instr>=15)
				lb(rs, rt);
			else if (instr == 13||instr==11||instr>=15)
				sb(rs, rt);
			//else if (instr == 15)
			//	jalr(rd, rs);
			else if (instr == 9)
			{
				int yes = jr(rs, rt, i);
				if (!yes)
					instr = 6; //beq
			}
			else
				nop();
			jump[i] = last = (instr >= 6 && instr <= 9);
		}
		else {
			printf("label%d: ", i);
			nop();
			cnt = (cnt+1)%5;
		}
	}
	//printf("label:\n beq $0,$0,label");
	return 0;
}
