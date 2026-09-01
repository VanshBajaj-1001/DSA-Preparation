#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
int daysneeded(vector<int> &weights,int capacity){
    int days=1;
    int currentLoad=0;
    for(int i:weights){
        if(currentLoad+i>capacity){
            days++;
            currentLoad=i;
        }
        else{
            currentLoad+=i;
        }
    }
    return days;
}
    int shipWithinDays(vector<int>& weights, int days) {
        int l=*max_element(weights.begin(),weights.end());
        int r=accumulate(weights.begin(),weights.end(),0);
        while(l<r){
            int mid=l+(r-l)/2;
            int daysrequired=daysneeded(weights,mid);
            if(daysrequired<=days){
                r=mid;
            }
            else{
                l=mid+1;
            }
        }
        return l;
    }
};
int main(){
    Solution obj;
    int n;
    cin>>n;
    vector<int> weights(n);
    for(int i=0;i<n;i++){
     cin>>weights[i];
    }
    int days;
    cin>>days;
    int ans=obj.shipWithinDays(weights,days);
    cout<<ans<<endl;
    return 0;
}