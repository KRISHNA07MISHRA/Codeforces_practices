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
vector<int> solve(vector<int>&arr){
    unordered_map<int,int> mp;
    for(int i = 0; i<arr.size(); i++){
        mp[arr[i]]++;
    }
 
    int l = -1;
    int r = -1;
    int s = 0;
    vector<int> index;
    for(int i = 0; i<arr.size(); i++){
        if(mp[arr[i]] == 1){
            index.push_back(i);
        }
    }
    if(index.size() == 0){
        return {0};
    }
    
    int len = INT_MIN;
    //int m = index.size();
    vector<bool> visited(arr.size(),false);
    for(int i = 0; i<index.size(); i++){
        int sindex = index[i];
        if(visited[sindex] == false){
            int j = sindex;
            while(j<arr.size() && mp[arr[j]] == 1){
                visited[j]= true;
                j++;
            }
 
            if(len<j-sindex){
                len = j-sindex;
                l = sindex+1;
                r = j;
                //cout<<l<<" "<<r<<" "<<endl;
            }
        }
    }
    
    return {l,r};
 
}
 
 
int main() {
    ll n;
    cin>>n;
    for(int i = 0; i<n; i++){
        int a;
        cin>>a;
        vector<int> arr;
        for(int j = 0; j<a; j++){
            int b;
            cin>>b;
            arr.push_back(b);
        }
        vector<int> ans = solve(arr);
        for(int j = 0; j<ans.size(); j++){
            cout<<ans[j]<<" ";
        }
        cout<<endl;
    }
 
}