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
string solve(string st){
    char ch1 = 'a';
    char ch2 = 'b';
    char ch3 = 'c';
 
    string ans = "";
    ans += st[0];
    for(int i = 1; i<st.length()-1; i++){
        if(st[i] == st[i-1]){
            if(st[i] != ch1 && st[i-1] != ch1 && st[i+1] != ch1){
                st[i] = ch1;
            }
            else if(st[i] != ch2 && st[i-1] != ch2 && st[i+1] != ch2){
                st[i] = ch2;
            }
            else{
                st[i] = ch3;
            }
            
        }
       
    }
    int n = st.length();
    if(st[n-2] == st[n-1]){
        if(st[n-2] != ch1 && st[n-3] != ch1 ){
            st[n-2] = ch1;
        }
        else if(st[n-2] != ch2 && st[n-3] != ch2){
            st[n-2] = ch2;
        }
        else{
            st[n-2] = ch3;
        }
    }
    return st;
}
 
int main(){
    string st;
    cin>>st;
    cout<<solve(st)<<endl;
   
}