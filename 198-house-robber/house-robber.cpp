class Solution {
public:

// another way to solve the problem , start from last index 
//   int helper(int idx , vector<int> nums){
//     if(idx >= nums.size()) return 0;

//     int take = nums[idx] + helper(idx + 2   , nums); // idx2 bcauz cant rob adjacent houses 
//     int nonTake = helper(idx + 1  , nums); // skipping the current one , chosing the next 
//     return max(take , nonTake);
//   }



 // start from first index
  int helper2(int idx , vector <int> nums , vector<int> & dp){
    
    if(idx < 0 ) return 0;
    if(dp[idx] != -1) return dp[idx];  
    int take = nums[idx] + helper2(idx - 2  , nums , dp);
    int nonTake = helper2( idx - 1 , nums , dp);

    return dp[idx] =  max(take ,  nonTake);
  }


    int rob(vector<int>& nums) {
        vector<int> dp(nums.size() ,  -1);
        return helper2(nums.size() - 1 , nums , dp);
    }
};