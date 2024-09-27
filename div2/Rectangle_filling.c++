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
 
string solve(vector<vector<char>>&matrix){
    int firstwhite = 0;
    int firstblack = 0;
    int lastwhite = 0;
    int lastblack = 0;
    int firstcolwhite = 0;
    int lastcolwhite = 0;
    int firstcolblack = 0;
    int lastcolblack = 0;
    int n = matrix.size();
    int m = matrix[0].size();
    if(n == 1 && matrix[0][0] != matrix[0][m-1]){
        return "NO";
    }
    else if(m == 1 && matrix[0][0] != matrix[n-1][0]){
        return "NO";
    }
    if((matrix[0][0] == matrix[n-1][m-1]) || (matrix[0][m-1] == matrix[n-1][0])){
        return "YES";
    }

    for(int i = 0; i<matrix[0].size(); i++){
        if(matrix[0][i] == 'W'){
            firstwhite++;
        }
        else if(matrix[0][i] == 'B') {
            firstblack++;
        }
        if(matrix[n-1][i] == 'W'){
            lastwhite++;
        }
        else if(matrix[n-1][i] == 'B') {
            lastblack++;
        }
    }
    
    for(int i = 0; i<matrix.size(); i++){
        if(matrix[i][0] == 'W'){
            firstcolwhite++;
        }
        else if(matrix[i][0] == 'B'){
            firstcolblack++;
        }
        if(matrix[i][m-1] == 'W'){
            lastcolwhite++;
        }
        else if(matrix[i][m-1] =='B'){
            lastcolblack++;
        }
    }
    if(((lastwhite>0 && lastblack>0)  || (firstblack>0 && firstwhite>0)) && 
    ((lastcolblack>0 && lastcolwhite>0) || (firstcolblack>0 && firstcolwhite>0))){
        return "YES";
    }
    return "NO";
}
 
int main() {
 
    long long n;
    cin>>n;
    
    for(int i = 0; i<n; i++){
        long long a,b;
        cin>>a;
        cin>>b;
        vector<vector<char>> matrix;
        for(int j = 0; j<a; j++){
            vector<char> temp;
            for(int k = 0; k<b; k++){
                char ch;
                cin>>ch;
                temp.push_back(ch);
            }
            matrix.push_back(temp);
        }

        cout<<solve(matrix)<<endl;
    }
   
    
    
}