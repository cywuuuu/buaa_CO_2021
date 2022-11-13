#include <iostream>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int maze[8][8];
int vis[8][8]; 
int num = 0;
	int n, m;int x1,x2,y1,y2;int cnt = 0;
int dfs(int x, int y)
{
	vis[x][y] = 1;
	if( x <= 0 || x > n || y <= 0 || y > m || maze[x][y] ){
		vis[x][y] = 0;
		return 0;
	}
	
	
	if(x == x2 && y == y2) {
		cnt++;
		vis[x][y] = 0;
		return 1;
	}
	else {

		if(!vis[x+1][y])
		dfs(x+1, y);
		if(!vis[x][y+1])
		dfs(x, y+1);
		if(!vis[x-1][y])
		dfs(x-1, y);
		if(!vis[x][y-1])
		dfs(x, y-1);
		vis[x][y] = 0;
		return 1;
	}
}
int main(int argc, char** argv) {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
		for (int j = 1 ; j <= m; j++)
			scanf("%d", &maze[i][j]);
	scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
	dfs(x1, y1);
	printf("%d", cnt);
	return 0;
}
/*
4
5
0
0
1
0
0
1
0
0
0
1
1
0
1
0
1
1
0
0
0
0
1
1
4
5
*/
