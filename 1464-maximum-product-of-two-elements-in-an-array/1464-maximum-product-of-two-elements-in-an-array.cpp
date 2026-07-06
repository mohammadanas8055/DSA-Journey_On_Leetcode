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
        int largest = max(nums[0], nums[1]); 
        int secondLargest = min(nums[0], nums[1]);

        // I need two numbers to begin with, so I take first two positions -> to pehle maan liya ki pehla largest hai aur dusra second largest
        // Phir loop me check bhi kar liya, pehle element se shuru karte hue, ki agar wo largest hua, to second largest aur largest exchange ho jayenge
        // i = 0 ko largest maana hai to 0 se shuru nahi karne ki zaroorat hai
        // par nums[1] ko secondLargest bagair order check kare maana hai
        // to nums[1] se shuru karenge largest se compare karne ke liye

        // So better use max and min and start the loop from i = 2

        for(int i = 2; i < nums.size(); i++){
            if(nums[i] > largest){
                secondLargest = largest;
                largest = nums[i];
            }
            
            // else if means "only check secondLargest if current number did NOT become largest.""
            // Two cases which are separated by if and else if
            // 1. current is new largest
            // 2. current is not largest, but can become second largest
            else if(nums[i] > secondLargest){
                secondLargest = nums[i];
            } // else ensure that nums[i] <= largest, so no need for that condition to write
            // BUT if(nums[i] > secondLargest && nums[i] <= largest) doesn't do what else if does
            //kyunki upar se aate hue largest ki value change ho gayi
            // ab agle if bhi chalega aur condition satisfy hogi hi(largest nums[i] ho chuka hai, to nums[i] <= largest rahega)
            // to ye wrong hai
            // Same element got used as both second largest and largest
            //else if means: If current element already became largest, don’t check it again for secondLargest.
        }
        return (largest - 1) * (secondLargest - 1);
    }
};

// Main takeaway:

// If you need best two values, track largest and secondLargest.
// When a new largest comes, old largest becomes second largest.
// If current is not largest but bigger than second largest, update second largest.