class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int count = 0;
        int maxCount = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == 1){
                count++;
                if(count > maxCount){ // Updates count only when the streak grows
                    maxCount = count;
                }
            }
            else{
                count = 0;
            }
            
        }
        return maxCount;
    }
};

/*

Time complexity -> O(n)
Space complexity -> O(1)

Consecutive ones ko add kiya, jaise hi 0 mila to usko break kar diya, agar usse zyada kahin 1 mil gaye to us pichle wale count ko replace kar diya

Could also write 
maxCount = max(count, maxCount);

*/