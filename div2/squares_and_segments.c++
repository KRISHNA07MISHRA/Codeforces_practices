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
bool check(long long a){
    long long val = sqrt(a);
    if(val*val == a){
        return true;
    }
    return false;
}
long long solve(long long a){
    if(check(a)){
        return sqrt(a)*2;
    }
   
    long long upper = sqrt(a)+1;

    long long lower = sqrt(a);
    if((upper*lower)>=a){
        return upper+lower;
    }
    return upper+lower+1;
}

int main() {
    long long t;
    cin >> t;
    
    cout<<solve(t)<<endl;
}