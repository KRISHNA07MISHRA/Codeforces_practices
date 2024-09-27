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
 
 
 
// long long solve(int n, vector<long long>& a) {
//     if (n == 1 || n == 2) {
//         // Impossible to have more than half unhappy if n <= 2
//         return -1;
//     }
 
//     // Calculate the total wealth
//     double total_sum = 0;
//     for (int i = 0; i < n; ++i) {
//         total_sum += a[i];
//     }
 
//     // Sort the wealth array
//     sort(a.begin(), a.end());
 
//     double mid = a.size()/2;
//     double target = a[mid];
 
//     double abhi_kya_ha_averge = (total_sum/a.size())/2;
    
//     double safe = total_sum;
//     while(abhi_kya_ha_averge<=target){
//         total_sum++;
//         abhi_kya_ha_averge = (total_sum/a.size())/2;
//     }
 
//     return total_sum-safe;
// }
 
int solve(string &temp){
    stack<int> st;
    int i = 0;
    int sum = 0;
    while(i<temp.length()){
        if(temp[i] == '('){
            st.push(i);
        }
        else if(!st.empty() && temp[i] == ')' ){
            sum += abs(st.top()-i);
            st.pop();
        }
        else if(temp[i] == '_' && st.size() == 0){
            st.push(i);
        }
        else if (temp[i] == '_' && !st.empty()){
            sum += abs(st.top()-i);
            st.pop();
        }
        i++;
    }
    return sum;
}
int main() {
    // int t;
    // cin >> t;
    // while (t--) {
    //     int n;
    //     cin >> n;
    //     vector<long long> a(n);
 
    //     for (int i = 0; i < n; ++i) {
    //         cin >> a[i];
    //     }
 
    //     cout << solve(n, a) << endl;
    // }
    // return 0;
 
 
 
 
    int n;
    cin>>n;
    for(int i = 0; i<n; i++){
        int a;
        cin>>a;
        string st = "";
        for(int j = 0; j<a; j++){
            char ch ;
            cin>>ch;
            st += ch;
        }
 
        cout<<solve(st)<<endl;
    }
}