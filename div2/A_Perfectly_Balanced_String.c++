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

string solve(string s){
    int i = 0;
    int j = 0;

    unordered_map<char,int> st;
    for(int k = 0; k < s.length(); k++){
        st[s[k]]++;
    }
    unordered_map<char,int> mp;
    while(j < s.length()){
        mp[s[j]]++;
        if(mp[s[j]] == 2){
            while(s[i] != s[j]){
                int val = mp[s[i]];
                if(abs((val-1) - mp[s[j]]) >= 2){
                    return "NO";
                }
                mp[s[i]]--;
                if(mp[s[i]] == 0){
                    mp.erase(s[i]);
                }
                i++;
            }
            unordered_map<char,int> temp;
            int l = i;
            int m = j;
            while(l != m){
                temp[s[l]]++;
                l++;
            }
            // Change here: No need to use abs() for size_t
            if(temp.size() > st.size() || st.size() - temp.size() >= 1){
                return "NO";
            }
            mp[s[j]]--;
            i++;
        }
        j++;
    }
    return "YES";
}

int main() {
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        string s;
        cin >> s;
        cout << solve(s) << endl;
    }
    return 0;
}
