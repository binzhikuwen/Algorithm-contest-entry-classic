/**********************************************************************************
* ���Թ�
*
* һ�������Թ���n��m�еĵ�Ԫ����ɣ�ÿ����Ԫ��Ҫô�ǿյ�(��1����ʾ),Ҫô���ϰ���(��0
* ����ʾ)�������������һ������㵽�յ������ƶ����У�����UDLR�ֱ��ʾ���ϡ��¡���
* ���ƶ������ڵ�Ԫ���κ�ʱ�򶼲������ϰ����У�Ҳ�����ߵ��Թ�֮�⡣�����յ㱣֤��
* �յء�n��m<=100
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
    u=x*m+y;    //���    u���к�Ϊu/m,�к�Ϊu%m.
    vis[x][y]=1;//���ʹ�
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
                fa[nx][ny]=u;//�¸��ӵĸ��׽����
                dist[nx][ny]=dist[x][y]+1;//�������
                last_dir[nx][ny]=d;//���׽�㵽�����ƶ�����
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
