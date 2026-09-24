class Solution {
public:
    int reverse(int x) {
        long long num = x;
        bool isNeg = false;
        if(num < 0){
            isNeg = true;
            num = num * -1;
        }
        long long rev = 0;
        while(num != 0){
            rev = rev * 10 + num % 10;
            num = num / 10;
        }
        if(rev > INT_MAX || rev < INT_MIN){
            return 0;
        }
        if(isNeg){
            return -rev;
        }
        return rev;
    }
};