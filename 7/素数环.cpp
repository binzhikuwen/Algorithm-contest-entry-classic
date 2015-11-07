/********************************************************************************** 
*  素数环
*  输入正整数n，把整数1,2,3,...,n组成一个环，使得相邻两个整数之和均为素数。输出时从
*  整数1开始逆时针排列。同一个环应恰好输出一次。n<=16;
*
* 样例输入: 6
*		    
*
* 样例输出: 1 4 3 2 5 6
*		    1 6 5 2 3 4
**********************************************************************************/

#include<cstdio>
#include<algorithm>
using namespace std;


#define MAX 1000
int n;
int A[MAX];
int isp[MAX];
int vis[MAX];

int is_prime(int x)
{
	for(int i = 2; i*i <= x; i++)
		if(x % i == 0) 
			return 0;
	return 1;
}


void dfs(int cur)
{
	if(cur == n && isp[A[0]+A[n-1]])	//递归边界。别忘了测试第一个数和最后一个数
	{
		for(int i = 0; i < n; i++) 		
			printf("%d ", A[i]);
		printf("\n");
	}
	else
	{
		for(int i = 2; i <= n; i++)		//尝试放置每个数i
		{
			if(!vis[i] && isp[i+A[cur-1]])//如果i没用用过，并且与前一个数之和为素数
			{
				A[cur] = i;
				vis[i] = 1;				  //设置使用标志
				dfs(cur+1);
				vis[i] = 0;				  //清除标志
			}
	}
}

int main()
{
	scanf("%d", &n);
	for(int i = 2; i <= n*2; i++)
		isp[i] = is_prime(i);
	memset(vis, 0, sizeof(vis));
	A[0] = 1;
	dfs(1);
	return 0;
}
