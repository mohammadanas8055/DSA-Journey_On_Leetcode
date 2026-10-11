class Solution {
public:
    bool isIsomorphic(string s, string t) {
        // Base Guard: Agar lengths different hain to isomorphic ho hi nahi sakti
        if(s.length() != t.length()) return false;

        // 256 size arrays to cover full ASCII character set
        // -1 indicates the character has NOT been mapped yet
    	vector<int> mppST(256,-1); // Maps character from s -> t
        vector<int> mppTS(256,-1); // Maps character from t -> s

        for(int i = 0; i < s.length(); i++){
            
            // Case 1: Check forward mapping(s -> t)
            // Agar s[i] pehle se mapped hai, aur wo current character t[i] ke equal nahi hai -> invalid
            if(mppST[s[i]] != -1 && mppST[s[i]] != t[i]){
                return false;
            }

            // case 2: Check reverse mapping(t -> s)
            // Agar t[i] pehle se kisi aur s[i] se map ho chuka hai -> invalid
            if(mppTS[t[i]] != -1 && mppTS[t[i]] != s[i]){
                return false;
            }

            // Establish the bidirectional mapping for future checks
            mppST[s[i]] = t[i];
            mppTS[t[i]] = s[i];
        }

        // Agar puri string bina conflict ke process ho gayi -> isomorphic
        return true;
    }
};

/*

TC -> O(n) | SC -> O(1)

*/