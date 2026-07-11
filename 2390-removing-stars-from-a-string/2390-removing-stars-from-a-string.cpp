/*

class Solution {
public:
    string removeStars(string s) {
        // String will act as an active stack, dynamically grow and shrink in size as we process characters
        // Agar stack use karte to phir se stack ko string me convert karna padta
        string ans;
        for(int i = 0; i < s.length(); i++){
            // Agar string and empty na ho aur star bhi ho current character(to pichla character delete karna hai)
            if(!ans.empty() && s[i] == '*'){
                ans.pop_back();
            } 
            // agar empty hai ya current character normal letter hai to else chalega, us character ko include kar lenge string me
            // It joins the stack and waits to see if a future star (*) will delete it.
            // Note: Agar stack khali ho aur tab '*' mile -> LeetCode guarantees this won't happen -> because operation is always possible(nahi to wo bhi push hoga)
            else{
                ans.push_back(s[i]);
            }
        }
        // This keeps the surviving characters 
        // IN their relative order. No reversing or copying needed
        return ans;
    }
};

TC -> O(n) (Single pass traversal with O(1) push/pop operations | SC -> O(n) (No stars)

*/

class Solution {
public:
    string removeStars(string s) {
        int i = 0; // Reader -> Reads the original letters from left to right
        int j = 0; // Writer -> Writes the active letters starting at the beginning of the index
        for(i = 0; i < s.length(); i++){
            if(s[i] == '*'){
                if(j > 0){ // Ensures that we only move backward if we actually have wriiten letters to erase
                // Agar empty string hui, ya sab delete ho chuka hai, to j-- karke, next step me us index pe overwrite nahi kar payenge
                    j--;
                }
            }
            // Agar normal letter dikha to use write karke aage badhenge
            else{
                s[j] = s[i];
                j++;
            }
        }
        // Because 0 se likhna shuru kiya hai, aur har baar likhne pe j++ kara hai, to index is the exact count of characters we have written
        // so we resize the string -> Taki length exactly number of surviving characters ke barabar rahe
        s.resize(j);
        return s;
    }
};

/*

eg. s = ab*
    (i = 0; j = 0)
    s[0] = 'a' -> s[j] = 'a' and move one step forward
    (i = 1; j = 1)
    s[1] = 'b' -> s[j] = 'b' and move one step forward
    (i = 2; j = 2)
    s[2] = '*' -> This means backspace (so ensuring our string still has letters to erase) -> Move j backward 
    WHY? -> because index 1 holds 'b' -> we will overwrite the'b' -> Effectively 'b' is deleted

    Now the loop ends, j is at index 1
    The first j characters are our answer(1 character)
    becuase they survived(index 0 to j - 1)

    So resize the string to that length

TC -> O(n) | SC -> O(1)

*/