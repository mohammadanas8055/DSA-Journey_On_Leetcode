class Solution {
public:
    bool isIsomorphic(string s, string t) {
    	vector<int> mppST(256,-1);
        vector<int> mppTS(256,-1);
        for(int i = 0; i < s.length(); i++){
            if(mppST[s[i]] != -1 && mppST[s[i]] != t[i]){
                return false;
            }
            if(mppTS[t[i]] != -1 && mppTS[t[i]] != s[i]){
                return false;
            }
            mppST[s[i]] = t[i];
            mppTS[t[i]] = s[i];
        }
        return true;
    }
};