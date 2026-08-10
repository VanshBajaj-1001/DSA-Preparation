#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
int n;
cin>>n;
vector<int> height(n);
for(int i=0;i<n;i++){
    cin>>height[i];
}
int l=0;
int r=n-1;
int ans=0;
 while(l<r){
     int width=r-l;
     int h=min(height[l],height[r]);
     int currentwater=width*h;
      ans=max(ans,currentwater);
     if(height[l]<height[r]){
         l++;
     }
     else{
         r--;
     }
 }
 cout<<ans<<endl;
 return 0;
}
