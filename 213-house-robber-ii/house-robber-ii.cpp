class Solution {
public:
 
    int helper ( vector<int> nums , vector<int> &dp , int start , int end ){
        if(start > end) return 0;

        if(dp[start] != -1) return dp[start];

        // take 
        int take = nums[start] + helper(nums , dp , start + 2 , end);
        // not Take
        int notTake = helper(nums , dp , start+1 , end);

        return dp[start] = max(take , notTake);
    }
     
    int rob(vector<int>& nums) {
        if(nums.size() == 1) return nums[0];
        vector<int> dp (nums.size()  , -1);
        vector<int> dp2 (nums.size()  , -1);
        return max( helper(nums , dp , 0 , nums.size() - 2 ) ,  helper(nums , dp2 , 1 , nums.size() - 1) );
    }
}; 