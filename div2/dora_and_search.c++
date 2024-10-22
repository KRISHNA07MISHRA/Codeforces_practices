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
vector<int> solve(vector<int>&arr){
    vector<int> ans;
 
    int left = 1;
    int right = arr.size();
    int i = 0;
    int j = arr.size()-1;
    bool flag = false;
    while(i<=j){
        if(arr[i] != left && arr[i] != right && arr[j] !=  left && arr[j] != right){
            ans.push_back(i+1);
            flag = true;
            ans.push_back(j+1);
            break;
        }
 
        if(arr[i] == left){
            i++;
            left++;
        }
        if(arr[i] == right){
            i++;
            right--;
        }
        if(arr[j] == left){
            j--;
            left++;
        }
        if(arr[j] == right){
            j--;
            right--;
        }
    }
    if(flag == false){
        return {-1};
    }
    return ans;
}
 
int main(){
    long long n;
    cin>>n;
    for(int i = 0;i<n; i++){
        int a;
        cin>>a;
        vector<int> arr1;
        
        for(int j = 0; j<a; j++){
            int b;
            cin>>b;
            arr1.push_back(b);
        }
        
 
        vector<int> ans = solve(arr1);
        if(ans[0] == -1){
            cout<<-1<<endl;
        }
        else{
            cout<<ans[0]<<" "<<ans[1]<<endl;
        }
    }
    
}