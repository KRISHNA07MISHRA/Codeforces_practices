#include <iostream>
#include <cmath>
using namespace std;

int solve(vector<int>&temp){
    int i = 0;
    int j = temp.size()-1;
    int leftsum = temp[0];
    int rightsum = temp[j];
    int maxi = 0;
    i++;
    j--;
    while(i<j){
        while(leftsum<rightsum){
            leftsum += temp[i];
            i++;
        }
        while(rightsum<leftsum){
            rightsum += tem[j];
            j--;
        }
        if(rightsum == leftsum){
            int val = (i+1)+(temp.length()-j);
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
