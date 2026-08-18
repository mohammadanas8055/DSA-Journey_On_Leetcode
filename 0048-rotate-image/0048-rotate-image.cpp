class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int left = 0; // row maintain karna hai
        int right = n - 1; // column maintain karna hai
        int top = 0; // row maintain karna hai
        int bottom = n - 1; // column maintain karna hai
        while(left < right && top < bottom){
            int i = left;
            int j = top;
            int k = right;
            int l = bottom;
            while(i < right && j < bottom && k > left && l > top){
                int temp1 = matrix[top][i]; // (0,0)
                int temp2 = matrix[j][right]; // (0,2)
                int temp3 = matrix[bottom][k]; // (2,2)
                int temp4 = matrix[l][left]; //(2,0)
                matrix[top][i] = temp4;
                matrix[j][right] = temp1;
                matrix[bottom][k] = temp2;
                matrix[l][left] = temp3;
                i++;
                j++;
                k--;
                l--;
            }
            left++;
            top++;
            right--;
            bottom--;
        }
    }
};