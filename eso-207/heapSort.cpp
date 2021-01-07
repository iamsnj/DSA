#include <iostream>
using namespace std;

struct heap
{
	int *A;
	int heapsize;
};

int left(int i)
{
	return 2*i+1;
}

int right(int i)
{
	return 2*i+2;
}

void max_heapify(heap *h, int i)
{
	int l = left(i);
	int r = right(i);
	int max_idx, flag = 0;
	if(l < h->heapsize)
	{	
		if(h->A[i] < h->A[l])
			max_idx = l;
		else
			max_idx = i;
		flag = 1;
	}
	
	if(r < h->heapsize)
	{
		if(h->A[i] < h->A[r] &&  h->A[r] > h->A[max_idx])
			max_idx = r;
		flag = 1;
	}
	if(max_idx != i && flag)
	{  
	    int temp = h->A[i];
	    h->A[i] = h->A[max_idx];
	    h->A[max_idx] = temp;
	    max_heapify(h, max_idx);
	}

}

void build_max_heap(heap *h)
{
	int n = h->heapsize;
	for(int i = n/2-1; i >= 0; i--)
		max_heapify(h, i);
}

void heapSort(heap *h)
{
	int n = h->heapsize;
	for(int i = n-1; i > 0; i--)
	{
		int temp = h->A[0];
		h->A[0] = h->A[i];
		h->A[i] = temp;
		h->heapsize --;
		max_heapify(h, 0);
	}
}

int main()
{
	int n;
	cin>> n;
	heap h;
	h.heapsize = n;
	h.A = (int*)malloc(h.heapsize*sizeof(int));
	for(int i = 0; i < h.heapsize; i++)
		cin>> h.A[i];
	build_max_heap(&h);
	heapSort(&h);
	for(int i = 0; i < n; i++)
		cout<<h.A[i]<<" ";
	return 0;
}