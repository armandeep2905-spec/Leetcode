class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        int Ts = 0;

       for(int i = 0 ; i < stones.size() ; i++){

           Ts += stones[i];
       } 

       int target = Ts / 2;
        

        vector<int> dp(target + 1, 0 );

        for (int x : stones){
            for (int j = target ; j >= x ; j--){
                dp[j] = max(dp[j] , x + dp[j - x]);
            }
       }

        return Ts - 2 * dp[target];
    }
};