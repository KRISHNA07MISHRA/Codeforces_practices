#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <unordered_map>
 
#include <unordered_set>
#include <climits>
 
using namespace std;
 
// Macros for Competitive Programming
#define ll long long
#define pb push_back
#define mp make_pair
#define all(v) (v).begin(), (v).end()
#define sz(x) (int)(x).size()
#define F first
#define S second
 
// Constants
const int MOD = 1e9 + 7;
const ll INF = 1e18;
 
// Fast Input/Output
void fast_io() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
 
}
 
ll solve(vector<ll>&arr){
    ll n = arr.size();
    vector<ll> prefix(n);
    vector<ll> suffix(n);
    ll sum1 = 0;
    ll sum2 = 0;
 
    for(ll i = 0; i<arr.size(); i++){
        if(arr[i]>0){
            sum1 += arr[i];
        }
        prefix[i] = sum1;
    }
    for(ll i = n-1; i>=0; i--){
        if(arr[i]<0){
            sum2 += -arr[i];
        }
        suffix[i] = sum2;
    }
 
    ll maxi = INT_MIN;
    for(int i = 0; i<n; i++){
        //cout<<prefix[i]<<" ";
        maxi = max(maxi,prefix[i]+suffix[i]);
    }
    ////cout<<endl;
    for(int i = 0; i<n; i++){
        //cout<<suffix[i]<<" ";
        //maxi = max(maxi,prefix[i]+suffix[i]);
    }
    //cout<<endl;
 
    return maxi;
 
}
 
 
int main() {
    ll n;
    cin>>n;
    for(int i = 0; i<n; i++){
        ll a;
        cin>>a;
        vector<ll> arr;
        for(int j = 0; j<a; j++){
            ll b;
            cin>>b;
            arr.push_back(b);
        }
        cout<<solve(arr)<<endl;
    }
 
}