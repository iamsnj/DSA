#include <iostream>
#include <cmath>
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

int parent(int i)
{
	return (i-1)/2;
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

void increaseKey(heap *h, int i, int v)
{
	int j = i;
	h->A[i] += v;
	while(j > 0 && h->A[parent(j)] < h->A[j])
	{	
		int temp = h->A[parent(j)];
		h->A[parent(j)] = h->A[j];
		h->A[j] = temp;
		j = parent(j);
	} 
}

int main()
{
	int n, index, key;
	cin>> n;
	heap h;
	h.heapsize = n;
	h.A = (int*)malloc(h.heapsize*sizeof(int));
	for(int i = 0; i < h.heapsize; i++)
		cin>> h.A[i];
	cin>> index>> key;
	build_max_heap(&h);
	increaseKey(&h, index, key);
	for(int i = 0; i < h.heapsize; i++)
		cout<<h.A[i]<<" ";
	return 0;
}
