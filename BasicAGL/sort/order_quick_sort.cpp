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
int partition(int* a , int low , int high)
{
	int key = a[high];
	int i = low - 1;
	for (int j = low; j < high; ++j)
	{
		if (a[j]<=key)
		{
			i++;
			swap(a[i], a[j]);
		}
		
	}
	swap(a[i+1], a[high]);
	return i+1;
}

int order_quick_sort(int* a, int low, int high, int i)
{
	if (low == high)
	{
		return a[low];
	}
	int r = partition(a, low, high);
	int k;
	k= r - low +1;
	if (i == k)		
	{
		return a[r];
	}
	if (i<k)
	{
		return order_quick_sort(a, low, r-1, i);
	}
	else
		return order_quick_sort(a, r+1, high, i-k);
}
int main(int argc, char const *argv[])
{
	int a[MAXNUM] = {2,8,5,4,9,3,1,7,6,0};
	output(a, MAXNUM);
	int m = order_quick_sort(a,0,MAXNUM-1,5);
	//output(a, MAXNUM);
	cout<<"m:"<<m<<endl;
	return 0;
}