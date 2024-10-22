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
 
int solve(vector<int>&arr, int b){
    vector<int> remain;
    sort(arr.begin(),arr.end());
    for(int i = 1; i<arr.size(); i++){
        int diff = arr[i]-arr[i-1]-1;
        remain.push_back(diff);
    }
    int last = b-arr[arr.size()-1]+(arr[0]-1);
    remain.push_back(last);
    sort(remain.begin(),remain.end());
    reverse(remain.begin(),remain.end());
 
    int val = 0;
    int start = 0;
    int i = 0;
    while(i<remain.size()){
        int temp = remain[i]-(2*start);
        if(temp>1){
            val += temp-1;
            start += 2;
        }
        else if(temp == 1){
            val++;
            start+=2;
        }
        else{
            break;
        }
        i++;
    }
    return b-val;
}
int main(){
    long long n;
    cin>>n;
    for(int i = 0;i<n; i++){
        int a,b;
        cin>>a;
        cin>>b;
        vector<int> arr1;
        
        for(int j = 0; j<b; j++){
            int c;
            cin>>c;
            arr1.push_back(c);
        }
       cout<<solve(arr1,a)<<endl;
    }
    
}