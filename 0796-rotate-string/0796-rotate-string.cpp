class Solution {
public:
    bool rotateString(string s, string goal) {
        // Base Guard: Agar lengths barabar nahi hain, to rotations se kabhi match nahi ho sakta
        // Example: "abc" and "abcd" can never be rotations of each other
        if(s.length() != goal.length()){
            return false;
        }

        // String Doubling Trick:
        // (s + s) contains ALL possiblr cyclic shifts of string 's' of length N as contiguous substrings
        string st = s + s;

        // string::find() returns the starting index of substring if found, else returns string::npos
        // Agar goal (s + s) ke andar mil gaya -> valid rotation
        return st.find(goal) != string::npos;
    }
};

/*

TC -> O(N) | SC -> O(N)

*/