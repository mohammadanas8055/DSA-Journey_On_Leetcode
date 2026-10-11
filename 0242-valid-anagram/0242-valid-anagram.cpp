class Solution {
public:
    bool isAnagram(string s, string t) {
        // Base Guard: Anagarams must have the exact same character count
        // If lengths differ, they can never be anagrams
        if(s.length() != t.length()){
            return false;
        }
        
        // Fixed-size frequency array of 26 lowercase English letters 
        // Array on stack is faster than vector/map due to cache locality and zero heap allocations
        int alphabet[26] = {0};

        // Increment for 's' and decrement for 't' simultaneously
        // Net frequency for every character must be 0 if both strings have identical characters
        for(int i = 0; i < s.length(); i++){
            alphabet[s[i] - 'a']++; // Count char from source string
            alphabet[t[i] - 'a']--; // Cancel out with char from target string
        }

        // Verify that all character buckets perfectly cancelled out to zero
        for(int i = 0; i < 26; i++){
            // If any count != 0, it means character frequencies did not match
            if(alphabet[i] != 0){
                return false;
            }
        }
        return true;
    }
};

/*

TC -> O(n) | SC -> O(1)

If input also contains Unicode characters(English, Hindi, Arabic, emoji etc)
we can't use a fixed size 26

So we need a frequency map(hash map)to store the frequency of each character

Pseudo idea:
for each character in s:
    freq[character]++

for each character in t:
    freq[character]--

check all counts zero

*/