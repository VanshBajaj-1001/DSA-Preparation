#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
       int n=prices.size();
       int minprice=INT_MAX;
       int maxprofit=0;
       for(int i:prices){
        if(i<minprice){
            minprice=i;
        }
        else{
            maxprofit=max(maxprofit,i-minprice);
        }
       }
       return maxprofit;
    }
};
int main(){
    Solution obj;
    int n;
    cin>>n;
    vector<int> nums(n);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    int profit=obj.maxProfit(nums);
    cout<<profit<<endl;
    return 0;
}