/********************************************************************************** 
* ������Ӵ�
*
*  ����һ���ַ���,���������Ļ����ִ�,���ж�ʱӦ�ú������б�������ո�,
*  �Һ��Դ�Сд,�������Ӧ�ñ���ԭ��.�����ַ����Ȳ�����5000,��ռ�ݵ���һ��.
*  Ӧ�������Ļ��Ĵ�,����ж��,�����ʼλ������.
*	
*	
*   ��������:Confuciuss say��Madam��I��m Adam.
*   �������:Madam��I��m Adam
*               
**********************************************************************************/
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define MAX 5000
char buf[MAX],s[MAX];
int p[MAX];
int main()
{
	int n,m=0,max=0,x,y;
	int i,j;
	fgets(buf,sizeof(buf),stdin);
	n = strlen(buf);
	for(i=0;i<n;i++)
	{
		if(isalpha(buf[i]))
		{
			p[m] = i;
			s[m++]=toupper(buf[i]);
		}
	}
	for(i=0;i<m;i++)
	{
		for(j=0;i-j>=0 && i+j<m;j++)
		{
			if(s[i-j] != s[i+j] )
				break;
			if(j*2+1 > max)
			{
				max = j*2+1;
				x = p[i-j];
				y = p[i+j];
			}
		}
		for(j=0;i-j>=0 && i+j+1<m;j++)
		{
			if(s[i-j] != s[i+j+1])
				break;
			if(j*2+2>max)
			{
				max = j*2+2;
				x = p[i-j];
				y = p[i+j+1];
			}
		}
	}
	for(i = x; i <= y; i++)
		printf("%c", buf[i]);
	printf("\n");
	return 0;
}
