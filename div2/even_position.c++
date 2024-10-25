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
#include<map>
using namespace std;
long long solve(vector<long long>& arr){
    long long count = 0;
    vector<long long> brr;
    for(int i = 0; i<arr.size(); i++){
        brr.push_back(arr[i]);
    }
    for(int i = 1; i<=arr.size()/2; i++){
        if( arr[i-1] != arr[i]){
            continue;
        }
        else{
            long long rep = arr[(arr.size()-1)-i];
            long long val = arr[i];
            if( rep != arr[i]){
                swap(arr[(arr.size()-1)-i],arr[i]);
            }
            // else if(i != 0 && rep != arr[i-1] && rep != arr[i+1] && rep != arr[i]){
            //     swap(arr[arr.size()-1-i],arr[i]);
            // }
            
        }
    }
    for(int i = 0; i<arr.size()-1; i++){
        if(arr[i] == arr[i+1]){
            count++;
        }
    }
    for(int i = brr.size()-2; i>=brr.size()/2; i--){
        if(brr[i] != brr[i+1]){
            continue;
        }
        else{
            long long rep =  brr[(brr.size()-1)-i];
            long long val = brr[i];
            if(rep != val){
                swap(brr[(brr.size()-1)-i],brr[i]);
            }
        }
    }
    long long count2 = 0;
    for(int i = 0; i<brr.size()-1; i++){
        if(brr[i] == brr[i+1]){
            count2++;
        }
    }
    return min(count,count2);
}
long long  maxBeautifulSegments(vector<long long>& arr) {
    long long sum = 0;
    long long count = 0;
    map<long long, int> prefixSumMap;

    // Initialize with prefix sum 0 to handle segments starting from the beginning
    prefixSumMap[0] = 1; 

    for (int i = 0; i < arr.size(); i++) {
        sum += arr[i];

        // If the prefix sum has been seen before, it means we found a beautiful segment
        if (prefixSumMap[sum]) {
            count++;
            // Reset the map for non-overlapping segments
            prefixSumMap.clear();
            // Reinitialize to start new segment tracking
            prefixSumMap[0] = 1;
            sum = 0;
        }

        // Mark current prefix sum
        prefixSumMap[sum]++;
    }

    return count;
}
int minimum_magic(vector<vector<int>>& matrix, int n) {
    int magic_count = 0;

    // Traverse along the diagonals from top-left to bottom-right
    for (int diag = 0; diag < n; ++diag) {
        int i = 0;       // Start row
        int j = diag;    // Start column

        while (i < n && j < n) {
            if (matrix[i][j] < 0) {
                // Amount of magic needed to make the diagonal element non-negative
                int needed_magic = -matrix[i][j];
                magic_count += needed_magic;

                // Apply this magic to the diagonal from (i,j) to the end of this diagonal
                int temp_i = i, temp_j = j;
                while (temp_i < n && temp_j < n) {
                    matrix[temp_i][temp_j] += needed_magic;
                    temp_i++;
                    temp_j++;
                }
            }

            i++;
            j++;
        }
    }

    return magic_count;
}

int main() {
    // long long n;
    // cin>>n;
    // for(int i = 0; i<n; i++){
    //     long long a;
    //     cin>>a;
    //     vector<long long> temp;
    //     for(int j = 0; j<a; j++){
    //         long long b;
    //         cin>>b;
    //         temp.push_back(b);
    //     }
    //     cout<<solve(temp)<<endl;
    // }

    int n;
    cin>>n;
    for(int i = 0; i<n; i++){
        string st;
        cin>>st;
        cout<<solve(st)<<endl;
    }
    
    return 0;
}