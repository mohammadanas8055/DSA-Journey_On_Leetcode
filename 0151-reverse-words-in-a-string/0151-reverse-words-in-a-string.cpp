class Solution {
public:
    string reverseWords(string s) {
        vector<string> words;
        string currentWord;
        for(int i = 0; i < s.length(); i++){
            if(s[i] != ' '){
                currentWord.push_back(s[i]);
            }
            else{
                if(!currentWord.empty()){
                    words.push_back(currentWord);
                    currentWord.clear();
                }
            }
        }
        if(!currentWord.empty()){
            words.push_back(currentWord);
        }
        string ans;
        for(int j = words.size() - 1; j >= 0; j--){
            for(int k = 0; k < words[j].length(); k++){
                ans.push_back(words[j][k]);
            }
            if(j != 0){
                ans.push_back(' ');
            }
        }
        return ans;
    }
};