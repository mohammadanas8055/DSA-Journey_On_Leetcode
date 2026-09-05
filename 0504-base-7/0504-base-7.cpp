class Solution {
public:
    string convertToBase7(int num) {
        string s;
        int sign = 1;
        if(num == 0){
            return "0";
        }
        if(num < 0){
            num = num * -1;
            sign = -1;
        }
        while(num != 0){
            s.push_back((num % 7) + '0');
            num = num / 7;
        }
        reverse(s.begin(), s.end());
        if(sign == -1){
            string temp = s;
            s.clear();
            s.push_back('-');
            for(int i = 0; i < temp.length(); i++){
                s.push_back(temp[i]);
            }
        }
        return s;
    }
};