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


long long gcd(long long a, long long b) {
    while (b) {
        a = a % b;
        swap(a, b);
    }
    return a;
}

long long solve(vector<long long>& arr) {
    long long n = arr.size();
    

    for (int i = 0; i < n - 1; i++) {
        if (arr[i] == arr[i + 1])
            return 0; 
    }

    long long ans = 0;
    
    
    for (int i = 0; i < n ; i += 2) {
        
        ans = gcd(ans,arr[i]);
    }
    bool flag = false;
    for(int i = 1; i<n; i+=2)
    {
        if(arr[i]%ans == 0){
            flag = true;
            break;
        }
    }
    if(flag == false){
        return ans;
    }

    long long result = 0;
    
    // Process elements at odd indices
    for (int i = 1; i < n ; i += 2) {
        
        result = gcd(result,arr[i]);
    }
    bool flag2 = false;
    for(int i = 0; i<n; i+=2){
        if(arr[i]%result == 0){
            flag2 = true;
        }
    }
    if(flag2 == false){
        return result;
    }
    return 0;

    
}

int main() {
    long long t;
    cin >> t;
    
    while (t--) {
        long long a;
        cin >> a;

        vector<long long> arr(a);
        for (int i = 0; i < a; i++) {
            cin >> arr[i];
        }

        cout << solve(arr) << endl;
    }

    return 0;
}
