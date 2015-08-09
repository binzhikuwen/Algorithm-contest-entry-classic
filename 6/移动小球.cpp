/********************************************************************************** 
* 移动小球
*
* 你有一些小球，从左到右依次编号为1,2,3,4,...,n,
* 你可以执行两种指令。其中，A X Y表示把小球X移动到小球Y左边，B X Y表示把小球X移动到
* 小球Y右边。指令保证合法，即X不等于Y。
* 输入小球个数n，指令条数m和m条指令，从左到右输出最后的序列。注意，n可能高达500000，
  而m可能高达100000。
* 样例输入:6 2
*		   A 1 4
*		   B 3 5
* 样例输出:2 1 4 5 3 6          
**********************************************************************************/
#include<iostream>
#include<cstdio>
#include<cstdlib>
using std::cin;
using std::cout;
using std::endl;
const int maxn=500000 + 50; 
int left[maxn],right[maxn],n,t; 
void link(int a,int b)
{
	right[a]=b;
	left[b]=a;
}    
int main()
{
	cin >> n;
	for(int i=1;i<=n;i++) 
	{
		left[i]=i-1; right[i]=i+1;
	}
	right[n]=0;
	cin >> t;
	for(int i=1;i<=t;i++)
	{
		int X,Y;
		char c;
		c=getchar();
		while(c!='A'&&c!='B')
			c=getchar();
		cin >> X >> Y;
		link(left[X],right[X]);//第一步x的left和right相互连接
		if(c=='B')
		{
			//X .. Y-> .. Y X right[Y]
			link(X,right[Y]);//这一行和下一行不能搞反
			link(Y,X);             
		}
		else
		{//A
			//X .. Y -> .. X Y
			link(left[Y],X);//这一行和下一行不能搞反
			link(X,Y);
		}
	}
	int head;
	for(head=1;head<=n&&left[head]!=0;head++)
		;
	cout << head<<" ";
	while(right[head]!=0)
	{
		head=right[head];
		cout << head<<" ";
	}    
	cout << endl;
	return 0;
}