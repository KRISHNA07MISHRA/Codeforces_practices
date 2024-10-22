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
 
vector<long long> solve(vector<long long>&arr,long long n){
    unordered_map<long long,long long> mp;
    for(int i = 0; i<arr.size(); i++){
        mp[arr[i]]++;
    }
    vector<long long> ans;
    long long start = n-1;
    vector<long long> kri;
    for(auto temp:mp){
        kri.push_back(temp.first);
    }
    sort(kri.begin(),kri.end());
    for(auto temp:kri){
        long long val = temp;
        long long freq = mp[temp];
        //ans.push_back(val);
        while(freq>0 && start>0){
            ans.push_back(val);
            freq -= start;
            start--;
        }
    }
    ans.push_back(ans[(ans.size()-1)]);
    return ans;
 
}
int main(){
    long long n;
    cin>>n;
    for(int i = 0;i<n; i++){
        long long a;
        cin>>a;
        
        vector<long long> arr1;
        long long b = (a*(a-1))/2;
        for(int j = 0; j<b; j++){
            long long c;
            cin>>c;
            arr1.push_back(c);
        }
       vector<long long> ans = solve(arr1,a);
       for(int j = 0; j<ans.size(); j++){
            cout<<ans[j]<<" ";
       }
       cout<<endl;
    }
    
}