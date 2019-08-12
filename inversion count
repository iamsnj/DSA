#include <iostream>
#include <climits>
using namespace std;

int merge_and_count_inv(int *A, int p, int q, int r)
{
    int L[q-p+1], R[r-q];
    for(int i = 0; i < q-p+1; i++)
        L[i] = A[i+p];
    for(int i = 0; i < r-q; i++)
        R[i] = A[i+q+1];
    L[q-p+1] = INT_MAX;
    R[r-q] = INT_MAX;
    int l = 0, r1 = 0, count_inv = 0;
    for(int i = p; i < r+1; i++)
    {
        if(L[l] <= R[r1])
        {
            A[i] = L[l];
            l++;
        }
        else
        {
            A[i] = R[r1];
            if(l < q-p+1 && r1 < r-q)
                count_inv += q-p+1-l;
            r1++;
        }
    }
    return count_inv;
}

int merge_sort_count_inv(int *A, int p, int r)
{
    int count_inv, l_count_inv, r_count_inv;
    if(p < r)
    {
        int q = (p+r)/2;
        l_count_inv = merge_sort_count_inv(A, p, q);
        r_count_inv = merge_sort_count_inv(A, q+1, r);
        count_inv = merge_and_count_inv(A, p, q, r);
        return l_count_inv+r_count_inv+count_inv;
    }
    else
        return 0;
}

int main()
{
    int n;
    cin>> n;
    int A[n];
    for(int i = 0; i < n; ++i)
        cin>> A[i];
    int inv = merge_sort_count_inv(A, 0, n-1);
    cout<<inv;
    return 0;
}
