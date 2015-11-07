/********************************************************************************** 
*  �鲢����
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
		int m = x + (y-x)/2;		//����
		int p = x, q = m, i = x;
		merge_sort(A, x, m, T);		
		merge_sort(A, m, y, T);		//�ݹ����
		while(p < m || q < y)
		{
			if(q >= y || (p < m && A[p] <= A[q]))
				T[i++] = A[p++];	//��������鸴�Ƶ���ʱ�ռ�
			else
				T[i++] = A[q++];		//���Ұ����鸴�Ƶ���ʱ�ռ�
		}
		for(i = x; i < y; i++) 
			A[i] = T[i];			//�Ӹ����ռ临�ƻ�A����
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
