#include<bits/stdc++.h>
using namespace std;
#include<iostream>

long long solve(long long val, long long n, long long mod){
    long long res = 1;

    while(n){
        if(n&1) res = (res * val)%mod;
        val = (val*val)%mod;
        n>>=1;
    }
    return res;
}
int main(){
    int n;
    cin>>n;
    cout<<solve(2,n,1000000007)<<endl;
}