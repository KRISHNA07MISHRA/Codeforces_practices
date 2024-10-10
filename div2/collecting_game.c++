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

long long solve(vector<long long>&first, long long b){

    sort(first.begin(),first.end());
    long long s = 0;
    long long e = INT_MAX;

    long long ans = s;
    while(s<=e){
        long long mid = s+(e-s)/2;
        long long req = 0;
        for(int i = 0; i<first.size(); i++){
            
            if(mid>first[i]){
                req += mid-first[i];
            }
        }
        if(b>=req){
           
            ans = mid;
            s = mid+1;
        }
        else{
            e = mid-1;
        }

    }
    return ans;

}

int main() {
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        long long a,b;
        cin >> a;
        cin>>b;
        vector<long long> first;
        //vector<long long> second;
        
        for (int j = 0; j < a; j++) {
            long long c;
            cin>>c;
            first.push_back(c);
        }
        
        cout<<solve(first,b)<<endl;

       
    }

    return 0;
}
