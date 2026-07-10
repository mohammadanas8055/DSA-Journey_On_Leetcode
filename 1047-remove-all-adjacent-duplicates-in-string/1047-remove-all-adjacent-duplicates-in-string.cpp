/*

class Solution {

public:

    string removeDuplicates(string s) {

        stack<char> st;

        for(int i = 0; i < s.length(); i++){

            if(!st.empty() && st.top() == s[i]){

                st.pop();

            }

            else{

                st.push(s[i]);

            }

        }

        string result = "";

        while(!st.empty()){

            result = st.top() + result; // C++ has to create a new string and copy the old string after the character. -> TC -> O(n^2)
                                        // Therefore use push_back(Stack provides in reverse order) -> Then reverse it
            st.pop();

        }

        return result;

    }

};
 
OR Directly use string as a stack

*/

class Solution {
public:
    string removeDuplicates(string s) {
        string result;
        for(int i = 0; i < s.length(); i++){
            if(!result.empty() && s[i] == result.back()){
                result.pop_back();
            }
            else{
                result.push_back(s[i]);
            }
        }
        return result;
    }
};

/*

# string as stack
A string can be used like a stack of characters.

Useful functions:
result.push_back(ch);                   // push
result.pop_back();                      // pop last char
result.back();                          // top
result.empty();                         // check empty
result.size() or result.size();         // length

Pattern:
if current char == result.back():
    result.pop_back()
else:
    result.push_back(current char)

TC -> O(n) | SC -> O(n)



*/