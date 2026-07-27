class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> ans(nums.size());
        // answer array final result store karegi
        // Is array ko extra space me count nahi karte
        // because problem returned output ko ignore karti hai

        int leftProduct = 1;
        // leftProuct current index k eleft side ke elements ka product rakhega

        ans[0] = 1; // Because index 0 ke left me kuch bhi nahi hota
                    // Empty product = 1

        for(int i = 1; i < nums.size(); i++){
            leftProduct *= nums[i - 1];
            // leftProduct me i se just previous element tak ka product build kar rahe hain

            ans[i] = leftProduct;
            // Ab ans[i] = product of all elements to the left of i
        }
        int rightProduct = 1;
        // rightProduct current index ke right side ke elements ka product rakhega
        // Because last index ke right me kuch nahi hota, so start with 1

        for(int i = nums.size() - 2; i >=0; i--){ // starts from n - 2 because last n - 1 ke right me kuch nahi hota 
                                                  // So uska right product is just 1 and ans[n - 1] has already left product from first pass
            rightProduct *= nums[i + 1];
            // Right side ka running product build kar rahe hain
            
            ans[i] = ans[i] * rightProduct;
            // ans[i] already left product hold kar raha hai
            // ab use right product se multiply karke
            // final product except self bana diya 
        }
        return ans;
        // Final answer return kar di
    }
};

/*

Don't think: total product - self
For every index i: 
ans[i] = product of all elements to left of i * product of all elements to right of i
first store product of all elements to the left of i(first element ko 1 de diya kyunki uske left me kuch nahi tha)
phir second last se shuru karte hue right side ke product ko har ek answer ke element se multiply kar ke usi me store kar diya(left pehle se tha * right)

so instead of doing division, directly left product * right product

TC -> O(n) | SC -> O(1) extra (excluding output array in this specific question)

*/