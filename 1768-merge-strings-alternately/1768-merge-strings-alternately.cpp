class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int i = 0;
        int j = 0;
        int m = word1.length();
        int n = word2.length();
        string s;
        while(i < m || j < n){
            if(i < m){
                s.push_back(word1[i]);
                i++;
            }
            if(j < n){
                s.push_back(word2[j]);
                j++;
            }
        }
        return s;
    }
};