class Solution {
public:

    // int temp(int index , bool buy , int size , vector<int>& prices ,  vector<vector<int>> &dp ){

    //     if(index == size) return 0;
    //     if(dp[index][int(buy)] != -1) return dp[index][int(buy)];
    //       long profit = 0 ;
    //     if(buy == true){
    //         // choice1 is to buy 
    //        long profit1 = -prices[index] + temp(index+1 , false , size , prices ,dp);
    //         //choice 2 is to not buy 
    //        long  profit2 =  0 + temp (index +1 ,  true, size , prices , dp);
    //        profit =  max(profit1 , profit2);
    //     }

    //     else // condition is we have to sell , we cant buy , bool buy ==false
    //     {
    //           //choice1 is to sell 
    //        long profit1 = prices[index] + temp(index +1 , true, size , prices , dp);
    //        //choic2 is not sell and wait so we cant buy yet
    //       long profit2 =  0 + temp(index+1 , false, size , prices ,dp );
    //           profit = max(profit1 , profit2);
    //     }

    //     return dp[index][int(buy)] = profit;
    //     }
    
    int maxProfit(vector<int>& prices) {
        // vector<vector<int>> dp(prices.size(), vector<int>(2, -1));
        // return temp(0 , 1 ,prices.size() , prices , dp);



        int profit = 0;

        for(int i = 1; i < prices.size(); i++) {

            if(prices[i] > prices[i-1])

                profit += prices[i] - prices[i-1];

        }

        return profit;

    }
    
};