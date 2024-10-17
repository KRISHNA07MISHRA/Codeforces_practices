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

vector<pair<long long,long long>> solve(vector<long long>&arr){
    unordered_map<long long,long long> mp;
    for(int i = 0; i<arr.size(); i++){
        mp[i] = arr[i];
    }
    sort(arr.begin(),arr.end());
    long long i = 0;
    long long j = 1;
    while(mp[j] == mp[i]){
        j++;
    }
    if(j>=arr.size()){
        return {{-1,-1}};
    }
    
    vector<pair<long long,long long>> ans;

    while(j<arr.size()){
        while(mp[j] == mp[i]){
            j++;
        }
        if(j>=arr.size()){
            break;
        }
        
        while(i<j && mp[i]!= mp[j]){
            ans.push_back({i+1,j+1});
            i++;
        }
        if(j>=arr.size()){
            break;
        }
    }
    j--;
    while(j>0 && mp[j] == mp[j-1]){
        ans.push_back({j+1,i});
        j--;
    }
    return ans;

}


int main() {
    long long a;
    cin>>a;
    for(int i = 0; i<a; i++){
        long long b;
       
        cin>>b;
      
        vector<long long> temp;
        for(int j = 0; j<b; j++){
            long long d;
            cin>>d;
            temp.push_back(d);
        }
        vector<pair<long long,long long>> ans = solve(temp);
        if(ans[0].first == -1){
            cout<<"NO"<<endl;
        }
        else{
            cout<<"YES"<<endl;
            for(int i = 0; i<ans.size(); i++){
                cout<<ans[i].first<<" "<<ans[i].second<<endl;
            }
           
        }
    }
}