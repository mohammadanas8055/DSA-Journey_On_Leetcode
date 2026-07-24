class Solution {
public:
    bool isPalindrome(string s, int left, int right){
        int i = left;
        int j = right;
        while(i < j){
            if(s[i] != s[j]){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }

    bool validPalindrome(string s) {
        int i = 0;
        int j = s.length() - 1;
        while(i < j){
            if(s[i] != s[j] && isPalindrome(s, i + 1, j) || s[i] != s[j] && isPalindrome(s, i, j - 1)){
                return true;               
            }
            if(s[i] != s[j] ){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
};