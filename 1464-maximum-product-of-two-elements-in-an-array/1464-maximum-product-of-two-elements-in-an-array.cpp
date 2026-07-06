class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxProduct = 1;
        int product;
        int maxIindex;
        int maxJindex;
        for(int i = 0; i < nums.size() - 1; i++){
            for(int j = i + 1; j < nums.size(); j++){
                product = nums[i] * nums[j];
                if(product >= maxProduct){
                    maxProduct = product;
                    maxIindex = i;
                    maxJindex = j;
                }
            }
        }
        int maximum = (nums[maxIindex] - 1) * (nums[maxJindex] - 1);
        return maximum;
    }
};