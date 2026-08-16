#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minPenalty(int period, vector<int>& lights, vector<int>& arrivalTime) {
        int maxgreen=0;
        for(int i: lights){
            maxgreen=max(maxgreen,i);
        }
      int maxWT=0;
        for(int i:arrivalTime){
            int r=i%period;
            int wait;
            if(r<maxgreen){
                wait=0;
            }
            else{
                wait=period-r;
            }
            maxWT=max(maxWT,wait);
        }
        return maxWT;
    }
};
int main(){
    Solution obj;
    int period;
    cout<<"Enter period"<<endl;
    cin>>period;
    int n;
    cout<<"Enter no of lights"<<endl;
    cin>>n;
    vector<int> lights(n);
    cout<<"Enter duartion of each  lights"<<endl;
    for(int i=0;i<n;i++){
        cin>>lights[i];
    }
    int c;
    cout<<"Enter no of cars"<<endl;
    cin>>c;
    vector<int> arrivalTime(c);
    cout<<"Enter arrival time of each car"<<endl;
    for(int i=0;i<c;i++){
        cin>>arrivalTime[i];
    }
    int ans=obj.minPenalty(period,lights,arrivalTime);
    cout<<"Output "<<ans<<endl;
    return 0;
}