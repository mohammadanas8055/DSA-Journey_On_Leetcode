class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        for(int j = 0; j < strs[0].size(); j++){
            for(int i = 1; i < strs.size(); i++){
                if(!strs[i].empty() && strs[0][j] == strs[i][j]){
                    continue;
                }
                else{
                    strs[0].resize(j);
                    return strs[0];
                }
            }
        }
        return strs[0];
    }
};