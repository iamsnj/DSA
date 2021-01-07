#include <iostream>
using namespace std;

void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

int partition(int *A, int p, int r)
{
	int pivot = A[r];
	int i = p-1;
	for(int j = p; j < r; j++)
	{
		if(A[j] <= pivot)
		{
			swap(A[j], A[i+1]);
			i++;
		}
	}
	swap(A[i+1], A[r]);
	return i+1;
}

void QuickSort(int *A, int p, int r)
{
	if(p < r)
	{
		int q = partition(A, p, r);
		QuickSort(A, p, q-1);
		QuickSort(A, q+1, r);
	}
}

int main()
{
	int n;
	cin>> n;
	int A[n];
	for(int i = 0; i < n; i++)
		cin>>A[i];
	QuickSort(A, 0, n-1);
	for(int i = 0; i < n; i++)
		cout<<A[i]<<" ";
}
