class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int maximumWealth = 0;
        // Ab tak ka sabse zyada wealth store karega
        // 0 se start isliye kiya kyunki minimum possible wealth 0 hai
        // (problem constraints me values non-negative hain)

        for(int i = 0; i < accounts.size(); i++){
            // Har customer ke liye ek baar loop chalega
            // i = customer ka index

            int currentWealth = 0;
            // Current customer ki total wealth
            // Har nayi customer ke liye fresh 0 se start karna zaroori hai

            for(int j = 0; j < accounts[i].size(); j++){
                currentWealth += accounts[i][j];
                // Curret customer ke saare ban k accounts ka paisa add karte jaa rahe hain
                // accounts[i][j] = i-th customer ka j-th bank account
            }
            maximumWealth = max(maximumWealth, currentWealth);
            // Is customer ki total wealth ko ab tak ke maximum se compare karo
            // Agar ye zyada hai to answer update kar do
        }
        return maximumWealth;
        // Sabse ameer customer ki wealth return kar di
    }
};

/*

accounts is a 2D vector
So, accounts.size() returns number of rows
one row = one customer

accounts[i].size() returns number of elements in row i

Therefore i goes over customers/rows
          j goes over banks for that customer/columns
          
TC -> O(no. of rows * no. of columns) -> O(m * n) or O(total number of elements) | SC -> O(1)

*/