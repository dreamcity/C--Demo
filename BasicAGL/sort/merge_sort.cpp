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
void merge(int* a, int low, int mid, int high)
{
	int b[MAXNUM]={0};
	int k = 0;
	int i= low, j=mid+1;
	while(i<=mid && j<=high)
	{
		if (a[i]<=a[j])
		{
			b[k] = a[i];
			i++;k++;
		}
		else
		{
			b[k] = a[j];
			j++;k++;
		}
	}
	while(i<=mid)
	{
		b[k] = a[i];
		i++;k++;
	}
	while(j<=high)
	{
		b[k] = a[j];
		j++;k++;
	}

	for (k=0,i = low; i <=high; ++k,++i)
	{
		a[i]=b[k];
	}
	//cout<<"a[high]"<<a[high]<<endl;
	//cout<<"high:"<<high<<endl;
}
void merge_sort(int* a, int low, int high )
{
	if (low<high)
	{
		int mid = (low + high)/2;
		// cout<<"mid:"<<mid<<endl;
		merge_sort(a, low, mid);
		merge_sort(a, mid+1, high);
		merge(a, low, mid, high);
	}
}
int main(int argc, char const *argv[])
{
	int a[MAXNUM] = {2,8,5,4,9,3,1,7,6,0};
	output(a, MAXNUM);
	merge_sort(a,0,MAXNUM-1);
	output(a, MAXNUM);
	return 0;
}