class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int i = 0; // Left pointer smallest element se start karega

        int j = numbers.size() - 1; // Right pointer largest element se start karega
        
        while(i < j){ // jab tak pointers cross nahi karte
                      // tab tak valid pair possible hai

            int sum = numbers[i] + numbers[j]; // Current left + right values ka sum nikaala 

            if(sum == target){
                return {i + 1, j + 1}; // this means create a vector containing these values and return it
                                       // problem is 1-based indexing -> i + 1 and j + 1 return
            }
            if(sum > target){
                j--; // sum zyada aa gaya
                     // array sorted hai, isliye bada element right side par hai
                     // sum ko kam karne ke liye right pointer ko left move karo
            }
            else{ // sum < target
                i++; // sum chota hai, isliye left pointer ko right move karo
                     // taaki larger number mile aur sum badhe
            }
        }
        return {}; // short form of return vector<int>(); -> empty vector
                   // or vector<int> {};
                   // it needs to be written because function must return a vector<int> in all cases
                   // But Leetcode guarantees exactly one solution, so practically code returns inside if(sum == target)
                   // so this line never executes
                   // so return {} is just a fallback to complete the function
                   // because compiler expects that every control path returns a vector<int>
    }
};

/*

return (); -> empty vector
return {a, b}; -> vector with 2 elements
Known as Initializer List Style

> 2-pointer logic works because array is sorted

If sum is too big:
To reduce sum, move the right pointer left(j--), because sorted array me right side par bigger values hote hain

If sum is too small:
To increase sum, move the left pointer right(i++)

TC -> O(n) | SC -> O(1)

*/