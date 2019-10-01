#include <iostream>     
#include <iomanip>
#include <complex>
#include <vector>
#include <cmath>
     
using namespace std; 

vector<complex<double> >rec_FFT(vector<complex<double> >A, int n)
{
    if(n == 1)
        return A;
    vector<complex<double> > A_even;
    vector<complex<double> > A_odd;
    for(int i = 0; i < n; i++)
    {
        if(i % 2 == 0)
            A_even.push_back(A[i]);
        else
            A_odd.push_back( A[i]);
    }
    vector<complex<double> > y(n);
    vector<complex<double> > y_even;
    vector<complex<double> > y_odd;
    y_even = rec_FFT(A_even, n/2);
    y_odd = rec_FFT(A_odd, n/2);
    double w_n_real, w_n_img, angle;
    angle = 2*M_PI/n;
    w_n_real = cos(angle);
    w_n_img = sin(angle);
    complex<double>w_n(w_n_real, w_n_img); // exact w(n)
    complex<double> w(1, 0);
    for(int k = 0; k < n/2; k++)
    {
        y[k] = (y_even[k] + w*y_odd[k]);
        y[k+n/2] = (y_even[k] - w*y_odd[k]);
        w = w*w_n;
    }
    // complex<double> w1(1, 0);
    // for(int k = n/2; k < n; k++)
    // {
    //     y.push_back(y_even[k-n/2] - w1*y_odd[k-n/2]);
    //     w1 = w1*w_n;
    // }
    return y;
}

int main() 
{
    int t;
    cin>> t;
    for(int j = 0; j < t; j++)
    {
        int n;
        cin>> n;
        
        // if(n == 0)
        //     cout<<"(0.000,0.000)"<<endl;
        //else//(n > 0)
        {
            // int a, b, N = 1;
            long long N = 1;
            vector<complex<double> > com_vec;
            // complex<double> polynomial(a, b);
            for(int i = 0; i < n; i++)
            {
                double a, b;
                cin>> a>> b;
                // complex<double> polynomial(a, b);
                com_vec.push_back({a, b});
            }
            while(N < n)
                N = 2*N;
            if(N-n > 0)
            {
                complex<double> polynomial(0, 0);
                for(int k = n; k < N; k++)
                {
                    com_vec.push_back(polynomial);
                }
            }
            vector<complex<double> > fin_ans;
            fin_ans = rec_FFT(com_vec, N);
            for(int i = 0; i < N; i++)
              cout<<fixed<<setprecision(3)<<fin_ans[i]<<endl;
        }
    }
    return 0;
}

/*
Sample Input 0

2
2
2 0
3 0
3
2 0
4 0
3 0

Sample Output 0

(5.000,0.000)
(-1.000,0.000)
(9.000,0.000)
(-1.000,4.000)
(1.000,0.000)
(-1.000,-4.000)

*/
