#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
   int n;
   int k;
   string s;
   cin>>n;
   cin>>k;
   cin>>s;
   int l=0;
   int white=0;
   int ans=INT_MAX;
   for(int r=0;r<n;r++){
       if(s[r]=='W'){
           white++;
       }
       if(r-l+1>k){
           if(s[l]=='W'){
               white--;
           }
           l++;
       }
       if(r-l+1==k){
           ans=min(ans,white);//minimum no of white that need to be colored black
       }
   }
   cout<<ans<<endl;
   return 0;
}
