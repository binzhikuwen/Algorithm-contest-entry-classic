/********************************************************************************** 
* 因子与阶乘
*
* 输入正整数n(2<=n<=100),把阶乘n！=1*2*3*..*n分解成素因子相乘的形式，从小到大输出各个
* 素数(2,3,5，...)的指数。例如825=3*5^2*11应表示成(0,1,2,0,1),表示分别有0,1,2,0,1个
* 2,3,5,7,11。你的程序应忽略比最大素因子更大的素数(否则末尾会有无穷多个0)。、
* 样例输入:5
*		   53
* 样例输出:5! = 3 1 1
*   	   53! = 49 23 12 8 4 4 3 2 2 1 1 1 1 1 1 1	            
**********************************************************************************/

#include <stdio.h>
#include <string.h>
int is_prime(int n)
{
	for (int i=2;i*i<=n;i++)
	{
		if(n%i==0)
		{
			return 0;
		}
	}
	return 1;
}

int prime[100],count;

int main()
{
	int n;
	int p[100];
	//构造素数表
	for(int i=2;i<=100;i++)
	{
		if(is_prime(i))
		{
			prime[count++]=i;
		}
	}
	while(scanf("%d", &n)==1)
	{
		printf("%d! =", n);
		memset(p,0,sizeof(p));
		int maxp = 0;
		for(int i=1;i<=n;i++)
		{
			int m = i;
			//必须将i复制到m中，而不要在做除法时直接修改它
			for(int j=0;j<count;j++)
			{
				while( m%prime[j] == 0)//反复除以prime[j]，并累加p[j]
				{
					m/=prime[j];
					p[j]++;
					if(j>maxp)
					{
						maxp = j;//更新最大素因子下表
					}
				}
			}
			
		}
		for(int i=0;i<=maxp;i++)
		{
			printf(" %d",p[i]);
		}
		printf("\n");

	}
	return 0;
}