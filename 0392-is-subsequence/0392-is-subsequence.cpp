class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i = 0; // Pointer for string 's' (the shorter string we are looking for)

        // Hum string 't' par traverse karenge ek ek karke
        for(int j = 0; j < t.length(); j++){

            // Safety check: 'i < s.length()' ensures we don't access memory outside of string s
            // Match check: Agar 't ka current character 's' ke current target char se match karte hai..
            if(i < s.length() && t[j] == s[i]){
               i++; // Next target character ki taraf badho
            }

            // Optimization: Agar saare characters mil gaye, to aage loop chalane ka fayeda nahi
            if(i == s.length()){
                return true;
            }
        }

        // Agar loop khatam hone ke baad i, s ki length ke barabar hai
        // Iska matlab saare characters order me mil gaye
        return i == s.length();
    }
};

/*

Agar ye condition lagate ki if(!s.empty() && s[i] = t[j]) 
s.empty() only tells about the original string. It doesn't tell if you have already finished matching all its characters.

If s = "abc" and t = "abcde"
i = 3 ban gaya, uske baad bhi t ke bache hue characters ke liye loop chalega
to s[3] is out of bounds

Instead, if write i < s.length()
jaise hi i, s ke end pe pahunchega, condition false

TC -> O(T) | SC -> O(1)

// 2-Pointer Approach: 'i' for 's', 'j' for 't'.
// 'j' hamesha aage badhega, 'i' sirf tab badhega jab match milega.
// Condition 'i < s.length()' zaroori hai taaki 'i' string se bahar na nikal jaye.
// End mein agar i == s.length(), matlab subsequence mil gaya.$0
*/