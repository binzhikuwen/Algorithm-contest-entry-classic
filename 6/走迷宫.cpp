/**********************************************************************************
* 走迷宫
*
* 一个网格迷宫由n行m列的单元格组成，每个单元格要么是空地(用1来表示),要么是障碍物(用0
* 来表示)。你的任务是找一条从起点到终点的最短移动序列，其中UDLR分别表示往上、下、左、
* 右移动到相邻单元格。任何时候都不能在障碍格中，也不能走到迷宫之外。起点和终点保证是
* 空地。n，m<=100
*
**********************************************************************************/
#include<stdio.h>
#include<string.h>
#include <windows.h>
#define MAXN 105

int n, m, xs, ys, xt, yt;

int maze[MAXN][MAXN];
int vis[MAXN][MAXN];
int fa[MAXN][MAXN];
int dist[MAXN][MAXN];
int last_dir[MAXN][MAXN];
int num[MAXN][MAXN];

int dx[] = {-1,1,0,0};
int dy[] = {0,0,-1,1};
char name[] = "UDLR";

int q[MAXN*MAXN];

void bfs(int x, int y)
{
    int front=0,rear=0,d,u;
    u=x*m+y;    //编号    u的行号为u/m,列号为u%m.
    vis[x][y]=1;//访问过
    fa[x][y]=u;
    dist[x][y]=0;
    q[rear++]=u;
    while(front<rear)
    {
        u = q[front++];
        x = u/m;
        y = u%m;
        for(d=0;d<4;d++)
        {
            int nx=x+dx[d];
            int ny=y+dy[d];
            if(nx>=0&&nx<n &&ny>=0&&ny<m &&maze[nx][ny] && !vis[nx][ny])
            {
                int v = nx*m+ny;
                q[rear++]=v;
                vis[nx][ny]=1;
                fa[nx][ny]=u;//新格子的父亲结点编号
                dist[nx][ny]=dist[x][y]+1;//距离更新
                last_dir[nx][ny]=d;//父亲结点到它的移动方向
            }
        }
    }
}

void print_path(int x,int y)
{
    int fx=fa[x][y]/m;
    int fy=fa[x][y]%m;
    if(fx!=x || fy!=y)
    {
        print_path(fx,fy);
        printf("%c",name[last_dir[x][y]]);
    }
}

int dir[MAXN*MAXN];
void print_path2(int x, int y)
{
    int c = 0;
    for(;;)
    {
        int fx = fa[x][y]/m;
        int fy = fa[x][y]%m;
        if(fx == x && fy == y)
            break;
        dir[c++] = last_dir[x][y];
        x = fx;
        y = fy;
    }
    while(c--)
        printf("%c",name[dir[c]]);
}


int main()
{
    int i, j;
    FILE *fp;
    fp = fopen("maze.in","r+");
    if(fp==NULL)
    {
        system("pause");
        return 1;
    }
    fseek(fp,0,SEEK_SET);
    fscanf(fp,"%d%d%d%d%d%d", &n, &m, &xs, &ys, &xt, &yt);
    printf("%d %d %d %d %d %d\n",n, m, xs, ys, xt, yt);
    for(i = 0; i < n; i++)
        for(j = 0; j < m; j++)
            fscanf(fp,"%d", &maze[i][j]);
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < m; j++)
            printf("%d ", maze[i][j]);
        printf("\n");
    }
    memset(vis, 0, sizeof(vis));
    bfs(xs, ys);
    print_path(xt, yt);
    printf("\n");
    print_path2(xt, yt);
    printf("\n");
    system("pause");
    return 0;
}
