class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int sum = 0;
        // Final diagonal sum store karega

        int n = mat.size();
        // Matrix square hai, isliye rows = columns = n

        for(int i = 0; i < n; i++){
            sum = sum + mat[i][i];
            // Primary diagonal add ki:
            // Positions are (0,0), (1,1), (2,2), ...

            if(i != n - i - 1){ // Ensuring that the middle element in a odd no. nxn matrix does not gets added twice
                sum = sum + mat[i][n - i - 1];
                // Secondary diagonal add ki:
                // Positions are (0, n - 1), (1, n - 2), (2, n - 3), ....

                // Consition usliye lagayi hai taaki middle element odd-sized matrix me do baar add na ho
            }
       }

       return sum;
       // Dono diagonals ka final sum return kar diya
    }
};

/*

Primary diagonal is top-left to bottom-right
mat[0][0], mat[1][1], mat[2][2]
row == column
so mat[i][i] are the primary diagonal elements 

Secondary diagonal is top-right to bottom-left
mat[0][2], mat[1][1], mat[2][0]
row increase, column decrease

n = mat.size() = 3
last index = n - 1 = 2
row 0 -> column 2 -> 2 - 0
row 1 -> column 1 -> 2 - 1
row 2 -> column 0 -> 2 - 2
therefore column is lastIndex - row
                    n - 1 - i

therefore secondary diagonal element for row i is mat[i][n - i - 1]

if primary and secondary diagonal are not pointing to the same cell, then add secondary.

Primary diagonal:
row == col
mat[i][i]

Secondary diagonal:
row + col == n - 1
mat[i][n - 1 - i]

TC -> O(n) (Even though the matrix has n*n elements, we are not visiting all of them) | SC -> O(1)

*/