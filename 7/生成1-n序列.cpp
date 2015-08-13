/********************************************************************************** 
*  生成1-n序列
*
* 
*
* 样例输入: 3
*		    2
*
* 样例输出: 123 132 213 231 312 321
*		    12 21
**********************************************************************************/
#include<stdio>
#include<stdlib>
#define MAXN 50
///O(N!)
void print_permutation(int n, int A[], int cur)
{
	if(cur == n)//递归边界
	{
		for(int i=0; i<n; i++)
			printf("%d ",A[i]);
		printf('\n');
	}
	else
	{
		for(int i=1; i<=n; i++)//尝试在A[cur]中填各种整数i
		{
			int ok = 1;
			for (int j=0; j<cur; j++)
				if(A[j] == i)
				{
					ok = 0;//如果i已经在A[0]-A[cur-1]出现过，则不能再选
				}
			if(ok) 
			{
				A[cur] = i;
				print_permutation(n, A, cur+1);//递归
			}
		}
	}
}
int main()
{
	int n, A[MAXN];
	scanf("%d",&n);
	print_permutation(n, A, 0);
	return 0;
}