/********************************************************************************** 
*  ��α���
*
* ����һ�ö���������������ǰ����ϵ��£������ҵ�˳�������������ֵ��ÿ����㶼
* ���մӸ��ڵ㵽�����ƶ����и���(L��ʾ��R��ʾ��)���������У�ÿ�����������ź���
* ����֮��û�пո����ڽ��֮����һ���ո������ÿ������������һ�Կ�����()������
* 
* ע�⣬����Ӹ���ĳ��Ҷ����·�����еĽ��û���������и��������߸����˳���һ�Σ�
* Ӧ�����-1��������������256.
* ��������:(11,LL) (7,LLL) (8,R) (5,) (4,L) (13,RL) (2,LLR) (1,RRR) (4,RR) ()
*		    (3,L) (4,R) ()
*
* �������:5 4 8 11 13 4 7 2 11
*		   -1          
**********************************************************************************/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
const int MAXN = 256;

typedef struct TNode
{
	int have_value;//�Ƿ񱻸�ֵ��
	int v;//���ֵ
	struct TNode* left, *right;
} Node;

Node* root;//�������ĸ����

Node* newnode()
{
	Node* u = (Node*) malloc(sizeof(Node));
	if(u != NULL)
	{
		u->have_value = 0;//��ʽ��ʼ��Ϊ0
		u->left = u->right = NULL;
	}
	return u;
}

int failed;
void addnode(int v, char* s)
{
	int n = strlen(s);
	Node* u = root;//���ڵ㿪ʼ������
	for(int i = 0; i < n; i++)
		if(s[i] == 'L')
		{
			if(u->left == NULL)//��㲻���ڣ������µĽ��
				u->left = newnode();
			u = u->left;//������
		} else if(s[i] == 'R')
		{
			if(u->right == NULL) u->right = newnode();
			u = u->right;
		}
		if(u->have_value)//�Ѿ�����ֵ��������������
			failed = 1;
		u->v = v;
		u->have_value = 1;//���
}

void remove_tree(Node* u) 
{
	if(u == NULL)
		return;
	remove_tree(u->left);
	remove_tree(u->right);
	free(u);
}

char s[MAXN + 10];//����������
int read_input()
{
	failed = 0;
	remove_tree(root);
	root = newnode();//���������
	for(;;) 
	{
		if(scanf("%s", s) != 1) 
			return 0;//�����������
		if(!strcmp(s, "()"))
			break;//��������λ�ã��˳�ѭ��
		int v;
		sscanf(&s[1], "%d", &v);//�������ֵ
		addnode(v, strchr(s, ',')+1);//���Ҷ��ţ�Ȼ�������
	}
	return 1;
}

int n = 0, ans[MAXN];
int bfs()
{
	int front = 0, rear = 1;
	Node* q[MAXN];
	q[0] = root;//��ʼ��ֻ��һ�������
	while(front < rear) 
	{
		Node* u = q[front++];
		if(!u->have_value) 
			return 0;//�н��û�и�ֵ����������������
		ans[n++] = u->v;//���ӵ��������β��
		if(u->left != NULL) 
			q[rear++] = u->left;//������ӷŽ�����
		if(u->right != NULL)
			q[rear++] = u->right;//���Ҷ��ӷŽ�����
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
