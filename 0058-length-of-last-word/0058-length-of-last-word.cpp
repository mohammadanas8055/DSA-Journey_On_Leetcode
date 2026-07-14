class Solution {
public:
    int lengthOfLastWord(string s) {
        int count = 0;
        int lastWordCount = 0;
        for(int i = 0; i < s.length(); i++){
            if(isalpha(s[i])){
                count++;
                lastWordCount = count;
            }
            if(!isalpha(s[i])){
                count = 0;
            }
        }
        return lastWordCount;
    }
};