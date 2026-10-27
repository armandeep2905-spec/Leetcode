class Solution {
public:
     int minCost = 0;
    int helper (vector<int>& dp , vector<int> cost , int i){
          if(i >= cost.size()) return 0;
         if(dp[i] != -1) return dp[i];
          int s1 = cost[i] + helper(dp , cost , i+1);
          int s2 = cost[i] + helper(dp ,cost , i+2);
         
        return dp[i] = min(s1 , s2);
          
    }
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> dp(cost.size() , -1);
        return min(helper(dp , cost , 0) , helper(dp , cost , 1));
    }
};