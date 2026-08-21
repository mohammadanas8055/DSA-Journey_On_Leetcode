// class Solution {
// public:
//     string reverseWords(string s) {
//         vector<string> words;
//         string currentWord;
//         for(int i = 0; i < s.length(); i++){
//             if(s[i] != ' '){
//                 currentWord.push_back(s[i]);
//             }
//             else{
//                 if(!currentWord.empty()){
//                     words.push_back(currentWord);
//                     currentWord.clear();
//                 }
//             }
//         }
//         if(!currentWord.empty()){
//             words.push_back(currentWord);
//         }
//         string ans;
//         for(int j = words.size() - 1; j >= 0; j--){
//             for(int k = 0; k < words[j].length(); k++){
//                 ans.push_back(words[j][k]);
//             }
//             if(j != 0){
//                 ans.push_back(' ');
//             }
//         }
//         return ans;
//     }
// };

class Solution{
public: 
    string reverseWords(string s){
        int n = s.length();
        int write = 0;
        for(int read = 0; read < n; read++){
            if(s[read] != ' '){
                if(write > 0 && s[read - 1] == ' '){
                    s[write] = ' ';
                    write++;
                }
                s[write] = s[read];
                write++;
            }
        }
        s.resize(write);
        int i = 0;
        int j = s.length() - 1;
        while(i < j){
            swap(s[i], s[j]);
            i++;
            j--;
        }
        int start = 0;
        for(int end = 0; end <= s.length(); end++){
            if(end == s.length() || s[end] == ' '){
                reverse(s.begin() + start, s.begin() + end);
                start = end + 1;
            }
            
        }
        return s;
    }
};