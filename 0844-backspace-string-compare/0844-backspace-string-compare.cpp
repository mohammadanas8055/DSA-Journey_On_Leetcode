class Solution {
public:
    bool backspaceCompare(string s, string t) {
        // stack<char> s1;
        // stack<char> t1;
        // for(int i = 0; i < s.length(); i++){
        //     if(!s1.empty() && s[i] == '#'){
        //         s1.pop();
        //     }
        //     else if(s[i] == '#'){
        //         continue;
        //     }
        //     else{
        //         s1.push(s[i]);
        //     }
        // }
        // for(int i = 0; i < t.length(); i++){
        //     if(!t1.empty() && t[i] == '#'){
        //         t1.pop();
        //     }
        //     else if(t[i] == '#'){
        //         continue;
        //     }
        //     else{
        //         t1.push(t[i]);
        //     }
        // }
        // return s1 == t1;

        int i = s.length() - 1;
        int j = t.length() - 1;
        int skipS = 0;
        int skipT = 0;
        while(i >= 0 || j >= 0){
            while(i >= 0){
                if(s[i] == '#'){     
                    skipS++;
                    i--;
                }
                else if(skipS > 0){
                    skipS--;
                    i--;
                }
                else{
                    break;
                }
            }
            while(j >= 0){
                if(t[j] == '#'){
                    skipT++;
                    j--;
                }
                else if(skipT > 0){
                    skipT--;
                    j--;
                }
                else{
                    break;
                }
            }
            if((i >= 0 && j < 0) || (i < 0 && j >= 0)){
                return false;
            }
            else if(i >= 0 && j >= 0 && s[i] != t[j]){
                return false;
            }
            else{
                i--;
                j--;
            }
        }
        return true;
    }
};