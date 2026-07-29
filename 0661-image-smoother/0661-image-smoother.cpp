class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        int m = img.size();
        int n = img[0].size();
        vector<vector<int>> result(m, vector<int>(n));
        
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                int sum = 0;
                int count = 0;
                for(int dr = -1; dr <= 1; dr++){
                    for(int dc = -1; dc <= 1; dc++){
                        int newRow = i + dr;
                        int newCol = j + dc;
                        if((0 <= newRow) && (newRow < m) && (0 <= newCol) && (newCol < n)){
                            sum += img[newRow][newCol];
                            count++;
                        }
                    }
                }
                result[i][j] = sum / count;
            }
        }
        return result;
    }
};