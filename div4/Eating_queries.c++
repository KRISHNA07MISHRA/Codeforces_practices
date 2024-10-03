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

vector<long long>  solve(vector<long long>&temp, vector<long long>&queries){
    sort(temp.begin(),temp.end());
    reverse(temp.begin(),temp.end());

    unordered_map<long long,long long> mp;
    for(int i = 0; i<queries.size(); i++){
        mp[i] = queries[i];
    }
    sort(queries.begin(),queries.end());
    long long prev = 0;
    for(int i = 0; i<temp.size(); i++){
        prev += temp[i];
    }
    long long sum = 0;
    long long j = 0;
    unordered_map<long long,long long> relate;
    for(int i = 0; i<queries.size(); i++){
        long long val = queries[i];
        while(val>sum && j<temp.size()){
            sum += temp[j];
            j++;
        }
        if(val<=sum){
            relate[val] = j;
        }
        
    }
    vector<long long> result ;
    for(int i = 0; i<queries.size(); i++){
        long long index = mp[i];
        if(index>prev){
            result.push_back(-1);
        }
        else{
            result.push_back(relate[index]);
        }
        
    }
    return result;

}

int main() {
    long long t;
    cin >> t;
    
    for(int i = 0; i<t; i++){
        long long a,b;
        cin>>a;
        cin>>b;
        vector<long long> temp;
       
        for(int j = 0; j<a; j++){
            long long c;
            cin>>c;
            temp.push_back(c);
        }
        vector<long long> temp2;
        for(int j = 0; j<b; j++){
            long long c;
            cin>>c;
            temp2.push_back(c);
        }
        vector<long long> ans = solve(temp,temp2);
        for(int i = 0; i<ans.size(); i++){
            cout<<ans[i]<<endl;
        }
       
    }
}