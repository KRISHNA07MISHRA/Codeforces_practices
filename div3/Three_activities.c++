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

//long long ans(long long index,vector<long long>&first,vector<long long>&second,vector<long long>&third,bool flag1,bool flag2, bool flag3 ){
    // if(index>=first.size() ){
    //     return 0;
    // }
    // long long nottake = ans(index+1,first,second,third,flag1,flag2,flag3);

    // long long take = 0;
    // if(flag1 == false){
    //     take = first[index] + ans(index+1,first,second,third,true,flag2,flag3);
    // }
    // if(flag2 == false){
    //     take = second[index] + ans(index+1,first,second,third,flag1,true,flag3);
    // }
    // if(flag3 == false){
    //     take = third[index] + ans(index+1,first,second,third,flag1,flag2,true);
    // }

    // return max(take,nottake);
// }
long long solve(vector<long long>&first,vector<long long>&second,vector<long long>&third){
    priority_queue<pair<long long,long long>> pq1;
    for(int i = 0; i<first.size(); i++){
        pq1.push({first[i],i});
    }
    vector<long long> temp1;
    int k1 = 3;
    while(!pq1.empty() && k1--){
        temp1.push_back(pq1.top().second);
        pq1.pop();
    }
    priority_queue<pair<long long,long long>> pq2;
    for(int i = 0; i<second.size(); i++){
        pq2.push({second[i],i});
    }
    vector<long long> temp2;
    int k2 = 3;
    while(!pq2.empty() && k2--){
        temp2.push_back(pq2.top().second);
        pq2.pop();
    }
    priority_queue<pair<long long,long long>> pq3;
    for(int i = 0; i<third.size(); i++){
        pq3.push({third[i],i});
    }
    vector<long long> temp3;
    int k3 = 3;
    while(!pq3.empty() && k3--){
        temp3.push_back(pq3.top().second);
        pq3.pop();
    }

    long long ans = 0;
    for(int i= 0; i<3; i++){
        for(int j = 0; j<3; j++){
            for(int k = 0; k<3; k++){
                if(temp1[i]!= temp2[j] && temp1[i]  != temp3[k] && temp2[j] != temp3[k]){
                    ans = max(ans,first[temp1[i]]+second[temp2[j]]+third[temp3[k]]);
                }
            }
        }
    }
    return ans;


}

// int solve(vector<long long>&arr, long long b){
//     priority_queue<long long> pq;
//     for(int i = 0; i<arr.size(); i++){
//         pq.push(arr[i]);
//     }
//     long long sum = 0;
//     while(!pq.empty()){
//         long long maxi = 0;
//         long long mini = 0;
//         long long k = b;
//         while(!pq.empty() && k--){
//             maxi = max(maxi,pq.top());
//             mini = min(mini,pq.top());
//             pq.pop();
//         }
//         sum += maxi;
//         long long sub = maxi-mini;
//         if(!pq.empty()){
//             int top = pq.top();
//             pq.pop();
//             top -= sub;
//             if(top>0){
//                 pq.push(top);
//             }
            
//         }

//     }
//     return sum;

// }

int main() {
    long long n;
    cin>>n;
    for(int i = 0; i<n; i++){
        long long a,b;
        cin>>a;


       
        vector<long long> first;
        vector<long long> second;
        vector<long long > third;
        for(int j = 0; j<a; j++){
            long long input;
            cin>>input;
            first.push_back(input);
        }
        for(int j = 0; j<a; j++){
            long long input;
            cin>>input;
            second.push_back(input);
        }
        for(int j = 0; j<a; j++){
            long long input;
            cin>>input;
            third.push_back(input);
        }
       // sort(first.begin(),first.end());

         cout<<solve(first,second,third)<<endl;
    }

    // cout<<(8%8)<<endl;

}
