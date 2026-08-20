#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void reverseString(vector<char>& s) {
        int beg=0;
        int end=s.size()-1;
        while(beg<end){
            char temp=s[beg];
            s[beg]=s[end];
            s[end]=temp;
            beg++;
            end--;
        }
    }
};
int main(){
    Solution obj;
    int n;
    cin>>n;
    vector<char> s(n);
    for(int i=0;i<n;i++){
        cin>>s[i];
    }
    obj.reverseString(s);
    for(auto i:s){
        cout<<i<<" ";
    }
    return 0;
}