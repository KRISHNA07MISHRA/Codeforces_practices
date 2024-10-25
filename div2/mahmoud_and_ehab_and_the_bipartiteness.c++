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
 
long long solve(vector<vector<long long>>&arr,long long n){
    unordered_map<long long,vector<long long>> adj;
    for(int i = 0; i<arr.size(); i++){
        long long u = arr[i][0];
        long long v = arr[i][1];
 
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<long long> color(n + 1, -1);  // -1 means unvisited
    queue<int> q;
    color[1] = 0;  // Assign the first node to set 0
    q.push(1);
 
    long long setA = 0, setB = 0; // To track sizes of the two sets
    setA++; // Since node 1 is in setA
 
    // BFS to divide nodes into two sets (bipartite)
    while (!q.empty()) {
        long long node = q.front();
        q.pop();
        
        for (auto neighbor : adj[node]) {
            if (color[neighbor] == -1) {
                color[neighbor] = 1 - color[node]; // Alternate between 0 and 1
                if (color[neighbor] == 0) {
                    setA++;
                } else {
                    setB++;
                }
                q.push(neighbor);
            }
        }
    }
    vector<long long> storetrue;
    vector<long long> storefalse;
    for(int i = 1; i<= arr.size()+1; i++){
        if(color[i] == 1){
            storetrue.push_back(i);
        }
        else{
            storefalse.push_back(i);
        }
    }
 
    long long ans = 0;
    for(int i = 0 ; i<storetrue.size(); i++){
        long long value = storetrue[i];
        long long size = adj[value].size();
 
        ans += (storefalse.size()-size);
    }
    return ans;
}
int main(){
    long long n;
    cin >> n;
 
    vector<vector<long long>> arr;
    for (int i = 0; i < n - 1; i++) {
        long long a, b;
        cin >> a >> b;
        arr.push_back({a, b});
    }
 
    cout << solve(arr, n) << endl;
 
    return 0;
}