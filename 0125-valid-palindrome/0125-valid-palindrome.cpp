class Solution {
public:
    bool isPalindrome(string s) {
        int i = 0;
        int j = s.length() - 1;
        // i = start pointer (0)
        // j = end pointer (last valid index)

        while(i < j){
            // Jab tak pointers cross nahi karte, pairs compare karte rahenge

            // SKIP 1: Left side se non-alphanumeric characters skip karo
            // isalnum(ch) returns true only for A-Z, a-z, 0-9
            // Spaces, commas, colons, symbols etc. ke liye false dega
            if(!(isalnum(s[i]))){
                i++;
                continue;
                // continue isliye: agla character check karne ke liye
                // outer while loop ka next iteration run hoga
            }

            // SKIP 2: Right side se non-alphanumeric characters skip karo
            if(!(isalnum(s[j]))){
                j--;
                continue;
            }

            // MATCH CHECK: Dono pointers valid alphanumeric characters par khade hain
            // tolower() uppercase ko lowercase me convert kar deta hai
            // taaki 'A' aur 'a' equal treat ho saken(case-insensitive requirement)
            if(tolower(s[i]) != tolower(s[j])){
                return false;
                // Character mismatch hua -> valid palindrome nahi hai
            }

            // Match mil gaya, dono pointers ko andar shift karo next pair ke liye
            i++;
            j--;
        }
        return true;
        // Puri string scan ho gayi aur koi mismatch nahi mila -> Valid Palindrome
    }
};