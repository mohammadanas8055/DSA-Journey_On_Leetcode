class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> ans;
        // Final duplicate numbers store karne ke liye

        for(int i = 0; i < nums.size(); i++){
            int num = nums[i];
            // Current element read kiya
            // Ye pehle kisi step me negative mark ho chuka ho sakta hai

            if(num < 0){
                num *= -1;
            }
            // Absilute value nikaal li
            // Kyunki sign ko ham sirf "visited" marker ki tarah use kar rahe hain
            // actual number ki identity positive value se hi samajh payenge

            int index = num - 1;
            // Number num ka "home index" hai num - 1
            // Kyunki values range [1,n] me hain
            // aur indices range [0,n - 1] me hoti hai

            if(nums[index] < 0){
                // Agar home index par value already negative hai
                // matlab ye number pehle bhi mil chuka hai
                // Isliye current num duplicate hai(na ki nums[i], kyunki wo negative ho sakta hai
                
                ans.push_back(num);
            }
            else{
                // Agar home index par value abhi positive hai
                // matlab ye number first time mila hai
                // Isliye use negative karke mark kar do

                nums[index] *= -1;
            }
        }
        return ans;
        // Saare duplicates return kar diye
    }
};

/*

Logic is fragile in this code
We are first flipping the sign, then decide whether duplicate tha ya nahi
This ia backwards from the usual safe logic. It's working here because each number appears once or twixe
pehle positive hai -> multiply by -1 -> it becomes negative -> nums[index] > 0 false -> so not duplicate yet 
Phir dusri baar aaya agar x -> nums[index] negative -> multiply by -1 -> positive -> duplicate checked
So under "appears once or twice" constraint, this works
But since we made it positive -> "marked information is lost" 
If, hypothetically, same number appeared 3 times -> negative again -> now duplicate detection breaks

So first check, then mark. Instead of first mark, then check
FIRST CHECK: if(nums[index] < 0) means: kya is number ka ghar pehle se marked hai?
If YES: duplicate
If NO: first time seen, mark negative

TC -> O(n) | SC -> O(1) extra space

Same negative-marking family problem as LC 448

Common idea:
Number x belongs to index x - 1 because values are in range [1,n]
We use the sign of nums[x - 1] as a visited marker

If nums[x - 1] is positive:
-> first time x appeared, mark t negative

If nums[x - 1] is already negative:
-> x has appeared before

Difference:
LC 448 -> finally jo indices positive bache, unke numbers missing hain
LC 442 -> agar home index already negative mila, current number duplicate hai

*/
