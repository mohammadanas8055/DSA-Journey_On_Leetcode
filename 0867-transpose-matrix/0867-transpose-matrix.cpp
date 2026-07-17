// class Solution {
// public:
//     vector<vector<int>> transpose(vector<vector<int>>& matrix) {
//         vector<vector<int>> mat;
//         for(int i = 0; i < matrix[0].size(); i++){ // original matrix ke columns traverse kar raha hai
//             vector<int> row;
//             for(int j = 0; j < matrix.size(); j++){
//                 row.push_back(matrix[j][i]);
//             }
//             mat.push_back(row);
//         }
//         return mat;
//     }
// };

/*

Transpose means:
original matrix[i][j] becomes answer[j][i]

TC -> O(rows*cols) | SC -> O(rows*cols)

But using push_back -> it starts with a small capacity
Also inner loop accesses matrix[j][i] -> row index is changing while column index stays the same
Now, in C++, matrices are stored in Row-Major order
Accessing matrix[0][0], then matrix[1][0], then matrix[2][0] forces the CPU to jump across different memory blocks(cache misses) 
Accessing matrix[0][0], then matrix[0][1], then matrix[0][2] is much faster because they sit next to each other in memory.

So we should pre-allocate memory(because we know it) and also try to read the input matrix row-by-row

So whenever we know the final size of a vector, always pre-size it or use .reserve()

*/

class Solution{
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix){
        int row = matrix.size(); // Original matrix me number of rows
        int col = matrix[0].size(); // Original matrix me number of columns
                                    // Matrix is not empty(according to constraints), so matrix[0] access safe hai

        vector<vector<int>> answer(col, vector<int>(row)); // transpose me dimension ulat jaati hain                            
                                                           // original = row * col
                                                           // answer = col * row
                                                           // col -> number of rows in answer matrix
                                                           // vector<int>(row) -> har row me kya rahega(1D vector with the size of row(of original matrix))

        for(int i = 0; i < row; i++){ // i traverses original matrix ki rows
            for(int j = 0; j < col; j++){ // j current row ke columns ko traverse kar raha hai
                answer[j][i] = matrix[i][j]; // Main rule of transpose -> original matrix[i][j] -> answer[j][i]
                                             // original ka row index column ban raha hai aur column index row ban raha hai
            }
        }
        return answer;
    }
};

/*

TC -> O(row * col) | SC -> O(row * col)

*/