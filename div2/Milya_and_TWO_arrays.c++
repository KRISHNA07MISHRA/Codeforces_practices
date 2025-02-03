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
// ll solve(vector<ll>&arr,ll b){
//     int n = arr.size();
//     vector<int> last_vist(b+1,-1);
//     vector<int> first_max(b+1,0);
//     vector<int> second_max(b+1,0);
 
//     for(int i = 0; i<arr.size(); i++){
//         int last_visited = last_vist[arr[i]];
//         int duration = i-last_visited-1;
//         if(first_max[arr[i]]<duration){
//             second_max[arr[i]] = first_max[arr[i]];
//             first_max[arr[i]] = duration;
//         }
//         else if(second_max[arr[i]]<duration){
//             second_max[arr[i]] = duration;
//         }
//         last_vist[arr[i]] = i;
//     }
 
//     // last check
//     for(int i = 1; i<=b; i++){
//         int lastvisited = last_vist[i];
//         int duration = n-lastvisited-1;
//         if(first_max[i]<duration){
//             second_max[i] = first_max[i];
//             first_max[i] = duration;
//         }
//         else if(second_max[i]<duration){
//             second_max[i] = duration;
//         }
//     }
 
 
//     int ans = INT_MAX;
//     for(int i = 1; i<=b; i++){
//         ans = min(ans,max((first_max[i]+1)/2,second_max[i]));
//     }
//     return ans;
    
// }
string solve(vector<ll>&arr, vector<ll>&brr){
 
    unordered_map<ll, ll> mp1;
    unordered_map<ll,ll> mp2;
    for(int i = 0; i<arr.size(); i++){
        mp1[arr[i]]++;
    }
    for(int i = 0; i<brr.size(); i++){
        mp2[brr[i]]++;
    }
    if(mp1.size() == 1 && mp2.size()<=2){
        return "NO";
    }
    if(mp2.size() == 1 && mp1.size()<=2){
        return "NO";
    }
    return "YES";
}
int main() {
    ll n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        ll a;
        cin>>a;
        vector<ll> arr;
        vector<ll> brr;
        for(int j = 0; j<a; j++){
            ll b;
            cin>>b;
            arr.push_back(b);
        }
        for(int j = 0; j<a; j++){
            ll b;
            cin>>b;
            brr.push_back(b);
        }
        cout<<solve(arr,brr)<<endl;
 
    }
    
    
    
}