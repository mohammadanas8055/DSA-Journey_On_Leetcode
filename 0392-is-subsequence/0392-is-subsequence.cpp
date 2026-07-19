class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i = 0;
        for(int j = 0; j < t.length(); j++){
            if(!s.empty() && t[j] == s[i]){
               i++;
            }
        }
        return i == s.length();
    }
};