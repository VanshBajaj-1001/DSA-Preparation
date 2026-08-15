#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int elevatorRequests(int n, vector<int>& requests) {
        int sum=requests[0];
        for(int i=1;i<requests.size();i++){
            sum+=abs(requests[i]-requests[i-1]);
            
        }
        return sum;
    }
};
int main(){
    Solution obj;
    int i;
    cout<<"Enter no of elements in the array"<<endl;
    cin>>i;
    vector<int> requests(i);
    cout<<"Enter requests in the array"<<endl;
    for(int j=0;j<i;j++){
        cin>>requests[j];
    }
    int n;
    cout<<"Enter no of floors";
    cin>>n;
    int sum=obj.elevatorRequests(n-1,requests);
    cout<<"Output "<<sum<<endl;
    return 0;
}