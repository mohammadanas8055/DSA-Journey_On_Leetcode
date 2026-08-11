/*

Brute Force me [1,n] me check karenge nums me kon sa present hai, then pop_back, nahi hai to dusri array me save karke pop_back -> TLE aa jayega 

Better approach(O(n) TC, O(n) SC)
frequency or boolean array(of size n, index 0 to n - 1) bana ke(all false), us array ke nums[i] - 1 index ko true kar do jo jo elements nums me ho
phir seen array par loop laga ke, false walon se i + 1 collect karke return karwa den

This trick can be extended to O(1) extra space
All elements of nums are in the range [1,n] -> yaani numbers aur array ke indices(0 to n - 1) ke beech me ek direct connection hai
. Number 1 ko index 0 pe hona chahiye
. Number 2 ko index 1 pe hona chahiye
.
.
. Number x ko index x - 1 pe hona chahiye

Ham original array nums ko hi as a Notebok/Tracker use karenge 
jo number mile, uske respective index(ghar) pe jaake wahan ka number negative kar do bas(agar pehle se negative hai to chor do) -> yani agar number positive hai, to use negative kar do
aur har number ka absolute value lo, to array change karte hue bhi sahi elements use ho rahe hain nums ke
phir se nums dekh ke, jo positive reh gaya, yaani iska maalik(index + 1) kabhi ghar aaya hi nahi
Wahi number missing hai

This is known as State Encoding
Not only numbers are given, but array ke indices khud apne aap me ek information hain
nums array as input to kaam kar hi raha hai, par negative sign ue karke hamne usi array ko "boolean seen array" ki tarah reuse bhi kar liya

*/

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        // Step 1: Marking process
        // Array ko left se right scan karenge
        // Jo bhi number miega, uske corresponding index par jaakar wahan ke number ko negative kar denge
        // Negative hone ka matlab: "Ye index jiska ghar hai, wo number array me exist karta hai"

        for(int i = 0; i < nums.size(); i++){

            // Number pehle kisi aur step me negative ho chuka ho sakta hai
            // Isliye ham hamesha uska absolute(positive) value nikalte hain
            // abs(nums[i]) bhi use kar sakte hain, par manual checking bhi thik hai
            int num = nums[i];
            if(num < 0){
                num *= -1;
            }

            // Value 'num' ka ghar kis index par hai?
            // 1-based array hai(1 to N), par indexing 0-based hoti hain
            // toh num ka index hoga (num - 1)
            int index = num - 1;

            // Us index par jao. Agar wahan positive value hai, to use negative bana do
            // Agar pehle se negative hai(yani duplicate number tha), to kuch mat karo
            if(nums[index] > 0){
                nums[index] *= -1;
            }
        }

        // Step 2: Finding Missing Numbers
        vector<int> ans;

        for(int i = 0; i < nums.size(); i++){
            // Pura array check karo
            // Agar kisi index 'i' par value abhi bhi POSITIVE hai
            // iska matlab wahan koi number aaya hi nahi tha mark karne
            // iska matlab (i + 1) number array me MISSING hai
            if(nums[i] > 0){
                ans.push_back(i + 1);
            }
        }
        return ans;
        // Missing numbers list return kar di
    }
};

/*

TC -> O(n) | SC -> O(1) (No extra array, except answer array)

*/