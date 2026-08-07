class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int i = 0;
        // Left  pointer array ke start par
        // Yahan large negative magnitude mil sakta hai
        // jiska square bahut bada ho sakta hai

        int j = nums.size() - 1;
        // Right pointer array ke end par
        // Yahan large positive value mil sakti hai
        // jiska square bhi bahut bada ho sakta hai

        vector<int> ans(nums.size());
        // Final sorted square answer array
        // Same size ki hogi as input

        int position = nums.size() - 1;
        // Answer array ko ham back se fill karenge
        // Kyunki har step par hame current LARGEST square mil raha hai

        while(i <= j){
            // Jab tak dono pointers valid range me hain
            // compare karte rahenge

            int leftSquare = nums[i] * nums[i];
            int rightSquare = nums[j] * nums[j];
            // Dono ends ke squares nikaal liye

            if(leftSquare < rightSquare){
                ans[position] = rightSquare;
                // Agar right side ka square bada hai
                // to wahi current largest square hoga
                // Isliye answer ke current last free position par daal diya

                j--;
                // Right value use ho chuki hai
                // to right pointer ko ek step left shift karo
            }
            else{
                ans[position] = leftSquare;
                // Aga left square bada hai ya equal hai
                // to use current largest maan kar answer me daal diya

                i++;
                // Left value use ho chuki hai
                // to left pointer ko ek step right shift karo 
            }
            position--;
            // Ek largest square place ho gaya
            // to answer me next placement usse ek position pehle hogi
        }
        return ans;
        // Fully sorted squared array return kar di
    }
};

/*

while(i <= j) and n ot <
because jab i == j hoga, tab bhi ek element bacha hai, aur uska square answer me daalna hoga
Answer array back se fill hogi because every comparison gives current "largest remaining square"

TC -> O(n) | SC -> O(n)

*/