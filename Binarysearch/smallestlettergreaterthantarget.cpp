#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int l=0;
        int r=letters.size()-1;
        while(l<=r){
            int mid=l+(r-l)/2;
            if(letters[mid]>target){
                r=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        if(l==letters.size()){
            return letters[0];
        }
        return letters[l];
    }
};
int main(){
    Solution obj;
    int n;
    cin>>n;
    vector<char> letters(n);
    for(int i=0;i<n;i++){
        cin>>letters[i];
    }
    char target;
    cin>>target;
    char ans=obj.nextGreatestLetter(letters,target);
    cout<<"Output "<<ans<<endl;
    return 0;
}