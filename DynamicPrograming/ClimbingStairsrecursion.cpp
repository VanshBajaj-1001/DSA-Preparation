class Solution {
public:
    int climbStairs(int n) {
        if(n==0){
            return 1;
        }
        if(n==1)return 1;
        int stepone=climbStairs(n-1);
        int steptwo=climbStairs(n-2);
        return stepone+steptwo;
    }
};