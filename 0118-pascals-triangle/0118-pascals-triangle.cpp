class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> result; // empty 2D vector result(each inner vector is a row)
        // Now we need to build each row and add it

        // 2D vectors can also be initialised 
        // eg 1. vector<vector<int>> grid(rows, vector<int>(cols, 0));
                 // Creates rows × cols 2D vector, all zeros

        // eg 2. vector<vector<int>> grid(3, vector<int>(4, 1));
                 // 3 rows, 4 columns, all 1s
        

        for(int i = 0; i < numRows; i++){
            vector<int> row(i + 1, 1); // make a 1D vector of size i + 1 (because i starts from 0, and there are i + 1 elements in each row) initialised with 0(we can't initialise a vector with = after specifying size)
            // we CAN initialise it in this way
            // vector<int> (size, value);

            // (first element is always 1) // don't insert 1, it adds another element 1
            // we can remove the assignment if we INITIALISE the vector with 1 -> ALL elements will be 1, middle ones will be replaced by the upcoming loop, and 1st and last would remain 1 

            
            // This is for the middle elements -> excluding row[0] and row[i] , everyone else, row[1] to row[i - 1]
            for(int j = 1; j < i; j++){ 
                row[j] = result[i - 1][j - 1] + result[i - 1][j];
            } // current row ke middle elements kaise aa rahe hain -> pichli row(result me jo saved hai)[result(i - 1)] -> uske pichle element(j - 1) aur same index(j) element se
            // unhen access karne ke liye result[i - 1][index]


            // (last element is always 1, i is the row index, also the last element)
            // similarly here, no need to for assignment of 1, if vector is initialised with 1 


            result.push_back(row); // Add elements to END of vector, v.insert(v.end(), x) and v.push_back(row) do the same thing
            // puch_back is just more readable and shorter

            // Here we are adding a whole vector(rows)

        }
        return result;
    }
};

/*

Time complexity -> O(numRows^2)
Space complexity -> O(numRows^2)

Other related function:
v.pop_back();          // Remove LAST element (O(1))
v.back();              // Get LAST element (without removing)
v.front();             // Get FIRST element
v.size();              // Get number of elements
v.empty();             // Returns true if no elements
v.clear();             // Remove ALL elements

"Building 2D structure where each element depends on previous elements"

Used in:

Pascal's Triangle ✅
Many Dynamic Programming problems
Matrix-based DP

*/