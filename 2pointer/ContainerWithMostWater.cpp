#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxArea(vector<int>& height) {
        
        int left=0;
        int right=height.size()-1;
        int maxwater=0;
        while(left<right){
            int width=right-left;
            int ht=min(height[left],height[right]);
            int water=ht*width;
            maxwater=max(maxwater,water);
            if(height[left]<height[right]){
                left++;
            }
            else{
                right--;
            }
        }
        return maxwater;
        
    }
};
int main(){
    Solution obj;
    int n;
    cin>>n;
    vector<int> height(n);
    for(int i=0;i<n;i++){
        cin>>height[i];
    }
    int ans=obj.maxArea(height);
    cout<<ans<<endl;
    return 0;
}