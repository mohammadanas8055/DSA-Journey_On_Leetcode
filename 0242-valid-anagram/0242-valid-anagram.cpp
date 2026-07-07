class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length() != t.length()){
            return false;
        }
        int alphabet[26] = {0};
        for(int i = 0; i < s.length(); i++){
            alphabet[s[i] - 'a']++;
            alphabet[t[i] - 'a']--;
        }
        for(int i = 0; i < 26; i++){
            if(alphabet[i] != 0){
                return false;
            }
        }
        return true;
    }
};