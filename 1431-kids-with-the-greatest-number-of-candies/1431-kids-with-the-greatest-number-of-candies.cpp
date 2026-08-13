class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        vector<bool> yesOrNo(candies.size());
        // Answer vector pre-allocate ki hai candies size ki
        // Har index par true/false store hoga

        int greatest = candies[0];
        // greatest me current maximum candies count store hoga
        // Initial value pehle bacche ki candies se start ki
        // Kyunki kisi bhi single element se comparison shuru karna safe hai

        for(int i = 1; i < candies.size(); i++){
            greatest = max(greatest, candies[i]);
            // Loop 1 se start kiya kyunki index 0 already greatest me hai
            // Har baar current value ko current maximum se compare kiye
        }
        // Loop ke baad greatest me sabse zyada candies wala value hoga
        
        for(int i = 0; i < candies.size(); i++){
            if(extraCandies + candies[i] >= greatest){
                yesOrNo[i] = true;
                // Agar current bacche ki candies+extraCandies
                // greatest ke barabar ya usse zyada ho jaye
                // to wo bacha "greatest" ban sakta hai

                // >= isliye kyunki barabar hone par bhi bacha tie kar leta hai
            }
            else{
                yesOrNo[i] = false;
                // Warna wo greatest tak nahi pahunch sakta
            }
        }
        return yesOrNo;
        // Har bacche ke liye true/false ka vector return kar diya
    }
};

/*

TC -> O(n) + O(n) = O(n) | SC -> O(n) (Extra auxiliary O(1))

*/