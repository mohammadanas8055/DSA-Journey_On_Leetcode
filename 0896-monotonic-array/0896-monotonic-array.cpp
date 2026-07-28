class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        int a = 0; // Increasing pairs ka count
        int b = 0; // Decreasing pairs ka count

        // Har adjacent pair ko check karenge
        for(int i = 0; i < nums.size() - 1; i++){

            // Agar current element chhota ya barabar hai
            if(nums[i] <= nums[i + 1]){
                a++;
            }

            // Agar current element bada ya barabar hai
            // Note: Equality (==) dono a aur b me count hogi
            // jo bilkul sahi hai kyunki constant array(ya constant pairs) dono me valid hoti hai
            if(nums[i] >= nums[i + 1]){
                b++;
            }
        }

        // Total pairs hamesha nums.size() - 1 hote hain
        // Agar saare pairs increasing nikle, YA saare decreasing nikle
        // To array Monotonic hai
        if(a == nums.size() - 1 || b == nums.size() - 1){
            return true;
        }
        // Warna nahi
        return false;
    }
};

/*

We can also write this using boolean flags 
Instead of counting how many times it obeyed the rule, we start by assuming it obeys BOTH rules. If it breaks a rule, we flip a flag to false

bool isIncreasing = true;
bool isDecreasing = true;

for(int i = 0; i < nums.size() - 1; i++){
    if(nums[i] > nums[i + 1]){
        isIncreasing = false; // It went down, so it can't be purely increasing
    }
    if(nums[i] < nums[i + 1]){
        isDecreasing = false; // It went up, so it can't be purely decreasing
    }
}

// If either of them is still true, it's monotonic
return isIncreasing || isDecreasing

*/

/*

Both methods are:
TC -> O(n) | SC -> O(1)

*/