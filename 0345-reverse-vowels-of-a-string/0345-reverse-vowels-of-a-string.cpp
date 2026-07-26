class Solution {
public:
    bool isVowel(char s){
        if(tolower(s) == 'a' || tolower(s) == 'e' || tolower(s) == 'i' || tolower(s) == 'o'|| tolower(s) == 'u'){
            return true;
        }
        return false;
    }
    string reverseVowels(string s) {
        int i = 0;
        int j = s.length() - 1;
        while(i < j){
            while(i < j && !isVowel(s[i])){
                i++;
            }
            while(i < j && !isVowel(s[j])){
                j--;
            }
                swap(s[i], s[j]);
                i++;
                j--;
            
        }
        return s;
    }
};