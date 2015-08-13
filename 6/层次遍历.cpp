/********************************************************************************** 
*  层次遍历
*
* 输入一棵二叉树，你的任务是按从上到下，从左到右的顺序输出各个结点的值。每个结点都
* 按照从根节点到它的移动序列给出(L表示左，R表示右)。在输入中，每个结点的左括号和右
* 括号之间没有空格，相邻结点之间用一个空格隔开。每棵树的输入用一对空括号()结束。
* 
* 注意，如果从根到某个叶结点的路径上有的结点没有在输入中给出，或者给出了超过一次，
* 应当输出-1，结点个数不超过256.
* 样例输入:(11,LL) (7,LLL) (8,R) (5,) (4,L) (13,RL) (2,LLR) (1,RRR) (4,RR) ()
*		    (3,L) (4,R) ()
*
* 样例输出:5 4 8 11 13 4 7 2 11
*		   -1          
**********************************************************************************/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
const int MAXN = 256;

typedef struct TNode
{
	int have_value;//是否被赋值过
	int v;//结点值
	struct TNode* left, *right;
} Node;

Node* root;//二叉树的根结点

Node* newnode()
{
	Node* u = (Node*) malloc(sizeof(Node));
	if(u != NULL)
	{
		u->have_value = 0;//显式初始化为0
		u->left = u->right = NULL;
	}
	return u;
}

int failed;
void addnode(int v, char* s)
{
	int n = strlen(s);
	Node* u = root;//根节点开始往下走
	for(int i = 0; i < n; i++)
		if(s[i] == 'L')
		{
			if(u->left == NULL)//结点不存在，建立新的结点
				u->left = newnode();
			u = u->left;//往左走
		} else if(s[i] == 'R')
		{
			if(u->right == NULL) u->right = newnode();
			u = u->right;
		}
		if(u->have_value)//已经赋过值，表明输入有误
			failed = 1;
		u->v = v;
		u->have_value = 1;//标记
}

void remove_tree(Node* u) 
{
	if(u == NULL)
		return;
	remove_tree(u->left);
	remove_tree(u->right);
	free(u);
}

char s[MAXN + 10];//保存输入结点
int read_input()
{
	failed = 0;
	remove_tree(root);
	root = newnode();//创建根结点
	for(;;) 
	{
		if(scanf("%s", s) != 1) 
			return 0;//整个输入结束
		if(!strcmp(s, "()"))
			break;//读到结束位置，退出循环
		int v;
		sscanf(&s[1], "%d", &v);//读到结点值
		addnode(v, strchr(s, ',')+1);//查找逗号，然后插入结点
	}
	return 1;
}

int n = 0, ans[MAXN];
int bfs()
{
	int front = 0, rear = 1;
	Node* q[MAXN];
	q[0] = root;//初始化只有一个根结点
	while(front < rear) 
	{
		Node* u = q[front++];
		if(!u->have_value) 
			return 0;//有结点没有赋值过，表明输入有误
		ans[n++] = u->v;//增加到输出序列尾部
		if(u->left != NULL) 
			q[rear++] = u->left;//把左儿子放进队列
		if(u->right != NULL)
			q[rear++] = u->right;//把右儿子放进队列
	}
	return 1;
}

int main()
{
	while(read_input()) 
	{
		if(!bfs())
			failed = 1;
		if(failed)
			printf("-1\n");
		else 
		{
			for(int i = 0; i < n; i++)
				printf("%d ", ans[i]);
			printf("\n");
		}
	}
  return 0;
}
