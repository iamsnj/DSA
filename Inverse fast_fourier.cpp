#include <iostream>     
#include <iomanip>
#include <complex>
#include <vector>
#include <cmath>
     
using namespace std; 

vector<complex<long double> >rec_FFT(vector<complex<long double> >A, int n)
{
    if(n == 1)
        return A;
    long double w_n_real, w_n_img, angle;
    angle = 2*M_PI/n;
    w_n_real = cos(angle);
    w_n_img = sin(angle);
    complex<long double>w_n(w_n_real, w_n_img); // exact w(n)
    complex<long double> w(1, 0);
    vector<complex<long double> > A_even;
    vector<complex<long double> > A_odd;
    for(int i = 0; i < n; i++)
    {
        if(i % 2 == 0)
            A_even.push_back(A[i]);
        else
            A_odd.push_back( A[i]);
    }
    vector<complex<long double> > y(n);
    vector<complex<long double> > y_even;
    vector<complex<long double> > y_odd;
    y_even = rec_FFT(A_even, n/2);
    y_odd = rec_FFT(A_odd, n/2);
    for(int k = 0; k < n/2; k++)
    {
        y[k] = (y_even[k] + w*y_odd[k]);
        y[k+n/2] = (y_even[k] - w*y_odd[k]);
        w = w*w_n;
    }
    return y;
}

vector<complex<long double> >rec_FFT_INV(vector<complex<long double> > A_INV, int n)
{
    if(n == 1)
        return A_INV;
    long double w_n_real, w_n_img, angle;
    angle = 2*M_PI/n;
    w_n_real = cos(angle);
    w_n_img = -sin(angle);
    complex<long double>w_n(w_n_real, w_n_img); // w(n)
    complex<long double> w(1, 0);
    vector<complex<long double> > A_INV_even;
    vector<complex<long double> > A_INV_odd;
    for(int i = 0; i < n; i++)
    {
        if(i % 2 == 0)
            A_INV_even.push_back(A_INV[i]);
        else
            A_INV_odd.push_back( A_INV[i]);
    }
    vector<complex<long double> > y_INV(n);
    vector<complex<long double> > y_INV_even;
    vector<complex<long double> > y_INV_odd;
    y_INV_even = rec_FFT_INV(A_INV_even, n/2);
    y_INV_odd = rec_FFT_INV(A_INV_odd, n/2);
    for(int k = 0; k < n/2; k++)
    {
        y_INV[k] = (y_INV_even[k] + w*y_INV_odd[k]);
        y_INV[k+n/2] = (y_INV_even[k] - w*y_INV_odd[k]);
        w = w*w_n;
    }
    return y_INV;
}

int main() 
{
    int t;
    cin>> t;
    for(int j = 0; j < t; j++)
    {
        int n;
        cin>> n;
        long long N = 1;
        vector<complex<long double> > com_vecA;
        vector<complex<long double> >com_vecB;
        long double a, b;
        for(int i = 0; i < n; i++)
        {
            
            cin>> a>> b;
            com_vecA.push_back({a, b});
        }
        for(int i = 0; i < n; i++)
        {
            cin>> a>> b;
            com_vecB.push_back({a, b});
        }
        while(N < 2*n)
            N = 2*N;
        for(int k = n; k < N; k++)
        {
            com_vecA.push_back({0,0});
            com_vecB.push_back({0,0});
        }
        vector<complex<long double> > fin_ansA;
        vector<complex<long double> >fin_ansB;
        fin_ansA = rec_FFT(com_vecA, N);
        fin_ansB = rec_FFT(com_vecB, N);
        vector<complex<long double> >product_vec(N);
        for(int i = 0; i < N; i++)
            product_vec[i] = fin_ansA[i]*fin_ansB[i];
        vector<complex<long double> >fin_poly;
        fin_poly = rec_FFT_INV(product_vec, N);
        for(int i = 0; i < N; i++)
            fin_poly[i] /= N;

        for(int i = 0; i < N; i++)
        {
            long double a = fin_poly[i].real();
            long double b = fin_poly[i].imag();
            if((int)(1000*a) == 0)
                a = 0.000;
            if((int)(1000*b) == 0)
                b = 0.000;
            // printf("(%.3lf,%.3lf)\n", a, b);
            cout<<fixed<<setprecision(3);
            cout << "(" << a << "," << b << ")" << endl;
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
1 0
4 0
3
2 0
4 0
3 0
3 0
1 0
7 0

Sample Output 0

(2.000,0.000)
(11.000,0.000)
(12.000,0.000)
(0.000,0.000)
(6.000,0.000)
(14.000,0.000)
(27.000,0.000)
(31.000,0.000)
(21.000,0.000)
(0.000,0.000)
(0.000,0.000)
(0.000,0.000)

*/
