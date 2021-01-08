#include <iostream>
using namespace std;

int find_index (long int *A, int n, long int k)
{
    int p = 0, r = n-1;
    while (p <= r)
    {
        int q = (p+r)/2;

        if (A[q] == k){
            return q;
        }
        if (A[q] <= A[r])
        {
            if (k > A[q] && k <= A[r]){
                p = q+1;
            }else{
                r = q-1;
            }
        }
        else
        {
            if (k >= A[p] && k < A[q]){
                r = q-1;
            }else{
                p = q+1;
            }
        }
    }
    return -1;
}

int main()
{
    int t;
    cin >> t;

    for (int i = 0; i < t; i++)
    {
        int n;
        cin >> n;
        long int A[n];

        for (int j = 0; j < n; j++){
            cin>> A[j];
        }
        long int k;
        cin >> k;
        int index = find_index(A, n, k);
        cout << index << endl;
    }
    return 0;
}
