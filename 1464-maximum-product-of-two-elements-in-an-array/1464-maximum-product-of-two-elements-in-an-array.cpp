// class Solution {
// public:
//     int maxProduct(vector<int>& nums) {
//         int maxProduct = 1;
//         int product;
//         int maxIindex;
//         int maxJindex;
//         for(int i = 0; i < nums.size() - 1; i++){
//             for(int j = i + 1; j < nums.size(); j++){
//                 product = nums[i] * nums[j];
//                 if(product >= maxProduct){
//                     maxProduct = product;
//                     maxIindex = i;
//                     maxJindex = j;
//                 }
//             }
//         }
//         int maximum = (nums[maxIindex] - 1) * (nums[maxJindex] - 1);
//         return maximum;
//     }
// };

// TC -> O(n^2) because checking every pair

/*

Now problem is asking for (nums[i] - 1) * (nums[j] - 1) to be maximum
Since nums[i] >= 1, best pair would be "Largest two numbers"

So we need to find out Largest and second largest numbers using one-pass tracking



*/

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int largest = nums[0];
        int secondLargest = nums[1];
        for(int i = 1; i < nums.size(); i++){
            if(nums[i] > largest){
                secondLargest = largest;
                largest = nums[i];
            }
            else if(nums[i] > secondLargest){
                secondLargest = nums[i];
            }
        }
        return (largest - 1) * (secondLargest - 1);
    }
};