#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.size()>s2.size()){
            return false;
            }
            vector<int> f1(26,0);
            vector<int> f2(26,0);
            for(char ch:s1){
                f1[ch-'a']++;
            }
            int k=s1.size();
            for(int i=0;i<k;i++){
             f2[s2[i]-'a']++;
            }
            if(f1==f2){
                return true;
            }
            for(int i=k;i<s2.size();i++){
                f2[s2[i]-'a']++;
                f2[s2[i-k]-'a']--;
                if(f1==f2){
                    return true;
                } 
            }
return false;
        
    }
};
int main(){
    Solution obj;
    string s1;
    string s2;
    cin>>s1;
    cin>>s2;
    bool ans=obj.checkInclusion(s1,s2);
    if(ans){
        cout<<"True";
    }
    else{
        cout<<"False";
    }
    return 0;
}