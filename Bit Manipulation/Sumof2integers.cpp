#include <iostream>
using namespace std;
class Solution {
public:
    int getSum(int a, int b) {
        while(b!=0){
            int carry=(a&b)<<1;
            a=a^b;
            b=carry;
        }
        return a;
    }
};
int main(){
    Solution obj;
    int a;
    int b;
    cin>>a;
    cin>>b;
    int sum=obj.getSum(a,b);
    cout<<sum<<endl;
    return 0;
}