#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <cmath>
#include <climits>  
#include <queue>
#include <stack>
 
using namespace std;
 
const long long MOD = 1e9 + 7;
typedef long long ll; 
ll solve(string st){
    ll total = 0;
    for(int i = 0; i<st.length(); i++){
        if(st[i] == '*'){
            total++;
        }
    }
    
    ll mid = 0;
    ll count = 0;
    for(int i = 0; i<st.length(); i++){
        if(st[i] == '*' && count == total/2){
            mid = i;
            break;
        }
        if(st[i] == '*'){
            count++;
        }
    }
    ll left = 0;
    ll target = mid-1;
    for(int i = mid-1; i>=0; i--){
        if(st[i] == '*'){
            left += target-i;
            target--;
        }
    }
    ll right = 0;
    ll target2 = mid+1;
    for(int i = mid+1; i<st.length(); i++){
        if(st[i] == '*'){
            right += i-target2;
            target2++;
        }
    }
    return left+right;
    
}
int main() {
    ll n;
    cin >> n;
    for(int i = 0; i<n; i++){
        ll a;
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