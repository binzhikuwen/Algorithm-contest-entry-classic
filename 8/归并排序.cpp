/********************************************************************************** 
*  归并排序
*
**********************************************************************************/
#include <stdio.h>
#include<stdlib.h>
#include<time.h>
#include<assert.h>
#define MAXN 1000000

int A[MAXN], T[MAXN];


void merge_sort(int* A, int x, int y, int* T)
{
	if(y-x > 1)
	{
		int m = x + (y-x)/2;		//划分
		int p = x, q = m, i = x;
		merge_sort(A, x, m, T);		
		merge_sort(A, m, y, T);		//递归求解
		while(p < m || q < y)
		{
			if(q >= y || (p < m && A[p] <= A[q]))
				T[i++] = A[p++];	//从左半数组复制到临时空间
			else
				T[i++] = A[q++];		//从右半数组复制到临时空间
		}
		for(i = x; i < y; i++) 
			A[i] = T[i];			//从辅助空间复制回A数组
	}
}


int main()
{
	int n;
	scanf("%d", &n);
	srand(time(NULL));
	int i;
	for(i = 0; i < n; i++)
	{
		A[i] = rand();	
		printf("%d ",A[i]);
	}
	merge_sort(A,0,n,T);
	printf("\n");
	for(i = 0; i < n; i++)
	{
		printf("%d ",A[i]);
	}
	return 0;
}
