class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int maxWealth = 0;
        for(int i = 0; i < accounts.size(); i++){ // This goes customer by customer, i.e., row by row
            int wealth = 0; // Har ek customer ke liye, wealth ko reset karna hoga
        for(int j = 0; j < accounts[i].size();j++){ // Goes through all bank accounts for that customer
                wealth = wealth + accounts[i][j];
            }
            if(wealth > maxWealth){
                maxWealth = wealth;
            }
        }
        return maxWealth;
    }
};

/*

accounts is a 2D vector
So, accounts.size() returns number of rows
one row = one customer

accounts[i].size() returns number of elements in row i

Therefore i goes over customers/rows
          j goes over banks for that customer/columns
          
TC -> O(no. of rows * no. of columns) or O(total number of elements)
SC -> O(1)

*/