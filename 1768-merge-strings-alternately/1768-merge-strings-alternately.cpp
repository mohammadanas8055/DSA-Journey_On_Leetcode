class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int i = 0;
        // Pointer for word1

        int j = 0;
        // Pointer for word2

        int m = word1.length();
        int n = word2.length();

        string s;
        // result string initialisation
        // Total length m + n hogi
        // C++ me push_back dynamic memory allocate karta hai
        // Optional optimization: s.reserve(m + n) se reallocation overhead bhi bach jayega
        
        // Loop runs as long as AT LEAST ONE string has characters left
        // Condition (i < m || j < n) ensures that we don't stop prematurely
        // when one string is shorter than the other
        while(i < m || j < n){

            // Step 1: If word1 still has characters, append current char and increment i
            if(i < m){
                s.push_back(word1[i]);
                i++;
            }

            // Step 2: if word2 still has characters, append current char and increment j
            // Alternating order: word1 ka char add hone ke turant baad word2 ka char add hota hai
            if(j < n){
                s.push_back(word2[j]);
                j++;
            }
        }
        return s;
        // merged string containing interleaved characters from both sides
    }
};

/*

O(m + n) memory allocated hona unavoidable hai, kyunki merged result ki total length (m + n) hogi
word1.resize(m + n) me overwriting ka risk hai aur phir overwriting se bachne ke liye piche se shift karna padega, jisse runtime slow ho sakta hai and code complex

TC -> O(m + n) (Loop tab tak chalta hai jab tak dono strings puri process na ho jayein) | SC -> O(m + n)

*/