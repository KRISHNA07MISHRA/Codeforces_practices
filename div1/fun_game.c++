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
 
string solve(string &st1, string &st2){
    if(st1[0] != st2[0] && st2[0]=='1'){
        return "NO";
    }
    bool flag = false;
    if(st1[0] == '1'){
        flag = true;
    }
    for(int i = 1; i<st1.length(); i++){
        if(st1[i] == '1'){
            flag = true;
        }
        if(st1[i] == '0' && st2[i] == '1' && flag == false){
            return "NO";
        }
    }
    
    return "YES";
}
 
int main() {
 
    long long n;
    cin>>n;
    
    for(int i = 0; i<n; i++){
        long long a;
        cin>>a;
        string st1 = "";
        string st2 = "";
        for(int j = 0; j<a; j++){
            char ch;
            cin>>ch;
            st1 += ch;
        }
        for(int j = 0; j<a; j++){
            char ch;
            cin>>ch;
            st2 += ch;
        }

        cout<<solve(st1,st2)<<endl;
    }
    
}