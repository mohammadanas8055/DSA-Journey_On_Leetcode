// class Solution {
// public:
//     int numSpecial(vector<vector<int>>& mat) {
//         int col;
//         int totalCount = 0;
//         int count;
//         for(int i = 0; i < mat.size(); i++){
//             count = 0;
//             for(int j = 0; j < mat[0].size(); j++){
//                 if(mat[i][j] == 1){
//                     count++;
//                     col = j;
//                 }
//             }
//             if(count == 1){
//                 for(int k = 0; k < mat.size(); k++){
//                     if(k != i && mat[k][col] == 1){
//                         count--;
//                         break;
//                     }
//                 }
//             }
//             if(count == 1){
//                 totalCount++;
//             }
//         }
//         return totalCount;
//     }
// };

class Solution{
public:
    int numSpecial(vector<vector<int>>& mat){
        int m = mat.size();
        int n = mat[0].size();
        int count = 0;
        vector<int> rowCount(m, 0);
        vector<int> colCount(n, 0);
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(mat[i][j] == 1){
                    rowCount[i]++;
                    colCount[j]++;
                }
            }
        }
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(mat[i][j] == 1 && rowCount[i] == 1 && colCount[j] == 1){
                    count++;
                }
            }
        }
        return count;
    }
};