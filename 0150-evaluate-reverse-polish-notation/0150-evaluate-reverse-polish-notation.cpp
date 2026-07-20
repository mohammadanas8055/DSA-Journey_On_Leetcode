class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> output;
        for(int i = 0; i < tokens.size(); i++){
            if(tokens[i] == "+"){
                int temp1 = output.top();
                output.pop();
                int temp2 = output.top();
                output.pop();
                output.push(temp2 + temp1);
            }
            else if(tokens[i] == "-"){
                int temp3 = output.top();
                output.pop();
                int temp4 = output.top();
                output.pop();
                output.push(temp4 - temp3);
            }
            else if(tokens[i] == "*"){
                int temp5 = output.top();
                output.pop();
                int temp6 = output.top();
                output.pop();
                output.push(temp6 * temp5);
            }
            else if(tokens[i] == "/"){
                int temp7 = output.top();
                output.pop();
                int temp8 = output.top();
                output.pop();
                output.push(temp8 / temp7);
            }
            else{
                int sign = 1;
                int num = 0;
                int start = 0;
                if(tokens[i][0] == '-'){
                    sign = -1;
                    start = 1;
                }
                for(int j = start; j < tokens[i].length(); j++){
                    num = num * 10 + tokens[i][j] - '0';
                }
                num = num * sign;
                output.push(num);
            }
        }
        return output.top();
    }
};