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

long long solve(vector<long long>&arr){
    int j = arr.size()-1;
    int count = 0;
    int ans = 0;
    int target = arr[j];
    while(j>=0){
        while(arr[j] == target && j>=0){
            j--;
            count++;
        }
        if(j <0){
            break;
        }
        ans++;
        int temp = count;
        while(temp-- && j>=0){
            j--;
        }
        count *=2;
        if(j<0){
            break;
        }


    }
    return ans;

}

int main() {
    long long n;
    cin>>n;
    for(int i = 0; i<n; i++){
        long long a;
        cin>>a;
        
        vector<long long> second;
       
        for(int j = 0; j<a; j++){
            long long c;
            cin>>c;
            second.push_back(c);
        }

        cout<<solve(second)<<endl;
    }
}