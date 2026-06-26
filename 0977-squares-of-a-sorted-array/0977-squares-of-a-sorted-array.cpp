class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n);
        int i = 0; 
        int j = nums.size() - 1;
        int pos = nums.size() - 1;
        while(i <= j){
            int leftSquare = nums[i] * nums[i];
            int rightSquare = nums[j] * nums[j];
            if(leftSquare > rightSquare){
                result[pos] = leftSquare;
                i++;
            }
            else{
                result[pos] = rightSquare;
                j--;
            }
            pos--;
        }
        return result;
    }
};