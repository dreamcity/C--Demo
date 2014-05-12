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

void quick_sort(int* a, int low, int high)
{
	if (low<high)
	{
		int k = partition(a, low, high);
		quick_sort(a, low , k-1);
		quick_sort(a, k+1, high);
	}
}
int main(int argc, char const *argv[])
{
	int a[MAXNUM] = {2,8,5,4,9,3,1,7,6,0};
	output(a, MAXNUM);
	quick_sort(a,0,MAXNUM-1);
	output(a, MAXNUM);
	return 0;
}