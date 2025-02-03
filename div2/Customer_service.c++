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
bool possible(vector<ll>&arr, int step){
    unordered_map<ll,ll> mp;
    ll start = step;
    for(int i = start; i<arr.size(); i+=(step+1)){
        mp[arr[i]]++;
    }
    if(mp.size()<=2){
        return true;
    }
    return false;
}
ll solve(vector<vector<ll>>&arr){
    int n  = arr.size();
 
    vector<ll> store(n);
 
    for(int row = 0; row<n; row++){
        ll countone = 0;
        for(int col = n-1; col>=0; col--){
            if(arr[row][col] != 1){
                break;
            }
            countone++;
        }
        store[row] = countone;
    }
 
    sort(store.begin(),store.end());
 
    ll s = 0;
//     for(int i = 0; i<store.size(); i++){
//         cout<<store[i]<<" ";
//     }
//     cout<<endl;
    unordered_set<ll> st;
    bool flag = false;
    for(int i = 1; i<store.size(); i++){
        // if(store[i] == 0 || st.find(store[i]) != st.end()){
        //     flag = true;
        // }
        // else if(store[i]>s){
        //     s++;
        // }
        // st.insert(store[i]);
 
        if(store[i]>s){
            s++;
        }
    }
    // s++;
    // if(flag == false){
    //     s--;
    // }
    
    return s+1;
}
 
int main() {
    ll n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        ll a;
        cin>>a;
        vector<vector<ll>> arr;
        for(int j = 0; j<a; j++){
            vector<ll> temp;
            for(int k = 0; k<a; k++){
                ll b;
                cin>>b;
                temp.push_back(b);
            }
            arr.push_back(temp);
        }
 
        cout<<solve(arr)<<endl;
    }
    
    
    
}