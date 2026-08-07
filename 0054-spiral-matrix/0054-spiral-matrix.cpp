class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size();
        // Total rows in matrix

        int n = matrix[0].size();
        // Total columns in matrix

        vector<int> ans;
        // Answer store karne ke liye
        // push_back use kiya taaki manually position track na karna pade

        int top = 0;
        int left = 0;
        int bottom = m - 1;
        int right = n - 1;
        // Ye 4 boundaries current "Unvisited rectangle" ko define karti hain

        // Initially poori matrix unvisited hai
        // top row = 0, bottom row = m - 1
        // left col = 0, right col = n - 1
        
        while(top <= bottom && left <= right){
            // jab tak kuch unvisited area bacha hai, tab tak spiral chalega
            // Agar boundaries cross kar gayi(top > bottom ya left > right)
            // matlab saare elements process ho chuke

            // ------STEP 1: Top row, left to right------
            int i = left;
            while(i <= right){
                ans.push_back(matrix[top][i]);
                i++;
                // Top row(fixed) ke saare elements left se right tak(variable i) add kiye
            }
            top++;
            // Top row complete ho gayi
            // Ab ye row visited hai, isliye boundary neeche le aaye
            // Ab andar wali rectangle ke liye top row ek niche hogi

            // -----STEP 2: Right column, top to bottom------
            int j = top;
            while(j <= bottom){
                ans.push_back(matrix[j][right]);
                j++;
                // Right column(fixed) ke saare elements top se bottom tak (variable j) add kiye
                // Column fixed hai(right), row change ho rahi hai
            }
            right--;
            // Right column complete ho gayi
            // Ab ye column visited hai, isliye boundary ek left le aaye

            // ------STEP 3: Bottom row, right to left-----
            // Ye tabhi valid hai jab abhi bhi bottom row bachi ho
            // Agar top > bottom ho gaya, matlab already pura traverse ho chuka
            if(top <= bottom){
                int k = right;
                while(k >= left){
                    ans.push_back(matrix[bottom][k]);
                    k--;
                    // Bottom row(fixed) ke saare elemens right se left(variable k) add kiye
                }
                bottom--;
                // Bottom row complete ho gayi
                // Boundary ek upar le aaye
            }

            // ------STEP 4: Left column, bottom to top------
            // Ye tabhi valid hai jab abhi bhi koi left column bachi ho
            // Agar left > right ho gaya, matlab already pura traverse ho chuka
            if(left <= right){
                int l = bottom;
                while(l >= top){
                    ans.push_back(matrix[l][left]);
                    l--;
                    // Left column(fixed) ke saare elements bottom se top(variable l) tak add kiye 
                }
                left++;
                // Left column complete ho gayi
                // Boundary ek right le aaye
            }
        }
        return ans;
        // Spiral order me saare elements collect ho chuke hain
    }
};

/*

Real idea for a spiral matrix is:
outer layer, then inner layer, then inner-inner layer
So boundaries need to be maintained(top, bottom, left, right)

One spiral means:
1. top row: left -> right
   After this, top row done, so: top++
2. right column: top -> bottom
   After this, right column done, so: right--;
3. bottom row: right -> left
   after this, bottom row done, so: bottom--;
4. left column: bottom -> top
   After this, left column done, so: left++;
Then again same process on the smaller inside rectangle

This whole cycle should happen inside while(top <= bottom && left <= right) because boundaries shrink karte rahenge

ALSO, top++, right-- hone ke baad, possible hai: 
no bottom row remains(eg. 1 x 3 matrix) (then it would run again)
OR
no left column remains(eg. 3 x 1 matrix) (again add the remaining elements again)
So bottom row traveral se pehle check: top <= bottom -> prevents bottom row ko dobara traverse karne se -> jab wo pehle hi top row ke through process ho chuki ho = koi remaining inner row bachi hai kya
And left column traversal se pehle check: left <= right -> prevents left column ko dobara traverse karne se -> jab wo column pehle hi right column ke through process ho chuki ho == koi remining inner column bachi hai kya
Agar nahi bachi → skip that side

But top row and column don't need safety checks
Top row: Always safe gau(Already check ho chuka hai while loop me)
Right column: ye bhi valid hogi, top++ karne par bhi
Par top row+right column done hone ke baad, ho sakta hai inner rectangle khatam ho chuka ho

Each boundary update happens "AFTER" traversing that side, not before
Pehle wo side traverse karo
Phir us side ko "visited" mark karo by shrinking boundary

TC -> O(m * n) | SC -> O(1) extra(Because answer vector me sirf output store ho raha hai)

*/