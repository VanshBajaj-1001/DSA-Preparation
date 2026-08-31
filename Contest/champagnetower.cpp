#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
int p;
int r;
int c;
cin>>p;
cin>>r;
cin>>c;
double glasses[100][100]={};
glasses[0][0]=p;
for(int i=0;i<r;i++){
    for(int j=0;j<=i;j++){
        if(glasses[i][j]>1.0){
            double overflow=(glasses[i][j]-1.0)/2.0;
            glasses[i+1][j]+=overflow;
            glasses[i+1][j+1]+=overflow;
        }
    }
}
double ans=min(1.0,glasses[r][c]);
cout<<fixed<<setprecision(5)<<ans;
return 0;
}
