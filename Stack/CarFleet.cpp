#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n=position.size();
        vector<pair<int,double>> cars;//position,time
        for(int i=0;i<n;i++){
            double time=(double)(target-position[i])/speed[i];
            cars.push_back({position[i],time});
        }
        sort(cars.begin(),cars.end(),greater<pair<int,double>>());//sort in descending order
        stack<double> st;
        for(int i=0;i<n;i++){
            double time=cars[i].second;
            if(st.empty()||time>st.top()){
                st.push(time);
            }
        }
        return st.size();
    }
};
int main(){
    Solution obj;
    int n;
    cin>>n;
    int target;
    cin>>target;
    vector<int> position(n);
    for(int i=0;i<n;i++){
        cin>>position[i];
    }
    vector<int> speed(n);
    for(int i=0;i<n;i++){
        cin>>speed[i];
    }
    int noofleets=obj.carFleet(target,position,speed);
    cout<<noofleets<<endl;
    return 0;
}