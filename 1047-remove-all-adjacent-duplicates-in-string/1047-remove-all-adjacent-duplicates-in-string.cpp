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

// class Solution {
// public:
//     string removeDuplicates(string s) {
//         string result;
//         for(int i = 0; i < s.length(); i++){
//             if(!result.empty() && s[i] == result.back()){
//                 result.pop_back();
//             }
//             else{
//                 result.push_back(s[i]);
//             }
//         }
//         return result;
//     }
// };

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

We can do it in place just as we did in Make the String Great

Imagine thye original string s as our stack
We need a pointer to track the "top of the stack" -> write

1. write tells you two things:
   . Where the next character should be written
   . what the current valid size of your "stack" is
2. The "top" of the stack is:
   . s[write - 1] (Because write is where the NEXT thing goes)
3. For every character s[i] we read:
   . Check for Duplicate: Is the stack NOT empty(write > 0), and is s[i] equal to the top of the stack(s[write - 1])?
       . If YES: It's a duplicate! How do you "pop" from an in-place stack? We just move the pointer "back". write--
       . If NO: It's a valid character. "Push" it to the stack. s[write] = s[i] and then write++
4. At the end:
   . The valid string only exists from index 0 to write - 1
   . So we resize it: s.resize(write)
   . return s 

*/

class Solution{
public:
    string removeDuplicates(string s){
        int write = 0;
        // write ka meaning:
        // 1. current valid result ki length
        // 2. next character kis index par likhna hai

        // Iska matlab current valid "stack" hamesha s[0 ... write - 1] me pada hai
        // Aur stack ka top hamesha s[write - 1] hoga, agar write > 0 hai
        for(int read = 0; read < s.length(); read++){
            // read original string ko left-to-right scan karega
            // Yani ham har character ko ek baar process kar rahe hain

            if(write > 0 && s[write - 1] == s[read]){
                // write > 0 isliye check kiya:
                // kyunki agar valid stack empty hai to top access nahi kar sakte

                // s[write - 1] == s[read] ka matlab:
                // current character, current built result ke last character ke equal hai
                // so adjacent duplicate pair mil gaya

                // Pair remove karne ke liye actual string erase nahi karni padti
                // bas valid result ki length 1 kam kar do
                // kyunki current character ko bhi add nahi karna
                // aur previous same character ko bhi hata dena hai
                write--;
            }
            else{
                // Duplicate pair nahi bana
                // to current character valid result ka part banega

                s[write] = s[read];
                // Current character ko valid result ke next slot me likh diya

                // NOTE:
                // Ye overwrite safe hai because read hamesha current scan position par hai
                // aur write current compacted result bana raha hai
                // Hum original string ke front part ko result-stack ki tarah reuse kar rahe hain

                write++;
                // Ab valid result ki length 1 badh gayi
            }
        }
        s.resize(write);
        // Pure process ke baad actual valid answer sirf first 'write' characters me hai
        // baaki characters old/irrelevant ho chuke hain
        // resize(write) unhe logically string se hata deta hai
        
        return s;
    }
};

/*

TC -> O(n) | SC -> O(1)

*/