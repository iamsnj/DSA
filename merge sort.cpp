#include <iostream>
using namespace std;

void merge(int *A, int p, int q, int r)
{
    int L[q-p+1], R[r-q];
    for(int l = 0; l < q-p+1; l++)
        L[l] = A[l+p];
    for(int i = 0; i < r-q; ++i)
        R[i] = A[i+q+1];
    L[q-p+1] = INT_MAX;
    R[r-q] = INT_MAX;
    int l = 0, r1 = 0;
    for(int i = p; i < r+1; ++i)
    {
        if(L[l] <= R[r1])
        {
            A[i] = L[l];
            l += 1;
        }
        else
        {
            A[i] = R[r1];
            r1 += 1;
        }
    }
}

void merge_sort(int *A, int p, int r)
{
    if(p < r)
    {
        int q = (p+r)/2;
        merge_sort(A, p, q);
        merge_sort(A, q+1, r);
        merge(A, p, q, r);
    }
}

int main()
{
    int n;
    cin>> n;
    int A[n];
    for(int i = 0; i < n; ++i)
        cin>> A[i];
    merge_sort(A, 0, n-1);
    for(int i = 0; i < n; ++i)
        cout<<A[i]<<" ";
    return 0;
}