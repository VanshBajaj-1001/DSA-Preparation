#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
  int noofgasstations(double dist,vector<int> stations){
      int cnt=0;
      int n=stations.size();
      for(int i=1;i<n;i++){
          int noinbtw=(stations[i]-stations[i-1])/dist;
          if((stations[i]-stations[i-1])==(noinbtw*dist)){
              noinbtw--;
          }
          cnt+=noinbtw;
      }
      return cnt;
  }
    double minMaxDist(vector<int> &stations, int k) {
        // Code here
        double l=0;double h=0;
        int n=stations.size();
        for(int i=0;i<n-1;i++){
            h=max(h,(double)stations[i+1]-stations[i]);
        }
        double diff=1e-6;
        while(h-l>diff){
            double mid=l+(h-l)/2.0;
            int cnt=noofgasstations(mid,stations);
            if(cnt>k){
                l=mid;
            }
            else{
                h=mid;
            }
        }
        return h;
    }
};
int main(){
    Solution obj;
    int  n;
    cin>>n;
    vector<int> nums(n);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    int k;
    cin>>k;
    cout<<obj.minMaxDist(nums,k)<<endl;
    return 0;
}