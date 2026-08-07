// class Solution {
// public:
//     double findMaxAverage(vector<int>& nums, int k) {
//         double sum = 0;
//         double maxSum = 0;
//         int count = 0;
//         for(int i = 0; i < nums.size(); i++){
//             if(count == k){
//                 sum = sum - nums[i - k] + nums[i];
//                 maxSum = max(maxSum, sum);
//                 continue;
//             }
//             sum += nums[i];
//             maxSum = sum; 
//             count++;
//         }
//         return maxSum / k;
//     }
// };

/*

Logic is correct, but we are doing window building and sliding in the same loop
count is unnecessary 
aur har baar maxSum partial sum ho raha hai, finally window ke size ka sum hua
So
> Calculate sum of first k elements
> Set maxSum = sum;
now slide from index i = k to i = n - 1

Pattern:
newWindowSum = oldWindow - outgoing + incoming

TC -> O(n) | SC -> O(1)

*/

class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double sum = 0; // point me chahiye isliye double

        // Step 1: Pehle k elements ka sum nikaalo
        // Ye hamara pehla "Window" hai
        for(int i = 0; i < k; i++){
            sum += nums[i];
        }

        // maxSum ko pehle window ke sum se initialize kiya 
        // Isse hame ek benchmark mil gaya compare karne ke liye
        double maxSum = sum;

        // Step 2: Window ko slide karna shuru karo
        // Index 'k' se start karengee kyunki 0 to k - 1 tak pehle hi add ho chuka hai
        for(int i = k; i < nums.size(); i++){

            // SLIDING WINDOW TRICK:
            // Nayi window ka sum = Purani window ka sum 
            //                      - Jo element peeche chhoot gaya(nums[i - k])
            //                      + Jo naya element andar aaya(nums[i])
            sum = sum - nums[i - k] + nums[i];

            // Har step par check karo kya ye naya sum ab tak ka best hai?
            maxSum = max(maxSum, sum);
        }

        // Final average nikalne ke liye k se divide kiya
        // double return type hai, aur hamare variables bhi double hain
        // toh precise answer milega
        return maxSum / k;
    }
};

/*

TC -> O(n) | SC -> O(1)

*/