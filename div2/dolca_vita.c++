#include <iostream>
#include <vector>      
#include <algorithm>   
#include <string>      
#include <map>         
#include <set>         
#include <queue>       
#include <stack>       
#include<set>
#include <cmath>       
#include <limits>
#include <limits.h>  
#include<unordered_set> 
#include <unordered_map> 
using namespace std;
 
long long solve(vector<long long>&arr, long long b){
    sort(arr.begin(),arr.end());
 
    long long total = 0;
    unordered_map<long long,long long> yahataksum;
    long long local_sum = 0;
    for(int i = 0; i<arr.size(); i++){
        yahataksum[i] = local_sum;
        local_sum += arr[i];
        
    }
 
    for(int i = 0; i<arr.size(); i++){
        long long value = arr[i];
        long long s = 1;
        long long e = b+1;
        long long maxi = 0;
        while(s<=e){
            long long mid = (s+e)/2;
            long long totalkarcha = (value+mid-1)+((mid-1)*(i))+yahataksum[i];
 
            if(totalkarcha<=b){
                maxi = max(maxi,mid);
                s = mid+1;
            }
            else{
                e = mid-1;
            }
        }
        total += maxi;
    }
    return total;
}
int main(){
    long long n;
    cin>>n;
    for(int i = 0;i<n; i++){
        long long a,b;
        cin>>a;
        cin>>b;
        vector<long long> arr1;
        
        for(int j = 0; j<a; j++){
            long long c;
            cin>>c;
            arr1.push_back(c);
        }
       cout<<solve(arr1,b)<<endl;
    }
    
}