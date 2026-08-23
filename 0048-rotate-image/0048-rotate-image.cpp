class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        // n = matrix ki dimension(square matrix hai)

        int left = 0; 
        // current layer ka leftmost column
        
        int right = n - 1; 
        // current layer ka rightmost column

        int top = 0; 
        // current layer ka topmost row

        int bottom = n - 1; 
        // current layer ka bottommost row
        
        // Ye variables ek "ring" ya "layer" define karte hain
        // Har iteration me outer ring rotate hoti hai, phir inner ring pe move karte hain

        while(left < right && top < bottom){
            // Ye outer loop layer level pe hai
            // Jab tak valid ring exist karti hai(kam se kam 2 x 2 area), rotate karo

            //< use kiya (not <=) kyunki agar left == right ya top == bottom hote
            // to layer denegerate ho jaati(single row/column) - rotate karne ka matlab nahi

            int i = left;
            // Ye top row me traverse karega left se right

            int j = top;
            // Ye right column me traverse karega top se bottom 

            int k = right;
            // Ye bottom row me traverse karega right se left 

            int l = bottom;
            // Ye left column me traverse karega bottom se top 

            while(i < right && j < bottom && k > left && l > top){
                // Ye inner loop layer ke andar 4 elements ek saath rotate karta hai 
                // Har iteration me 4 corners simultaneously swap hote hain 

                // Conditions saari 4 pointers ki bounds check kar rahi hain
                // Jaise hi koi boundary tak pahunche, layer complete ho gayi

                int temp1 = matrix[top][i];
                // Top row ka current element

                int temp2 = matrix[j][right]; 
                // Right column ka current element

                int temp3 = matrix[bottom][k];
                // Bottom row ka current element
                
                int temp4 = matrix[l][left]; 
                // Left column ka current element 

                // 4 temps save kar rahe hain kyunki cyclic rotation me
                // agar seedha assign kiya to values lose ho jayengi

                // 90° clockwise rotation:
                // Top -> Right, Right -> Bottom, Buttom -> Left, Left -> Top
                matrix[top][i] = temp4; 
                // Left ka element top me
                
                matrix[j][right] = temp1;
                // Top ka element right me
                
                matrix[bottom][k] = temp2;
                // Right ka element bottom me
                
                matrix[l][left] = temp3;
                // Bottom ka element left me

                i++;
                // Top pointer aage

                j++;
                // Right pointer neeche
                
                k--;
                // Bottom pointer piche

                l--;
                // Left pointer upar

                // har pointer apni respective direction me move karta hai
                // clockwise rotation ke natural direction ke saath
            }

            // Ek layer complete - ab andar wali layer pe move karo
            left++;
            top++;
            right--;
            bottom--;
        }  
    }
};

/*

TC -> O(n^2) | SC -> O(1) 

Alternative: Transpose + Reverse rows
This layer-by-layer method was longer, harder because of boundary conditions and has geometric intuition
Transpose + Reverse is shorter, easier and has mathematical intuition

*/

/* 

// STEP 1: TRANSPOSE the matrix
// Transpose ka matlab: matrix[i][j] aur matrix[j][i] swap karo
// Yani main diagonal ke across flip karo

// Example:
// 1 2 3        1 4 7
// 4 5 6   ->   2 5 8
// 7 8 9        3 6 9

// Notice main diagonal(1,5,9) apni jagah stay karta hai
// Baaki elements diagonal ke opposite side me chale jaate hain
for(int i = 0; i < n; i++){
    for(int j = i + 1; j < n; j++){
        // IMPORTANT: j = i + 1 se start kiya, j = 0 se nahi

        // Kyun?
        // Agar j = 0 se start karte, to ham har pair ko DO baar swap karte
        // Example: matrix[0][1] aur matrix[1][0] swap
        // Phiw wapas matrix[1][0] aur matrix[0][1] swap = back to ORIGINAL!

        // j = i + 1 se start karke ham sirf UPPER TRIANGLE traverse karte hain(diagonal ke upar wala hissa)
        // Har pair sirf ek baar swap hota hai

        // Aur diagonal elements(i == j) khud ke saath swap karne ki zaroorat nahi

        swap(matrix[i][j], matrix[j][i]);
        // In-place swap karta hai(elements ki position exchange)
        // Standard C++ library function, O(1) time
    }
}

// STEP 2: REVERSE each row
// Transpose ke baad matrix aisi ho gayi:
// 1 4 7
// 2 5 8
// 3 6 9

// Ab har row ko reverse karo:
// 1 4 7      7 4 1
// 2 5 8  ->  8 5 2
// 3 6 9      9 6 3

// Final result - original ka 90°  clockwise rotation!

for(int i = 0; i < n; i++){
    reverse(matrix[i].begin(), matrix[i].end());
    // reverse() ek STL function hai jo container ke elements ulte kar deta hai
    // matrix[i] ek row hai (vector<int>)
    // matrix[i].begin() = row ka start iterator
    // matrix[i].end() = row ka end iterator(last element ke ek baad)

    // Ye in-place reverse karta hai, O(n) per row
}

// Total: n rows x O(n) reverse each = O(n^2)
// Plus transpose = O(n^2) (n*(n - 1)/2 swaps)
// Grand total = O(n^2), which is optimal

*/

/*

TC -> O(n^2) | SC -> O(1)

*/