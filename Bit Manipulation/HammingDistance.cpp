#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int hammingDistance(int x, int y) {
        int a=x^y;
        int count=0;
        while(a!=0){
            if(a&1){
                count++;
            }
            a=a>>1;
        }
        return count;
    }
};
int main(){
    Solution obj;
    int x;
    int y;
    cin>>x;
    cin>>y;
    cout<<obj.hammingDistance(x,y)<<endl;
    return 0;
}