class Solution {
public:
    int calPoints(vector<string>& operations) {
        vector<int> ans;
        for(int i = 0; i < operations.size(); i++){
            if(operations[i] == "C"){
                ans.pop_back();
            }
            else if(operations[i] == "D"){
                int push = 2 * ans.back();
                ans.push_back(push);
            }
            else if(operations[i] == "+"){
                int last = ans.back();
                ans.pop_back();
                int add = last + ans.back();
                ans.push_back(last);
                ans.push_back(add);
            }
            else{
                int num = 0;
                if(operations[i][0] == '-'){
                    for(int j = 1; j < operations[i].length(); j++){
                    num = num * 10 + (operations[i][j] - '0');
                }
                num = num * -1;
                }
                else{
                    for(int j = 0; j < operations[i].length(); j++){
                    num = num * 10 + (operations[i][j] - '0');
                }
                }
                ans.push_back(num);
            }
        }
        int sum = 0;
        for(int i = 0; i < ans.size(); i++){
            sum = sum + int(ans[i]);
        }
        return sum;
    }
};