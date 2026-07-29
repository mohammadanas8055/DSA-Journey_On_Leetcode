class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int largest = max(nums[0], nums[1]);
        int secondLargest = min(nums[0], nums[1]);
        for(int i = 2; i < nums.size(); i++){
            if(nums[i] > largest){
                secondLargest = largest;
                largest = nums[i];
            }
            else if(nums[i] > secondLargest){
                secondLargest = nums[i];
            }
        }
        return (largest - 1) * (secondLargest - 1);
    }
};