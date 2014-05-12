#include "iostream"
using namespace std;
#ifndef MAXNUM
#define MAXNUM 10
#endif
void output(int* a, int n)
{
	cout<<"the output array:"<<endl;
	for (int i = 0; i < n; ++i)
	{		
		cout<<a[i];
	}
	cout<<endl;
}

void radix_sort(int* a, int n, int k, int r)
{
	//n为待排序元素个数
	//k为最大元素的长度，字位长度
	//r为每个数位的长度，采用2^r进制
	int b[n] ;
	int c[r] ;
	int t;
	int m = k/r;
	for (int i = 0; i < n; ++i)
	{
		b[i] = 0;
	}
	for (int i = 0, t=1; i < m; ++i, t*=2^r)
	{
		for (int j = 0; j < r; ++j)
		{
			c[j] = 0;
		}
		for (int j = 0; j < n; ++j)
		{
			c[(a[j]/t)%2^r]++;
		}
		for (int j = 1; j < r; ++j)
		{
			c[j] = c[j-1] + c[j];
		}
		for (int j = 0; j < n; ++j)
		{
			b[c[(a[j]/t)%2^r]] = a[j];
			c[(a[j]/t)%2^r]--;
		}
		for (int i = 0; i < n; ++i)
		{
			a[i] = b[i];
		}
	}

	// for (int i = 0; i < k; ++i)
	// {
	// 	c[i] = 0;
	// }

}
int main(int argc, char const *argv[])
{
	int a[MAXNUM] = {2,3,7,4,1,3,1,7,6,0};
	output(a, MAXNUM);
	radix_sort(a,MAXNUM,8,2);
	output(a, MAXNUM);
	return 0;
}