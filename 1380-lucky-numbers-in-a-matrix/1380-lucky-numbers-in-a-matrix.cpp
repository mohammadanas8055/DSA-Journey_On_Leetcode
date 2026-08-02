class Solution {
public:
    vector<int> luckyNumbers(vector<vector<int>>& matrix) {
        vector<int> lucky;
        
        for(int i = 0; i < matrix.size(); i++){
            int minimum = matrix[i][0];
            int minCol = 0;
            for(int j = 1; j < matrix[i].size(); j++){
                if(minimum > matrix[i][j]){
                    minimum = matrix[i][j];
                    minCol = j;
                }
            }
            bool isLucky = true;
            for(int k = 0; k < matrix.size(); k++){
                if(matrix[k][minCol] > minimum){
                    isLucky = false;
                }
            }
            if(isLucky){
                lucky.push_back(minimum);
            }
        }
        return lucky;
    }
};