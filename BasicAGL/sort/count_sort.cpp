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
void count_sort(int* a, int n, int k )
{
	int b[n] ;
	int c[k] ;
	for (int i = 0; i < k; ++i)
	{
		c[i] = 0;
	}
	for (int i = 0; i < n; ++i)
	{
		b[i] = 0;
	}
	//计数取值为a[i]的元素个数
	for (int i = 0; i < n; ++i)
	{
		c[a[i]] = c[a[i]] +1;
	}
	//output(c, k);
	//计数取值小于等于j的元素个数
	//
	for (int j = 1; j <k; ++j)
	{
		c[j] = c[j] + c[j-1];
	}
	// output(c, k);
	// cout<<"k:"<<k<<endl;
	// cout<<"n:"<<n<<endl;
	// output(a, n);
	// output(b, n);
	// output(a, k);
	//将a[i]输出在b[c[a[i]]]中
	for (int i=0; i<n ; i++)
	{
		b[c[a[i]]-1] =a[i];
		//output(b, n);
		c[a[i]] = c[a[i]] - 1;
		// output(b, n);
	}
	
	//output(b, n);
	for (int i = 0; i <n; ++i)
	{
		a[i]=b[i];
	}
}
int main(int argc, char const *argv[])
{
	int a[MAXNUM] = {2,3,7,4,1,3,1,7,6,0};
	output(a, MAXNUM);
	count_sort(a,MAXNUM,8);
	output(a, MAXNUM);
	return 0;
}