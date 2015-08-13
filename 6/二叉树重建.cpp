/********************************************************************************** 
*  二叉树重建
*
* 输入一棵二叉树的先序遍历和中序遍历序列，输出它的后序遍历序列
*
* 样例输入: DBACEGF ABCDEFG
*		    BCAD CBAD
*
* 样例输出: ACBFGED
*		    CDAB    
**********************************************************************************/
#include<stdio.h>
#include<string.h>
const int MAXN = 30;

void build(int n, char* s1, char* s2, char* s) 
{
	if(n <= 0) 
		return;
	int p = strchr(s2, s1[0]) - s2;//找到根结点在中序遍历中的位置
	build(p, s1+1, s2, s);//递归构造左子树的后序遍历
	build(n-p-1, s1+p+1, s2+p+1, s+p);//递归构造右子树的后序遍历
	s[n-1] = s1[0];
}

int main() 
{
	char s1[MAXN], s2[MAXN], ans[MAXN];
	while(scanf("%s%s", s1, s2) == 2) 
	{
		int n = strlen(s1);
		build(n, s1, s2, ans);
		ans[n] = '\0';//别忘了加上字符串结束标志
		printf("%s\n", ans);
	}
	return 0;
}