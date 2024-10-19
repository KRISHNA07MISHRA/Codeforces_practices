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

string solve(string st1, string st2){
    int total = 0;
    for(int i = 0; i<st1.length(); i++){
        if(st1[i] == '0'){
            total++;
        }
    }
    int j = st1.length()-1;
    int flip = 0;
    while(j>=0){

        if((flip%2 == 0 && st1[j]!= st2[j]) || (flip%2 == 1 && st1[j]==st2[j])){
            int len = j+1;
            if(total != len-total){
                return "NO";
            }
            flip++;
        }
        // while(flip%2 == 0 && st1[j]!=st2[j]){
        //     if(st1[j] == '0'){
        //         total--;
        //     }
        //     j--;
        // }
        // while(flip%2 == 1 && st1[j] == st2[j]){
        //     if(st1[j] == '0'){
        //         total--;
        //     }
        //     j--;
        // }
        if(st1[j] == '0'){
            total--;
        }
        j--;



    }
    return "YES";
}
int main(){
    long long n;
    cin>>n;
    for(int i = 0; i<n; i++){
        long long a;
        cin>>a;
        string st1 = "";
        string st2 = "";
        for(int j = 0; j<a; j++){
            char ch ;
            cin>>ch;
            st1 += ch;
        }
        for(int j = 0; j<a; j++){
            char ch ;
            cin>>ch;
            st2 += ch;
        }
        cout<<solve(st1,st2)<<endl;
    }

    
}