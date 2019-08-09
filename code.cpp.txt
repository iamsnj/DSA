#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int n;
	cin>>n;
	int arr[n];
	for(int x = 0; x < n; x++)
	    cin>> arr[x];
	int sum;
	sort(arr, arr+n);
	cin>>sum;
	int x = 0, j = 0, fr, bk, pair = 0;
	while(x+j < n-1)
	{
	    fr = arr[j];
	    bk = arr[n-1-x];
	    if(sum == fr+bk){
	        pair ++;
	        x++;
	        j++;
	    }
	    else if(sum < fr+bk)
	        x++;
	    else
	        j++;
	}
	cout<<pair;
	return 0;
}
