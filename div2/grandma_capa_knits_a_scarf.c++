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

long long solve(string st){
    
    char ch = 'a';
    int mini = INT_MAX;
    for(char i = ch; i<='z'; i++){
        
        int k = 0;
        int count = 0;
        int j = st.length()-1;
        while(k<j){
            while(st[k] == st[j]){
                k++;
                j--;
            }
            if(k>=j){
                break;
            }
            if(st[k] != st[j]){
                if(st[k] == i){
                    k++;
                    count++;
                }
                else if(st[j] == i){
                    j--;
                    count++;
                }
                else{
                    count = -1;
                    break;
                }
            }
        }
        if(count != -1){
            mini = min(mini,count);
        } 

    }
    return mini == INT_MAX?-1:mini;
}

int main(){
    long long n;
    cin>>n;
    for(int i = 0;i<n; i++){
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