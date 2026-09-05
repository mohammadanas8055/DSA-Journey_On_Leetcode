class Solution {
public:
    string convertToBase7(int num) {
        if(num == 0){
            return "0";
        }
        string s;
        int sign = 1;
        if(num < 0){
            num = num * -1;
            sign = -1;
        }
        while(num != 0){
            s.push_back((num % 7) + '0');
            num = num / 7;
        }
        if(sign == -1){
            s.push_back('-');
        }
        reverse(s.begin(), s.end());
        return s;
    }
};