class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(int i = 0; i < s.length(); i++){
            if(s[i] == '(' || s[i] == '{' || s[i] == '['){
                st.push(s[i]);
            } // Opening brackets ko push kar do, agar sahi order me closing brackets aayenge to ye pop hote jayenge
            else{ // If any close bracket comes, this else runs

                if(st.empty()){
                    return false;
                } // this ensures that opening bracket(any) is present
                  // agar sirf closing brackets honge -> yani stack me kuch push nahi hua hai
                  // wo invalid hai, because pehle opening aur uske corresponding closing bracket chahiye
                
                if(s[i] == ')' && st.top() != '('){
                    return false;
                } // This ensures that if closing bracket is ) then opening should be (
                if(s[i] == '}' && st.top() != '{'){
                    return false;
                } // This ensures that if closing bracket is } then opening should be {
                if(s[i] == ']' && st.top() != '['){
                    return false;
                } // This ensures that if closing bracket is ] then opening should be [

                st.pop(); // Check mismatch case, agar yahan tak aa gaye to sahi opening bracket tha, pop kar do use
            }
        }
        return st.empty(); // And not return true
                           // Because "(((" will push three opening brackets and never pop them
                           // So final line should depend on stack 
    }
};

/*

>Why stack is needed?
Because the last opened bracket must close first.

>valid tabhi hai jab saare opening brackets match hoke pop ho chuke hain

TC -> O(n) | SC -> O(n) (Worst case all opening brackets, all go into stack)

>Pattern that needs to be remembered:
Opening bracket -> push
Closing bracket -> top must match
If matched -> pop
At end -> stack must be empty

*/

/*

// opening bracket mile to stack me push karo

// closing bracket mile to pehle check karo
// ki stack empty to nahi hai
// agar empty hai, matlab is closing bracket ka koi pair nahi hai

// agar stack empty nahi hai to top element check karo
// agar matching opening bracket nahi hai to string invalid hai

// agar matching bracket mil gaya to stack se pop kar do

*/