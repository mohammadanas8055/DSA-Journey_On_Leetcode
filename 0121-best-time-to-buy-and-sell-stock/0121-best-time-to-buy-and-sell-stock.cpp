class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minimum = prices[0];
        int profitIfSellToday = 0;
        int maxProfit = 0;
        for(int i = 0; i < prices.size(); i++){
            profitIfSellToday = prices[i] - minimum;
            if(profitIfSellToday > maxProfit){
                maxProfit = profitIfSellToday;
            }
            if(minimum > prices[i]){
                minimum = prices[i];
            }
        }
        return maxProfit;
    }
};