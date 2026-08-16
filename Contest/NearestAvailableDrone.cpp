#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int nearestDrone(vector<vector<int>>& drones, vector<int>& target) {
        int best=INT_MAX;
        int ans=-1;
        for(int i=0;i<drones.size();i++){
            int x=drones[i][0];
            int y=drones[i][1];
            int range=drones[i][2];
            int distance=abs(x-target[0])+abs(y-target[1]);
            if(distance<=range &&distance<best){
                best=distance;
                ans=i;
            }
            
        }
        return ans;
    }
};
int main(){
    Solution obj;
    int n;
    cout<<"Enter no of elements "<<endl;
    cin>>n;
    vector<vector<int>> drones(n,vector<int>(3));
    cout<<"Enter Elements in the drone array"<<endl;
    for(int i=0;i<n;i++){
        cin>>drones[i][0];
        cin>>drones[i][1];
        cin>>drones[i][2];
    }
    vector<int> target(2);
    cout<<"Enter target coordinates"<<endl;
    cin>>target[0];
    cin>>target[1];
    int ans=obj.nearestDrone(drones,target);
    cout<<"Output "<<ans<<endl;
    return 0;
}