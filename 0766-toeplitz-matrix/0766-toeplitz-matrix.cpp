class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size(); // Total rows in the matrix

        int n = matrix[0].size(); // Total columns in the matrix
                                  // Problem constraints ke according matrix empty nahi hai

        for(int i = 0; i < m - 1; i++){ // i ko m - 1 tak hi chala rahe hain
                                        // kyunki ham matrix[i + 1][...] access karenge 
                                        // Agar i last row tak chala gaya to i + 1 out-of-bounds ho jayega

            for(int j = 0; j < n - 1; j++){ // j ko n - 1 hi chala rahe hain
                                            // kyunki ham matrix[...][j + 1] access karenge
                                            // Agar j last column tak chala gaya to j + 1 invalid ho jayega

                if(matrix[i][j] != matrix[i + 1][j + 1]){ // Toeplitz property ke hisaab se
                                                          // har element apne bottom-right diagonal neighbour ke equal hona chahiye
                                                          // Agar ek bhi mismatch mila, matrix Toeplitz nahi hai

                    return false;
                }
            }
        }
        return true; 
        // Agar poori matrix me kahin mismatch nahi mila
        // to har diagonal valid hai
    }
};

/*

TC -> O(m * n) | SC -> O(1)

*/

// now considering the follow up questions

/*

Follow-up 1: Matrix disk par stored hai, memory me sirf ek row at a time load kar sakte hain

Previous row load karo -> current row load karo -> compare current[j] == previous[j -1] for j = 0 to n - 1 (Current row ka element previous row ke ek position left wale element ke equal hona chahiye)

class Solution{
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix){
        int m = matrix.size();
        int n = matrix[0].size();

        vector<int> previousRow = matrix[0]; // pehli row ko previous row ki tarah store kar liya
                                             // Real scenario me ye disk se load karna represent karta hai

        for(int i = 1; i < m; i++){ // Row 1 se start kar rahe hain
                                    // kyunki row 0 already previous row ke roop me stored hai

            vector<int> currentRow = matrix[i]; // current row ko disk se load kiya(simulate)
                                                // Real scenario me disk I/O hoga

            for(int j = 1; j < n; j++){ // j = 1 se start kiya 
                                        // kyunki j = 0 ke liye j - 1 = - 1 invalid ho jayega
                                        // Also, column 0 ke elements ko previous row se compare karne ki zaroorat nahi hai
                                        // Unke diagonal neighbour previous row me exist hi nahi karte

                if(currentRow[j] != previousRow[j - 1]){ // Toeplitz property:
                                                         // current[j] should equal previous[j - 1]
                                                         // Agar nahi hai, matrix toeplitz nahi hai

                    return false;
                }
            }
            previousRow = currentRow; // Current row ab next iteration ke liye previous row ban jayegi
                                      // Memory me sirf ek row stored rehti hai at a time

        }
        return true; // Saari rows process ho gayin bina mismatch ke
                     // Matrix Toeplitz hai
    }
};

TC -> O(m * n) | SC -> O(n)

*/

/*

Follow-up 2: Memory bahut limited hai. Ek poori row bhi load nahi kar sakte. Sirf k elements at a time load kar sakte ho

Rows ko chunks me process karo -> Har chunk ke liye previous row ka corresponging shifted chunk chahiye -> Overlap element handle karo
Let's assume chunk size = k

class Solution{
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix){
        int m = matrix.size();
        int n = matrix[0]. size();
        int k = 2; // k = chunk size
                   // Real scenario me ye memory constraint se decide hoga
                   // Example ke liye k = 2

                   // Previous row ka first chunk load karenge
                   // overlap ke liye ek extra element bhi store karenge

        for(int i = 1; i < m; i++){ // Har row ke liye

            for(int chunkStart = 0; chunkStart < n; chunkStart = chunkStart + k){ // Rows ko chunk me process kar rahe hain
                             // Har chunk [chunkStart, chunkStart + k - 1] tak hai
            
                int chunkEnd = min(chunkStart + k - 1, n - 1); // Last chunk chota ho sakta hai, agar n, k se divisible na ho

                for(int j = chunkStart; j <= chunkEnd; j++){ // current chunk ke har element ke liye 

                    if(j == 0){
                        continue; // j = 0 ke liye j - 1 = -1 invalid
                                  // Column 0 ke elements ka diagonal neighbour previous row me nahi hai
                    }

                    // Toeplitz check: 
                    // current row ka j-th element == previous row ka (j - 1)-th element
                    if(matrix[i][j] != matrix[i - 1][j - 1]){
                        return false;
                    }
                }
            }
        }
        return true;
    }
};

Here we are still accessing matrix[i][j] & matrix[i - 1][j - 1] directly because it's a simulation
I real disk-based system, flow would be
Load chunk[L,R] from current row -> load chunk[L-1,R-1] from previous row -> compare element by element -> move to next chunk

TC -> O(m * n) | SC -> O(k)

*/