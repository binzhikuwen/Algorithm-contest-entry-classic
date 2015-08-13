/********************************************************************************** 
*  ����1-n����
*
* 
*
* ��������: 3
*		    2
*
* �������: 123 132 213 231 312 321
*		    12 21
**********************************************************************************/
#include<stdio>
#include<stdlib>
#define MAXN 50
///O(N!)
void print_permutation(int n, int A[], int cur)
{
	if(cur == n)//�ݹ�߽�
	{
		for(int i=0; i<n; i++)
			printf("%d ",A[i]);
		printf('\n');
	}
	else
	{
		for(int i=1; i<=n; i++)//������A[cur]�����������i
		{
			int ok = 1;
			for (int j=0; j<cur; j++)
				if(A[j] == i)
				{
					ok = 0;//���i�Ѿ���A[0]-A[cur-1]���ֹ���������ѡ
				}
			if(ok) 
			{
				A[cur] = i;
				print_permutation(n, A, cur+1);//�ݹ�
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