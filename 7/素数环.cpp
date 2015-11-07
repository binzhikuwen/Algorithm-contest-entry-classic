/********************************************************************************** 
*  ������
*  ����������n��������1,2,3,...,n���һ������ʹ��������������֮�;�Ϊ���������ʱ��
*  ����1��ʼ��ʱ�����С�ͬһ����Ӧǡ�����һ�Ρ�n<=16;
*
* ��������: 6
*		    
*
* �������: 1 4 3 2 5 6
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
	if(cur == n && isp[A[0]+A[n-1]])	//�ݹ�߽硣�����˲��Ե�һ���������һ����
	{
		for(int i = 0; i < n; i++) 		
			printf("%d ", A[i]);
		printf("\n");
	}
	else
	{
		for(int i = 2; i <= n; i++)		//���Է���ÿ����i
		{
			if(!vis[i] && isp[i+A[cur-1]])//���iû���ù���������ǰһ����֮��Ϊ����
			{
				A[cur] = i;
				vis[i] = 1;				  //����ʹ�ñ�־
				dfs(cur+1);
				vis[i] = 0;				  //�����־
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
