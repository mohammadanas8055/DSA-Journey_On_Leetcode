class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        vector<int> frequency(101);
        // frequency[x] batayega ki number x ab tak kitni baar dikha
        // Size 101 rakhi kyunki problem constraint ke according
        // nums[i] ki value 1 se 100 tak ho sakti hai(index 100 ko safely access karne ke liye)

        // vector<int>(101) automatic zero-initialize karta hai
        // C-style int frequency[101] galat hota kyunki wo garbage se bhari hoti 

        int pairs = 0;
        // Total good pairs count karega

        for(int i = 0; i < nums.size(); i++){
            
            pairs += frequency[nums[i]];
            // Current number nums[i] ab tak kitni baar aa chuka hai?
            // Utne hi naye good pairs ban jayenge current index ke saath

            // Example: agar 1 pehle 2 baar aa chuka hai
            // aur ab teesri baar aaya hai, to 2 naye pairs ban jayenge
            // (current 1 with each previous 1)

            frequency[nums[i]]++;
            // Ab current number ki frequency ko badha diya
            // Taaki agla same number aaye to ye bhi count ho

            // Important: pairs update pehle, frequency update baad me
            // Warna current khud ke saath pair ho jayega(galat)
        }
        return pairs;
        // Total good pairs return kar diya
    }
};

/*

Stand on a number and see how many times the same number appeared BEFORE that position

arr[x] stores: how many times number x has appeared before current index
Inputs were 1 to 100 , so made 101 boxes(0 to 100 indexed) for counting how many times a number has appeared before

So pehle usko 0 se initialize karna hoga 
int frequency[101] = {}; OR int frequency[101] = {0}; OR vector<int> frequency(101,0); OR vector<int> frequency(101);

If current number appeared before k times, then k new pairs
Phir current number ka count badha diya for future elements

TC -> O(n) | SC -> O(1) because freq[101] is fixed size

Pattern:
frequency count with fixed-size array

Here we used frequency while scanning, instead of checking at the end(in case of Valid Anagram)

*/