/********************************************************************************** 
* ��ĸ����
* ����һ���ֵ䣨��*****��β����Ȼ�����������ɵ��ʡ�ÿ����һ������w���㶼��Ҫ���ֵ���
* �ҳ����п�����w����ĸ���ź�õ��ĵ��ʣ��������ֵ����С�����˳����һ������������
* �����ڣ����:(�����뵥��֮���ÿո����и��������������뵥�ʶ��ɲ�����6��Сд��ĸ
* ��ɡ�ע�⣬�ֵ��еĵ��ʲ�һ�����ֵ������С�
* ��������:
* tarp given score refund only trap work earn courese pepper part ****
* �������:
* score
* refund
* part tarp trap
* :(
* courese
*               
**********************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char word[2000][10],sorted[2000][10];
//�ַ��ȽϺ���
int cmp_char(const void *_a, const void *_b)
{
	char *a = (char *)_a;
	char *b = (char *)_b;
	return *a - *b;
}
int cmp_str(const void *_a, const void *_b)
{
	char *a = (char *)_a;
	char *b = (char *)_b;
	return strcmp(a,b);
}
int main()
{
	int n=0;
	for(;;)
	{
		scanf("%s",word[n]);
		if(word[n][0]=='*')
		{
			break;//����������־����ֹѭ��
		}
		n++;
	}
	qsort(word,n,sizeof(word[0]),cmp_str);//�����е�������
	for(int i=0;i<n;i++)
	{
		strncpy(sorted[i],word[i],sizeof(sorted[i]));
		qsort(sorted[i],strlen(sorted[i]),sizeof(char),cmp_char);//��ÿ����������
	}
	char s[10];
	while (scanf("%s",s)==1)
	{
		qsort(s,strlen(s),sizeof(char),cmp_char);//�����뵥������
		int found = 0;
		for(int i=0;i<n;i++)
		{
			if(strcmp(sorted[i],s)==0)
			{
				found=1;
				printf("%s ",word[i]);//���ԭʼ���ʣ�������������
			}
		}
		if(!found)
		{
			printf(":(");
		}
		printf("\n");
	}
	return 0;
}
