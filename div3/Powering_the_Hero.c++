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
 
long long solve(vector<long long>&temp){
    long long sum = 0;
    priority_queue<long long> pq;
    for(int i= 0; i<temp.size(); i++){
        if(temp[i] == 0 && !pq.empty()){
            sum += pq.top();
            pq.pop();
        }
        pq.push(temp[i]);
    }
    return sum;

}
 
int main() {
 
    long long n;
    cin>>n;
    
    for(int i = 0; i<n; i++){
        long long a;
        cin>>a;
        // long long b;
        // cin>>b;
        vector<long long> temp;
        for(int j = 0; j<a; j++){
            long long c;
            cin>>c;
            temp.push_back(c);
        }

        cout<<solve(temp)<<endl;
    }
    
}