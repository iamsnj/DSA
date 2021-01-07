#include <iostream>
#include <random>
#include <ctime>
using namespace std;

void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

int random_(int high)
{
	srand(time(0));
	int random_value = rand() % high;
	return random_value;
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

int randomised_partition(int *A, int p, int r)
{
	int k = random_(p, r);
	swap(A[k], A[r]);
	return partition(A, p, r);
}

void randomised_quick_sort(int *A, int p, int r)
{
	if(p < r)
	{
		int q = partition(A, p, r);
		randomised_quick_sort(A, p, q-1);
		randomised_quick_sort(A, q+1, r);
	}
}

int main()
{
	int n;
	cin>> n;
	int A[n];
	for(int i = 0; i < n; i++)
		cin>> A[i];
	randomised_quick_sort(A, 0, n-1);
	for(int i = 0; i < n; i++)
		cout<<A[i]<<" ";
	return 0;
}
