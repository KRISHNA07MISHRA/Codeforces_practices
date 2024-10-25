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
#include <iomanip> // set precision
 
using namespace std;
 
double solve(vector<long long>&arr, long long b){
    long long  sum = 0;
    int i = 0;
    int j = 0;
    long long temp = 0;
    while(j<arr.size()){
        
        while(j-i<b && j<arr.size()){
            temp += arr[j];
            j++;
        }
 
 
        sum += temp;
        temp  -= arr[i];
        i++;
 
    }
    double value = (double)sum/(double)(arr.size()-b+1);
    return value;
}
 
int main(){
    long long n,a;
    cin>>n;
    cin>>a;
    vector<long long> arr;
    for(int i = 0; i<n; i++){
        long long b;
        cin>>b;
        arr.push_back(b);
    }
    cout << fixed << setprecision(6) << solve(arr, a) << endl;
}