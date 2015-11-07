/********************************************************************************** 
*  ���������
*  ����һ������Ϊn������A1��A2��...,An,����������͡����仰˵��Ҫ���ҵ�1<=i<=j<=n,
*  ʹ��Ai+(Ai+1)+...+Aj
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
		return A[x];			//ֻ��һ��Ԫ��,ֱ�ӷ���
	m = x + (y-x)/2;			//���ε�һ��:����[x,m)��[m,y)
	maxL = maxsum(A, x, m);
	maxR = maxsum(A, m, y);
	max  = maxL>maxR?maxL:maxR; //���εڶ���:�ݹ����
	
	v = 0; L = A[m-1];
	for(i = m-1; i >= x; i--) 
	{
		v += A[i];
		if(v > L) L = v;
	}							//���ε�����:�ϲ�(1)----�ӷֽ�㿪ʼ��������������L
				
	v = 0; R = A[m];
	for(i = m; i < y; i++)
	{
		v += A[i];
		if(v > R) R = v;
	}							//���ε�����:�ϲ�(2)----�ӷֽ�㿪ʼ���ҵ����������R
	
	return max>(L+R)?max:(L+R);//��������Ľ���L��R�Ƚ�
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
