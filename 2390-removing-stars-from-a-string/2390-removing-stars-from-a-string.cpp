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

/*

TC -> O(n) (Single pass traversal with O(1) push/pop operations | SC -> O(n) (No stars)

*/