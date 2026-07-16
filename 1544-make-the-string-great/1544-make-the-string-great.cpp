class Solution {
public:
    string makeGood(string s) {
        string good;
        for(int i = 0; i < s.length(); i++){
            if(good.empty()){
                good.push_back(s[i]);
            }
            else if(s[i] != good.back() && tolower(s[i]) == tolower(good.back())){
                good.pop_back();
            }
            else{
                good.push_back(s[i]);
            }
        }
        return good;
    }
};