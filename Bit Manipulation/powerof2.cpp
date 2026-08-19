#include <iostream>
using namespace std;
class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n>0 && (n&(n-1))==0){
            return true;
        }
        else{
            return false;
        }
    }
};
int main(){
    Solution obj;
    int n;
    cin>>n;
    bool ans=obj.isPowerOfTwo(n);
    if(ans){
        cout<<"true"<<endl;
    }
    else{
        cout<<"false"<<endl;
    }
    return 0;
}