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

vector<long long> solve(vector<long long>&arr){
    unordered_map<long long,long long> mp;
    for(int i = 0; i<arr.size(); i++){
        mp[i] = arr[i];
    }
    vector<long long> temp = arr;
    sort(temp.begin(),temp.end());
    long long  prevsum = 0;
    
    unordered_map<long long,long long> result;
    int i = 0;
    int j = i+1;
    while(i<temp.size()-1){
        
        long long curr = prevsum + temp[i];
        
        while(curr>temp[j] && j<temp.size()){
            curr += temp[j];
            j++;
            
        }
        long long kri = i + (j-i)-1;
        result[temp[i]] = kri;
        prevsum += temp[i];
        i++;
        if(i == j){
            j++;
        }
    }
    result[temp[temp.size()-1]] = temp.size()-1;
    vector<long long> varsha;
    for(int i = 0; i<arr.size(); i++){
        varsha.push_back(result[mp[i]]);
    }
    return varsha;

}

int main() {
    long long n;
    cin>>n;
    for(int i = 0; i<n; i++){
        long long a,b;
        cin>>a;
        
        vector<long long> second;
       
        for(int j = 0; j<a; j++){
            long long c;
            cin>>c;
            second.push_back(c);
        }

        vector<long long> ans = solve(second);
        for(int i = 0; i<ans.size(); i++){
            cout<<ans[i]<<" ";
        }
        cout<<endl;
    }
}