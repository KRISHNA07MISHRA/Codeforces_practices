#include <iostream>
#include <vector>      
#include <algorithm>   
#include <string>      
#include <map>         
#include <set>         
#include <queue>       
#include <stack>       
#include <cmath>       
#include <limits>
#include <limits.h>      
#include <unordered_map> 
using namespace std;

string solve(string st){
    string ans = "";

    int totalpair = st.length()/2;
    int defactive = 0;
    int i = 0;
    int j = st.length()-1;
    while(i<j){
        if(st[i] != st[j]){
            defactive++;
        }
        i++;
        j--;
    }

    int maxione = (totalpair-defactive)*2;

    int k = 0;
    while(k<defactive){
        ans += '0';
        k++;
    }
    if(st.length()%2 == 1){
        while(k<=(st.length()-defactive)){
                ans += '1';
                k++;
        }
        while(k<=st.length()){
            ans += '0';
            k++;
        }
    }
    else{
        while(k<=(st.length()-defactive)){
                ans += '1';
                k++;
                if(k<=st.length()){
                    ans += '0';
                    k++;
                }
                else{
                    break;
                }
        }
        while(k<=st.length()){
            ans += '0';
            k++;
        }

    }
    return ans;
    

}

int main() {
    int t;
    cin >> t;
    
    for(int i = 0; i<t; i++){
        int a;
        cin>>a;
        string st = "";
        for(int j = 0; j<a; j++){
            char b;
            cin>>b;
            st += b;
        }
        cout<<solve(st)<<endl;
    }
}