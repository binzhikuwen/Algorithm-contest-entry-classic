/********************************************************************************** 
*  数字三角形
*  有一个由非负整数组成的三角形，第一行只有一个数，除了最下行之外每个数的左下方和右
*  下方各有一个数。从第一行的数开始，每次可以往左下或右下走一格，直到走到最下行，把
*  沿途经过的数全部加起来。如何走才能使得这个和尽量大。
*
*  转态转移方程：   d(i,j) = a(i,j) + max{d(i+1,j),d(i+1,j+1)} 
**********************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<assert.h>
#define maxn 100
int n, a[maxn][maxn];
int d[maxn][maxn];

int f(int i, int j)
{
    if(d[i][j] >= 0)
		return d[i][j];
    return d[i][j] = a[i][j] + (i==n ? 0 : max(f(i+1, j+1), f(i+1, j)));
}
