#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minBishopMoves(vector<int>& source, vector<int>& target) {
        int x1=source[0];
        int y1=source[1];
        int x2=target[0];
        int y2=target[1];
        if(x1==x2 && y1==y2){
            return 0;
        }
        if((x1+y1)%2!=(x2+y2)%2){
            return -1;
        }
        if(abs(x1-x2)==abs(y1-y2)){
            return 1;
        }
        return 2;
    }
};
int main(){
    Solution obj;
    vector<int> source(2);
    vector<int> target(2);
    cin>>source[0];
    cin>>source[1];
    cin>>target[0];
    cin>>target[1];
    cout<<obj.minBishopMoves(source,target);
    return 0;


}