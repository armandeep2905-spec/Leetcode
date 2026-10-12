class Solution {
public:

    int calculate(vector<int> &dp , int n){
         if(n==1) return 1;
         if(n==2) return 2;
         if(dp[n] != -1) return dp[n];
         dp[n] = calculate(dp , n-1) + calculate(dp , n-2);
         return dp[n];
    }
    int climbStairs(int n) {
        vector<int> dp(n+1 , -1);
        return calculate(dp , n);
    }
};