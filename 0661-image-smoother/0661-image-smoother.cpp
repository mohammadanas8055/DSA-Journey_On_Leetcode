class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        int m = img.size();
        // Total rows in the image 

        int n = img[0].size();
        // Total columns in the image
        
        vector<vector<int>> result(m, vector<int>(n));
        // Answer matrix pehle se hi m x n size ki bana li
        // Agar yahan pre-allocation nahi ki hoti
        // to result[i][j] = ... karte waqt undefined behavior hota
        // In-place nahi kiya kyunki agar original img update karte
        // to adjacent cells ke calculations galat ho jaate

        for(int i = 0; i < m; i++){
            // har row traverse kar rahe hain
            
            for(int j = 0; j < n; j++){
                // Har column traverse kar rahe hain
                // (i,j) current cell hai jiska smoothed value nikalna hai

                int sum = 0;
                // Current cell ke valid neighbors ka total sum

                int count = 0;
                // Valid neighbors ki count
                // Count fixed(9) nah ihai kyunki corners aur edges par
                // kuch neighbors exist nahi karte

                for(int dr = -1; dr <= 1; dr++){
                    // dr = row direction shift
                    // -1 means upar, 0 means same row, +1 means neeche

                    for(int dc = -1; dc <= 1; dc++){
                        // dc = column direction shift
                        // -1 means left, 0 means same col, +1 means right
                        // dr aur dc ke 9 combinations se
                        // sab neighbors aur khud current cell cover ho jaate hain

                        int newRow = i + dr;
                        int newCol = j + dc;
                        // Candidate neighbor ki actual position

                        if((0 <= newRow) && (newRow < m) && (0 <= newCol) && (newCol < n)){
                            // Boundary check: 
                            // newRow >= 0 ensures upar wali rows ke bahar nahi gaye 
                            // newRow < m ensures neeche wali rows ke bahar nahi gaye
                            // newCol >= 0 ensures left wale columns ke bahar nahi gaye 
                            // newCol < n ensures right wale columns ke bahar nahi gaye 

                            sum += img[newRow][newCol];
                            // valid neighbor mila, uski value sum me add ki

                            count++;
                            // aur count badhaya
                        }
                        // Agar newRow ya newCol invalid hai
                        // simple ignrore kar dete hain
                        // koi special corner/edge handling nahi chahiye
                    }
                }
                result[i][j] = sum / count;
                // Integer division use ho rahi hai
                // C++ me int / int automatically floor value deta hai
                // jo problem me maanga tha
            }
        }
        return result;
        // Smoothed image return kar di
    }
};

/*

For any cell (i,j), possible row shifts are: -1, 0, +1
                and possible column shifts are: -1, 0, +1
So total combinations: (-1,-1) -> up-left
                       (-1,0) -> up
                       (-1,+1) -> up-right
                       (0,-1) -> left
                       (0,0) -> self
                       (0,+1) -> right
                       (+1,-1) -> down-left
                       (+1,0) -> down
                       (+1,+1) -> down-right

sare 9 relative position try karo -> jo valid ho, use sum me add karo aur count++
Har candidate neighbour ke liye: newRow = i + dr
                                 newCol = i + dc
                                 aur 0 <= newRow < m
                                     0 <= newCol < n
one outer loop for dr: -1 to +1
one inner loop for dc: -1 to +1

TC -> O(m * n * 9) = O(m * n) (For every cell, 9 positions check) | SC -> O(m * n)

* result ko empty rakh ke result[i][j] invalid access tha
* Also, ((0 <= newRow < m) && (0 <= newCol < n)) looks mathematically correct, but C++ me aise chained comparison work nahi karti

It first evaluates 0 <= newRows -> 0 or 1
And then it checks 1 < m or 0 < m

To saari conditions ko separately && se likhna padega(sab hi true honi chahiye valid hone ke liye)

*/