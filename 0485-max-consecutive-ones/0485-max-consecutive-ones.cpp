class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int count = 0;
        // count current running streak of consecutive 1s store karega
        // Jaise hi 0 milega, current steak toot jayegi

        int maxCount = 0;
        // maxCount ab tak ki sabse badi streak store karega

        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == 1){
                count++;
                // Agar current element 1 hai
                // to consecutive streak ek aur badh gayi

                maxCount = max(maxCount, count);
                // Har baar streak badhne par check kar lo
                // kya ye ab tak ki sabse badi streak ban gayi hai

                // Ye line yahin isliye rakhi hai because
                // streak sirf tabhi meaningful hoti hai jab current element 1 ho
            }
            else{
                count = 0;
                // Agar 0 mil gaya to current consecutive streak break ho gayi
                // Ab next 1 se nayi streak start hogi
            }
        }
        return maxCount;
        // Puri array me maximum consecutive 1s ki streak return kar di
    }
};

/*

TC -> O(n) | SC -> O(1)

*/