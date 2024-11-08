#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <cmath>
#include <climits>  // For LLONG_MIN, LLONG_MAX
#include <queue>
#include <stack>
 
using namespace std;
 
const long long MOD = 1e9 + 7;
typedef long long ll; 
ll value(ll index, vector<ll>&arr, vector<ll>&brr,ll prev,vector<vector<ll>>&dp){
    if(index>=arr.size()){
        return 0;
    }
    if(dp[index][prev] != -1){
        return dp[index][prev];
    }
    ll nottake = value(index+1,arr,brr,prev,dp);
    ll take = 0;
 
    if(prev == 0 || prev == 1 ){
        take = brr[index] + value(index+1,arr,brr,2,dp);
    }
    if(prev == 0 || prev == 2){
        take = max(take,arr[index] + value(index+1,arr,brr,1,dp));
    }
 
    return dp[index][prev] = max(take,nottake);
}
ll solve(vector<ll>&arr,vector<ll>&brr){
    int n = brr.size();
    vector<vector<ll>> dp(n+1,vector<ll>(3,-1));
    return value(0,arr,brr,0,dp);
}
int main() {
    ll n;
    cin >> n;
    vector<ll> arr;
    vector<ll> brr;
 
    for(int i = 0; i<n; i++){
        ll a;
        cin>>a;
        arr.push_back(a);
    }
    for(int i = 0; i<n; i++){
        ll a;
        cin>>a;
        brr.push_back(a);
    }
 
    cout<<solve(arr,brr)<<endl;
    
   
 
}