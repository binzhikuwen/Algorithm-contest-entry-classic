/********************************************************************************** 
*  最大连续和
*  给出一个长度为n的序列A1，A2，...,An,求最大连续和。换句话说，要求找到1<=i<=j<=n,
*  使得Ai+(Ai+1)+...+Aj
*
**********************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<assert.h>
int A[100000], S[100000];

int maxsum(int* A, int x, int y)
{
	int i, m, v, L, R, max;
	int maxL,maxR;
	if(y - x == 1) 
		return A[x];			//只有一个元素,直接返回
	m = x + (y-x)/2;			//分治第一步:划分[x,m)和[m,y)
	maxL = maxsum(A, x, m);
	maxR = maxsum(A, m, y);
	max  = maxL>maxR?maxL:maxR; //分治第二步:递归求解
	
	v = 0; L = A[m-1];
	for(i = m-1; i >= x; i--) 
	{
		v += A[i];
		if(v > L) L = v;
	}							//分治第三步:合并(1)----从分界点开始往左的最大连续和L
				
	v = 0; R = A[m];
	for(i = m; i < y; i++)
	{
		v += A[i];
		if(v > R) R = v;
	}							//分治第三步:合并(2)----从分界点开始往右的最大连续和R
	
	return max>(L+R)?max:(L+R);//把子问题的解与L和R比较
}

int main() 
{
	int max;
	int n;
	scanf("%d", &n);
	srand(time(NULL));
	int i;
	bool flag;
	for(i = 0; i < n; i++)
	{
		flag = rand()%2;
		if(flag)
		{
			A[i] = rand();
		}else
		{
			A[i] = -rand();

		}
		
		printf("%d ",A[i]);
	}
	max = maxsum(A, 0, n);
	printf("\nmax = %d\n", max);
	return 0;
}
