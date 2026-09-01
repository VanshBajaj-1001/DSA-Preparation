#include <bits/stdc++.h>
using namespace std;
class Solution {
public: bool possible(vector<int>& bloomday,int m,int k,int day){
    int bouquets=0;
    int consecutive=0;
    for(int i:bloomday){
        if(i<=day){
            consecutive++;
            if(consecutive==k){
                bouquets++;
                consecutive=0;
            }
        }
        else{
            consecutive=0;
        }
    }
    return bouquets>=m;
}
    int minDays(vector<int>& bloomDay, int m, int k) {
        long long req=1LL*m*k;
        if(req>bloomDay.size()){
            return -1;
        }
        int l=*min_element(bloomDay.begin(),bloomDay.end());
        int h=*max_element(bloomDay.begin(),bloomDay.end());
        while(l<h){
            int mid=l+(h-l)/2;
            if(possible(bloomDay,m,k,mid)){
                h=mid;
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
     int n;cin>>n;
    vector<int> nums(n);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    int m;
    cin>>m;
    int k;
    cin>>k;
    cout<<obj.minDays(nums,m,k);
    return 0;
}