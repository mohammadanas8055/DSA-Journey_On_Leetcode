class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<char> s1;
        stack<char> t1;
        for(int i = 0; i < s.length(); i++){
            if(!s1.empty() && s[i] == '#'){
                s1.pop();
            }
            else if(s[i] == '#'){
                continue;
            }
            else{
                s1.push(s[i]);
            }
        }
        for(int i = 0; i < t.length(); i++){
            if(!t1.empty() && t[i] == '#'){
                t1.pop();
            }
            else if(t[i] == '#'){
                continue;
            }
            else{
                t1.push(t[i]);
            }
        }
        return s1 == t1;
    }
};