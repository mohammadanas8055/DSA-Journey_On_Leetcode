class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        // Har nums1 element ke liye nums2 me uska next greater dhoodhna hai

        for(int i = 0; i < nums1.size(); i++){
            int index;
            // pehle dhoondho ki nums1[i] nums2 me kis index par hai

            for(int j = 0; j < nums2.size(); j++){
                if(nums1[i] == nums2[j]){
                    index = j;
                    break;
                    // Mila, ab aage search karne ki zaroorat nahi
                }
            }
            int maxValue = -1; 
            // Default -1 rakha kyunki agar next greater na mile
            // to -1 return karna hai(problem statement ke according)

            for(int j = index + 1; j < nums2.size(); j++){
                // index ke aage se search karo
                // kyunki "next greater" strictly right side wala hi hota hai

                if(nums2[j] > nums2[index]){
                    maxValue = nums2[j];
                    break;
                    // First greater mila, aage dekhne ki zaroorat nahi
                    // (kyunki hame "next" chchaiye, "any" nahi)
                }
            }
            nums1[i] = maxValue;
            // nums1 ko in-place modify kar rahe hain
            // Isse extra memory nahi lagti(ourput ke alawa)
        }
        return nums1;
        // Modified nums1 hi answer hai
    }
};

/*

TC -> O(n1 x n2) -> O(n^2) | SC -> O(1) extra

This is not the optimal approach, monotonic stack se O(n1 + n2) me ho sakta hai
> Ek stack maintain karo jo strictly decreasing ho(top se bottom tak)
  Jab bhi ek naya element dikhta hai:
. Agar wo stack ke top se "bada" hai, matlab wo top wale ka "next greater" hai
. Pop kar do stack se, aur uska answer ye current element hai
Isse har element sirf ek baar push aur ek baar pop hota hai -> O(n)

eg. nums2 = [4, 1, 2]

Stack(empty) -> answer: {}
i = 0 -> stack empty
         push 4
         stack: [4]

i = 1 -> 1 < 4(top), no pop
         Push 1
         Stack: [4, 1]

i = 2 -> 2 > 1(top) -> 1 ka next greater = 2 -> pop 1, save answer: 1 -> 2
         2 < 4(new top), stop
         Push 2
         Stack: [4, 2]

End: Stack me jo bache(4,2) - unka next greater exist nahi karta -> -1

Answers map:
. 4 -> -1
. 1 -> 2
. 2 -> -1
Ab nums1 ke har element ke liye is map me dekh lo

Standard monotonic stack solution ke liye unordered_map chahiye

*/