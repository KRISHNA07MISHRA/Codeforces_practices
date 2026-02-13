#include <iostream>
#include <vector>      
#include <algorithm>   
#include <string>      
#include <map>         
#include <set>         
#include <queue>       
#include <stack>       
#include <cmath>       
#include <limits>
#include <limits.h>      
#include <unordered_map> 
using namespace std;



void solve(vector<int>&arr, vector<int>&brr, int n){
    long long target = (1LL*n*(n+1))/4;

    int i = n;
    while(i>=1){
        if(target-i>=0){
            arr.push_back(i);
            target -= i;
        }
        else{
            brr.push_back(i);

        }
        i--;
    }
    
}

int main(){

    int n;
    cin>>n;

    long long total = (1LL*n*(n+1))/2;
    if(total%2 == 1) cout<<"NO"<<endl;
    else{
        cout<<"YES"<<endl;
        vector<int> arr ;
        vector<int> brr;
        solve(arr,brr,n);
        cout<<arr.size()<<endl;
        for(int i = 0; i<arr.size(); i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
        cout<<brr.size()<<endl;
        for(int i = 0; i<brr.size(); i++){
            cout<<brr[i]<<" ";
        }
        cout<<endl;
    }

}