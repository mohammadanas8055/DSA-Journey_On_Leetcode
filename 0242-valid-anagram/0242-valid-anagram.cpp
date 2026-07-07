class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length() != t.length()){
            return false;
        }
        // If lengths differ, they cannot be anagrams
        
        int alphabet[26] = {0};
        // This creates a frequency array for lowercase English letters, all starting from 0

        for(int i = 0; i < s.length(); i++){
            alphabet[s[i] - 'a']++; // This means add count for characters(alphabets) from s
            alphabet[t[i] - 'a']--; // This means subtract count for characters(alphabets) from t
        }
        // If both strings have same character frequencies, everything returns zero
        for(int i = 0; i < 26; i++){
            if(alphabet[i] != 0){
                return false;
            }
        }
        // This is checking whether any character count is unmatched 
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