class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        int sum = 0; // sum prefix sum store karega
                     // yani current index tak ka total

        for(int i = 0; i < nums.size(); i++){
            sum = sum + nums[i]; // current element ko running total me add kiya

            nums[i] = sum; // current index par running sum store kar diya
                           // isse array khud hi answer array ban jaata hai
        }
        return nums; // modified array hi running sum answer hai
    }
};

/*

TC -> O(n) | -> SC -> O(1) (ignoring returned input vector itself)
 
*/