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
int solve(vector<int>&arr, vector<int>brr){
    // priority_queue<pair<int,pair<int,int>>> pq;
    // for(int i = 0; i<arr.size(); i++){
    //     int diff = brr[i]-arr[i];
    //     pq.push({diff,{arr[i],brr[i]}})
    // }
    vector<int> diff;
    for(int i = 0; i<arr.size(); i++){
        diff.push_back(brr[i]-arr[i]);
    }
    sort(diff.begin(),diff.end());
    reverse(diff.begin(),diff.end());
 
    int i = 0;
    int j = diff.size()-1;
    int count = 0;
    while(i<j){
        if(diff[i]+diff[j]>=0){
            i++;
            j--;
            count++;
        }
        else{
            j--;
        }
    }
    return count;
}
 
int main(){
    long long n;
    cin>>n;
    for(int i = 0;i<n; i++){
        int a;
        cin>>a;
        vector<int> arr1;
        vector<int> brr1;
        for(int j = 0; j<a; j++){
            int b;
            cin>>b;
            arr1.push_back(b);
        }
        for(int j = 0; j<a; j++){
            int b;
            cin>>b;
            brr1.push_back(b);
        }
 
        cout<<solve(arr1,brr1)<<endl;
    }
    
}