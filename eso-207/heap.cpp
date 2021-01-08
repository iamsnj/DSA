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

int parent(int i)
{
	return (i-1)/2;
}

void swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void heapifyUp(heap *h, int idx)
{
    while (idx > 0 && h->A[parent(idx)] < h->A[idx])
    {
        swap(&(h->A[idx]), &(h->A[parent(idx)]));
        idx = parent(idx);
    }
}

void heapifyDown(heap*h, int idx)
{
    int l = left(idx);
    int r = right(idx);
    int max_idx = idx;

    if (l < h->heapsize && h->A[l] > h->A[idx]){
        max_idx = l;
    }
    if (r < h->heapsize && h->A[r] > h->A[max_idx]){
        max_idx = r;
    }

    if (max_idx != idx)
    {
        swap(&(h->A[idx]), &(h->A[max_idx]));
        heapifyDown(h, max_idx);
    }
}

void insertKey(heap *h, int key)
{
    h->heapsize++;
    int n = h->heapsize;
    h->A = (int*)realloc(h->A, sizeof(int)*n); 
	h->A[n-1] = key;
    heapifyUp(h, n-1);
}

int getMax(heap* h)
{
    int n = h->heapsize;
    return h->A[0];
}

int extractMax(heap *h)
{
	int n = h->heapsize;
	int _max = h->A[0];
	h->A[0] = h->A[n-1];
    h->heapsize -= 1;
	heapifyDown(h, 0);
	return _max;
}

void buildHeap(heap *h)
{
    int n = h->heapsize;

    for (int i = (n-1)/2; i >= 0; i--){
        heapifyDown(h, i);
    }
}

void increaseKey(heap *h, int key, int idx)
{
    if (h->heapsize <= idx){
        cout << "idx should be less than heapsize.";
        return;
    }
    if (h->A[idx] >= key){
        cout << "Key should be greater than A[idx].";
        return;
    }
    h->A[idx] = key;
    heapifyUp(h, idx);
}

void deleteKey(heap *h, int idx)
{
    int n = h->heapsize;
    h->A[idx] = h->A[n-1];
    h->heapsize -= 1;
    heapifyDown(h, idx);
}

void heapSort(heap *h)
{
	int n = h->heapsize;
	for (int i = n-1; i > 0; i--)
	{
		swap(&(h->A[0]), &(h->A[i]));
		h->heapsize -= 1;
		heapifyDown(h, 0);
	}
}

int main()
{
    int n;
	cin >> n;
	heap h;
    /*
        if: insertKey is used, then 
        h.heapsize = 0;
        else if: build heap, then
        h.heapsize = n;

    */
	h.heapsize = 0;
	h.A = (int*)malloc(h.heapsize*sizeof(int));
	 
    return 0;
}
