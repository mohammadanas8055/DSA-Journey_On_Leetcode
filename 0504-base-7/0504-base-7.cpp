class Solution {
public:
    string convertToBase7(int num) {
        // EDGE CASE: 0 ka Base 7 bhi "0" hi hota hai
        // Kyunki hamara while(num != 0) loop 0 ke liye chalega hi nahi
        // Isliye 0 ko explicitly handle karna zaroori hai
        if(num == 0){
            return "0";
        }

        string s;
        int sign = 1;
        
        // Negative numbers ko handle karne ke liye flag maintain karte hain
        // Array/String build karne ke liye number ko positive me convert kar lete hain
        if(num < 0){
            num = num * -1;
            sign = -1;
        }

        // BASE CONVERSION ALGORITHM (Repeated Division Method):
        // Kisi bhi decimal number ko Base B me convert karne ke liye
        // Usko repeatedly B se divide karte hain aur remainders collect karte hain
        while(num != 0){
            s.push_back((num % 7) + '0'); // Convert int digit to char digit 
            num = num / 7; // Reduce number for next digit
        }

        // Elegant trick for negative sign:
        // Kyunki remainders Right-to-left (Least Significant Digit se Most Significant Digit) collect hue hain
        // number ka sabse pehla character (Negative Sign) un-reversed string ke END me hona chahiye

        if(sign == -1){
            s.push_back('-');
        }

        // String Reversal:
        // Digits ulte order me collect hue the. isliye final correct representation ke liye puri string ko reverse karte hain
        // Isse '-' sign bhi automatically index 0 par aa jata hai
        reverse(s.begin(), s.end());

        return s;
    }
};

/*

TC -> O(log7|num|) (Har step me 7 se divide ho raha hai) (Loop maximum 9 baar chalega (range |num| <= 10^7 -> max digits = 9). So O(log7N) = O(1) in practice) | SC -> O(log7|num|)

*/