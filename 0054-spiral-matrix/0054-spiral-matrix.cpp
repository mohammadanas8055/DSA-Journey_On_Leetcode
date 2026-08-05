class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> ans;
        int top = 0;
        int left = 0;
        int bottom = m - 1;
        int right = n - 1;
        while(top <= bottom && left <= right){
            int i = left;
            while(i <= right){
                ans.push_back(matrix[top][i]);
                i++;
            }
            top++;

            int j = top;
            while(j <= bottom){
                ans.push_back(matrix[j][right]);
                j++;
            }
            right--;

            if(top <= bottom){
                int k = right;
                while(k >= left){
                    ans.push_back(matrix[bottom][k]);
                    k--;
                }
                bottom--;
            }
            if(left <= right){
                int l = bottom;
                while(l >= top){
                    ans.push_back(matrix[l][left]);
                    l--;
                }
                left++;
            }
        }
        return ans;
    }
};