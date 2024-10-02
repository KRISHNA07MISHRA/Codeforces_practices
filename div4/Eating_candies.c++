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
int solve(vector<int>&temp){
    int i = 0;
    int j = temp.size()-1;
    int leftsum = temp[0];
    int rightsum = temp[j];
    int maxi = 0;
 
    while(i<j){
        while(leftsum<rightsum&& i<j){
            i++;
            leftsum += temp[i];
            
        }
        while(rightsum<leftsum&& i<j){
            j--;
            rightsum += temp[j];
            
        }
        while(rightsum == leftsum&& i<j){
            int val = (i+1)+(temp.size()-j);
            maxi = max(maxi,val);
            i++;
            j--;
            leftsum += temp[i];
            rightsum += temp[j];
        }
 
    }
    return maxi;
}
 
int main() {
    int t;
    cin >> t;
    
    for(int i = 0; i<t; i++){
        int a;
        cin>>a;
        vector<int> temp;
        for(int j = 0; j<a; j++){
            int b;
            cin>>b;
            temp.push_back(b);
        }
        cout<<solve(temp)<<endl;
    }
}