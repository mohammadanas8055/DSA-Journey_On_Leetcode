class Solution {
public:
    string makeGood(string s) {
        int write = 0;
        int n = s.length();
        for(int i = 0; i < n; i++){
            if(write == 0){
                s[write] = s[i];
                write++;
            }
            else if(s[i] != s[write - 1] && tolower(s[i]) == tolower(s[write - 1])){
                write--;
            }
            else{
                s[write] = s[i];
                write++;
            }
        }
        s.resize(write);
        return s; 
    }
};

// class Solution {
// public:
//     string makeGood(string s) {
//         string good;
//         for(int i = 0; i < s.length(); i++){
//             if(good.empty()){
//                 good.push_back(s[i]);
//             }
//             else if(s[i] != good.back() && tolower(s[i]) == tolower(good.back())){
//                 good.pop_back();
//             }
//             else{
//                 good.push_back(s[i]);
//             }
//         }
//         return good;
//     }
// };