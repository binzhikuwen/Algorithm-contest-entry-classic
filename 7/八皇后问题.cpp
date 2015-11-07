/********************************************************************************** 
*  八皇后问题
**********************************************************************************/
#include<stdio.h>
#define MAX 8
int C[MAX];
int tot;

void search(int cur) 
{
	if(cur == MAX) 
	{
		tot++;						//递归边界。只要走到了这里，所有皇后必然不冲突
	} else
	{
		for(int i = 0; i < n; i++)
		{
			int ok = 1;
			C[cur] = i;					//尝试把cur行的皇后放在第i列
			for(int j = 0; j < cur; j++)//检查是否和前面的皇后冲突
			{
				if(C[cur] == C[j] || cur-C[cur] == j-C[j] || cur+C[cur] == j+C[j]) 
				{
					ok = 0;
					break;
				}
			}
			if(ok) 
				search(cur+1);//如果合法，则继续递归
		}
	}
}

int vis[3][MAX];

void search1(int cur)
{

	if(cur == MAX)
	{
		tot++;
	} else
	{	
		for(i = 0; i < MAX; i++)
		{
			if(!vis[0][i] && !vis[1][cur+i] && !vis[2][cur-i+MAX])
			{	
				//利用二维数组直接判断,依次为列，主对角线，副对角线
				C[cur] = i;				//如果不用打印解，整个c数组都可以忽略
				vis[0][i] = vis[1][cur+i] = vis[2][cur-i+MAX] = 1;//修改全局变量
				search1(cur+1);
				vis[0][i] = vis[1][cur+i] = vis[2][cur-i+MAX] = 0;//切记，一定要改回来
			}
		}
	}
}


int main() 
{
	search(0);
	printf("%d\n", tot);
	return 0;
}
