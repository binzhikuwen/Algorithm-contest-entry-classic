/********************************************************************************** 
* 字母重排
* 输入一个字典（用*****结尾），然后再输入若干单词。每输入一个单词w，你都需要在字典中
* 找出所有可以用w的字母重排后得到的单词，并按照字典序从小到大的顺序在一行中输出（如果
* 不存在，输出:(。输入单词之间用空格或空行隔开，且所有输入单词都由不超过6个小写字母
* 组成。注意，字典中的单词不一定按字典序排列。
* 样例输入:
* tarp given score refund only trap work earn courese pepper part ****
* 样例输出:
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
//字符比较函数
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
			break;//遇到结束标志就终止循环
		}
		n++;
	}
	qsort(word,n,sizeof(word[0]),cmp_str);//给所有单词排序
	for(int i=0;i<n;i++)
	{
		strncpy(sorted[i],word[i],sizeof(sorted[i]));
		qsort(sorted[i],strlen(sorted[i]),sizeof(char),cmp_char);//给每个单词排序
	}
	char s[10];
	while (scanf("%s",s)==1)
	{
		qsort(s,strlen(s),sizeof(char),cmp_char);//给输入单词排序
		int found = 0;
		for(int i=0;i<n;i++)
		{
			if(strcmp(sorted[i],s)==0)
			{
				found=1;
				printf("%s ",word[i]);//输出原始单词，而不是排序后的
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
