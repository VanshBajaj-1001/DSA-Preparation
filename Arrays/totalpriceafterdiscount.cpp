#include <iostream>
#include<vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    double minPrice(vector<int>& prices, vector<int>& discounts) {
        sort(prices.begin(),prices.end(),greater<int>());
        sort(discounts.begin(),discounts.end(),greater<int>());
        double ans=0.0;
        int m=discounts.size();
        for(int i=0;i<prices.size();i++){
            if(i<m){
                ans+=prices[i]*((100.0-discounts[i])/100.0);
            }
            else{
                ans+=prices[i];
            }
        }
        return ans;
    }
};
int main(){
    Solution obj;
    int n;
    double ans;
    int m;
    cout<<"Enter the no of prices"<<endl;
    cin>>n;
    cout<<"Enter no of discounts"<<endl;
    cin>>m;
    cout<<"Enter the  prices";
    vector<int> prices(n);
    for(int i=0;i<n;i++){
        cin>>prices[i];
    }
    cout<<"Enter the discounts"<<endl;
    vector<int> discounts(m);
    for(int i=0;i<m;i++){
        cin>>discounts[i];
    }
    ans=obj.minPrice(prices,discounts);
    cout<<"Output "<<ans<<endl;
    return 0;
}