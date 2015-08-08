/********************************************************************************** 
* 蛇形填数 
*
* 在n*n方阵里填入1,2,3...，n*n，要求填成蛇形。例如n=4时方阵为：
*	10 11 12 1
*	9  16 13 2
*	8  15 14 3
*	7  6  5  4
* 上面的方阵中，多余的空格只是为了便于观察规律，不必严格输出。n<=8
* 
*               
**********************************************************************************/
#include <stdio.h>
#include <string.h>
#define MAX 20
int a[MAX][MAX];
int main()
{
	int n;
	int pot=1;
	int i=0,j;
	memset(a,0,sizeof(a));  
	scanf("%d", &n);
	j = n-1;
	a[i][j] = pot;
	while(pot<n*n)
	{
		while(i<n-1&&!a[i+1][j])
		{
			a[++i][j] = ++pot;
		}
		while(j>0&&!a[i][j-1])
		{
			a[i][--j] = ++pot;
		}
		while(i>0&&!a[i-1][j])
		{
			a[--i][j] = ++pot;
		}   
		while(j<n-1&&!a[i][j+1])
		{
			a[i][++j] = ++pot;
		}
	}
	for(int k=0;k<n;k++)
	{
		for(int l=0;l<n;l++)
		{
			printf("%4d ",a[k][l]);
		}
		printf("\n");
	}

	return 0;
}