class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        int m = mat.size(); // Original matrix ki total rows

        int n = mat[0].size(); // Original matrix ki total columns
                               // problem constraints ke according matrix empty nahi hai

        if(m * n != r * c){ // Reshape tabhi possible hai jab total elements same rahen
            return mat; // Agar count same nahi hai, to requested shape impossible hai
        }

        int row = 0;
        int col = 0;
        // Ye pointers new reshaped matric me current position track karenge
        // row = current row in answer
        // col = current column in answer

        vector<vector<int>> ans(r, vector<int>(c)); // new matrix preallocate kar di, required dimensions ke saath
                                                    // push_backuse nahi kiya, kyunki final size already pata hai

        for(int i = 0; i < m; i++){ // original matrix ke rows traverse kar rahe hain
            for(int j = 0; j < n; j++){ // original matrix ke columns traverse kar rahe hain
                                        // isse elements original row-major order me milte rahenge

                if(col == c){
                    row++;
                    col = 0;
                    // Agar current row full ho gayi
                    // to next row par jao aur column ko 0 se restart karo
                }
                ans[row][col] = mat[i][j]; // original matrix ka current element
                                           // reshaped matric ke current tracked position par store kar diya

                col++; // Next element answer matrix ke next column me jayega
            }
        }
        return ans; // successfully reshaped matrix return kar di
    }
};

/*

TC -> O(m * n) | SC -> O(r * c)

*/