#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
     int coin(vector<int> &coins,int amount,vector<int> &ans){
       if(amount==0){
        return 0;
       }
       if(amount <0){
        return INT_MAX;
       }
       if(ans[amount]!=-1){
        return ans[amount];
       }
       int answer=INT_MAX;
    
        for(int i: coins){
            int result=coin(coins,amount-i,ans);
            if(result!=INT_MAX){
                answer=min(answer,result+1);
            }
        }
        ans[amount]=answer;
        return ans[amount] ;
     }
    int coinChange(vector<int>& coins, int amount) {
        vector<int> ans(amount+1,-1);
        int answer=coin(coins,amount,ans);
        if(answer==INT_MAX){
            return -1;
        }
        return answer;
    }
};
int main(){
    Solution obj;
    int n;
    cin>>n;
    vector<int> coins(n);
    cout<<"Enter the coins"<<endl;
    for(int i=0;i<n;i++){
        cin>>coins[i];
    }
    int amount;
    cout<<"Target"<<endl;
    cin>>amount;
    int ans=obj.coinChange(coins,amount);
    cout<<"Output "<<ans<<endl;
return 0;
}