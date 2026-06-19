class Solution {
public:
    int maxProfit(vector<int>& prices) {
       int maxProfit = 0 ;
       int minElem = prices[0];
       for(int i = 1 ; i < prices.size() ;  i++)
       {
          int sell = prices[i];
          int profit = sell - minElem;
          maxProfit = max(profit ,  maxProfit);
          minElem = min (minElem ,  prices[i]);

       }
       

       return maxProfit;
    }
};