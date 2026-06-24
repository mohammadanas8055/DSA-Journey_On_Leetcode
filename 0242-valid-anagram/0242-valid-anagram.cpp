class Solution {
public:
    bool isAnagram(string s, string t) {
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        if(t == s){
            return 1;
        }
        else{
            return 0;
        }
    }
};