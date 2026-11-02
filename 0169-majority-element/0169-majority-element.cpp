class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count = 0;
        int majority = nums[0]; // initialize with first element (safe, n >= 1)
        int n = nums.size();
        for(int i = 0; i < n; i++){
            if(count == 0){
                majority = nums[i]; // new candidate when previous is fully cancelled
            }
            if(nums[i] == majority){
                count++; // vote FOR current candidate
            }
            else{
                count--; // vote AGAINST - cancels one vote of current candidate
            }
        }
        return majority;
    }
};

/*

TC -> O(n) | SC -> O(1)

*/