class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minimumSoFar = prices[0]; // ek ek minimum ke liye, baar baar profit dekho, agar maximum profit hai , to wo answer hoga
        int maximumProfit = 0;
        for(int i = 0; i < prices.size(); i++){
            int profitIfSellToday = prices[i] - minimumSoFar; // us day pe sell karne pe profit -> SP - CP(current minimum)
            if(profitIfSellToday > maximumProfit){
                maximumProfit = profitIfSellToday;
            }
            if(minimumSoFar > prices[i]){
                minimumSoFar = prices[i];
            }// minimum update karne ke liye , kyunki maximum profit = maximum SP - minimum CP
        }
        return maximumProfit;
    }
};

/*

Time complexity -> O(n)
Space complexity -> O(1)

"Single pass + track running state"

This is one of the MOST IMPORTANT patterns in DSA.

Used in:

Best Time to Buy/Sell Stock (today)
Maximum subarray sum (Kadane's algorithm)
Find max/min in array
Many "find optimal X" problems

*/