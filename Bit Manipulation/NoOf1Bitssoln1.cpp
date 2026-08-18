#include<iostream>
using namespace std;
class Solution {
public:
    int hammingWeight(int n) {
        int count=0;
        while(n>0){
            if(n&1){
                count++;
            }
         n=n>>1;
        }
        return count;
    }
};
int main(){
    Solution obj;
    int n;
    cin>>n;
    int ans=obj.hammingWeight(n);
    cout<<"Output "<<ans<<endl;
    return 0;
}