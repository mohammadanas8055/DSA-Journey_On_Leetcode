class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        for(int j = 0; j < strs[0].size(); j++){
            for(int i = 1; i < strs.size(); i++){
                if(!strs[i].empty() && strs[0][j] == strs[i][j]){
                    continue;
                }
                else{
                    return strs[0].substr(0, j);
                }
            }
        }
        return strs[0];
    }
};

/*

How Would I Place A Pointer At Each Word...If There are 200 Words? -> Ans. We don't need 200 pointers
Instead we manage two things:
Which character index are we looking at?(j)
2. Which word are we comparing it against(i)

So let's look the firsrt word, and assume it might be the common prefix
Ab uske ek ek character ko check karo, dusre words ke first character se(loop from 1 to strs.size() - 1)
Agar aage ka koi word chhota na ho, aur phir match bhi kar gaya, to next character pe shift
agar first word khatam ho gaya, iska matlab wahi maximum common prefix ho sakta hai(Aur saare word usse chhote the length me)
Jaise hi mismatch mile, waise hi stop kar dena hai

*/