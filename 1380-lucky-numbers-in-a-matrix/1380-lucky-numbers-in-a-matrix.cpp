// class Solution {
// public:
//     vector<int> luckyNumbers(vector<vector<int>>& matrix) {
//         vector<int> lucky;
//         // Final lucky numbers store karne ke liye
        
//         for(int i = 0; i < matrix.size(); i++){
//             // Step 1: Current row ka minimum find karo

//             int minimum = matrix[i][0];
//             int minCol = 0;
//             // Assume kar liya ki row ka pehla element hi minimum hai

//             for(int j = 1; j < matrix[i].size(); j++){
//                 if(minimum > matrix[i][j]){
//                     minimum = matrix[i][j];
//                     minCol = j;
//                     // Agar aur chhota element mil gaya
//                     // To minimum aur uska column index update kar diya
//                 }
//             }

//             // Step 2: check karo ki kua ye minimum
//             // apni column me maximum bhi hai
//             bool isLucky = true;
//             for(int k = 0; k < matrix.size(); k++){
//                 if(matrix[k][minCol] > minimum){
//                     isLucky = false;
//                     break; // Once a bigger element is found, it is already proven not lucky. No need to check the rest of the column
//                 }
//             }
//             if(isLucky){
//                 lucky.push_back(minimum);
//                 // dono conditions satisfy hui:
//                 // row me minimum aur column me maximum
//             }
//         }
//         return lucky;
//     }
// };

/*

TC -> For each of the m rows: row scan(Finding minimum) = O(n), column scan(checking column) = O(m) -> O(m * (n + m)) | SC -> O(n) (O(1) excluding answer vector)

*/

/*

Approach 2:
Precompute Row Minimums + Column Maximums-
TC -> O(m * n) | SC -> O(m + n)
Time optimal but not space optimal

*/

/*

Approach 3:
Observation based-
row minimum hona hai, column maximum
So, lucky numbers agar exist karta hai 
to
maximum among all row minimums and also minimum among all column maximums

Why?
row minimums me se chote wale candidates weak hote hain
lucky banne ke liye row-min value ko as large as possible hona chahiye
similarly column maximums me se lucky ko as small as possible hona chahiye

max(row minimums) vs min(column maximums) -> if equal -> lucky number exists

*/

class Solution{
public:
    vector<int> luckyNumbers(vector<vector<int>>& matrix){
        int m = matrix.size();
        int n = matrix[0].size();
        int maximumAmongRowMinimum = INT_MIN;
        for(int i = 0; i < m; i++){
            int minRow = matrix[i][0];
            for(int j = 0; j < n; j++){
                minRow = min(minRow, matrix[i][j]);
            }
            maximumAmongRowMinimum = max(maximumAmongRowMinimum, minRow);
        }
        int minimumAmongColumnMaximum = INT_MAX;
        for(int i = 0; i < n; i++){
            int maxCol = matrix[0][i];
            for(int j = 0; j < m; j++){
                maxCol = max(maxCol, matrix[j][i]);
            }
            minimumAmongColumnMaximum = min(minimumAmongColumnMaximum, maxCol);
        }
        if(maximumAmongRowMinimum == minimumAmongColumnMaximum){
            return {minimumAmongColumnMaximum};
        }
        return {};
    }
};
