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
void insert_sort(int* a, int n)
{
	for (int i = 1; i <n; ++i)
	{
		int key;
		key = a[i];
		int j = i-1;
		while (j>=0 && a[j] > key)
		{
			a[j+1] = a[j];
			j--;
			//output(a, 10); 
		}
		a[j+1] = key;
	}
}

int main(int argc, char const *argv[])
{
	int a[MAXNUM] = {2,8,5,4,9,3,1,7,6,0};
	output(a, MAXNUM);
	insert_sort(a,MAXNUM);
	output(a, MAXNUM);
	return 0;
}