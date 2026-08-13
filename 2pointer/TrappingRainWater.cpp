#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        int left=0;
        int right=height.size()-1;
        int lmax=0;
        int rmax=0;
        int water=0;
        while(left<=right){
            if(height[left]<=height[right]){
                if(height[left]>=lmax){
                    lmax=height[left];
                }
                else{
                    water+=lmax-height[left];
                }
                left++;
            }
            else{
                if(height[right]>=rmax){
                    rmax=height[right];
                }
                else{
                    water+=rmax-height[right];
                }
                right--;
            }
        }
        return water;
    }
};
int main(){
    Solution obj;
    int n;
    cout<<"Enter no of elements in the array"<<endl;
    cin>>n;
    cout<<"Enter heights in the array"<<endl;
    vector<int> height(n);
    for(int i=0;i<n;i++){
        cin>>height[i];
    }
    int water=obj.trap(height);
    cout<<"Output "<<water<<endl;
    return 0;
}