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
int solve(string &st){
    int count = 0;
    int i = 0;
    while(i<st.length() && st[i] == '0'){
        i++;
    }
 
    if(i>=st.length()){
        return 0;
    }
    int j = i;
    while(j<st.length()){
        while(j<st.length() && st[j] == st[i]){
            j++;
        }
        count++;
        i = j;
    }
    return count;
}
 
 
int main() {
    ll n;
    cin>>n;
    for(int i = 0; i<n; i++){
        int a;
        cin>>a;
        string st = "";
        for(int j = 0; j<a; j++){
            char ch;
            cin>>ch;
            st += ch;
        }
        cout<<solve(st)<<endl;
    }
 
}
 