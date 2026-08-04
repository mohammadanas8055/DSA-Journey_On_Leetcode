class Solution {
public:
    string reversePrefix(string word, char ch) {
        for(int i = 0; i < word.length(); i++){
            if(word[i] == ch){
                int left = 0;
                int right = i;
                while(left < right){
                    swap(word[left], word[right]);
                    left++;
                    right--;
                }
                break;
            }
        }
        return word;
    }
};