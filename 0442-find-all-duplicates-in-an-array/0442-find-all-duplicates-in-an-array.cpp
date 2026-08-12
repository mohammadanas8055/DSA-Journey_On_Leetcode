class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> ans;
        for(int i = 0; i < nums.size(); i++){
            int num = nums[i];
            if(num < 0){
                num *= -1;
            }
            int index = num - 1;
            if(nums[index] < 0){
                ans.push_back(num);
            }
            else{
                nums[index] *= -1;
            }
        }
        return ans;
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

*/