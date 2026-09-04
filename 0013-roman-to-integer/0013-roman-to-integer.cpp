// class Solution {
// public:
//     int romanToInt(string s) {
//         int num = 0;
//         for(int i = 0; i < s.length(); i++){
//             if(s[i] == 'M'){
//                 if(i > 0 && s[i - 1] == 'C'){
//                     num += 900 - 100;
//                 }
//                 else{
//                     num += 1000;
//                 }
//             }
//             else if(s[i] == 'D'){
//                 if(i > 0 && s[i - 1] == 'C'){
//                     num += 400 - 100;
//                 }
//                 else{
//                     num += 500;
//                 }
//             }
//             else if(s[i] == 'C'){
//                 if(i > 0 && s[i - 1] == 'X'){
//                     num += 90 - 10;
//                 }
//                 else{
//                     num += 100;
//                 }
//             }
//             else if(s[i] == 'L'){
//                 if(i > 0 && s[i - 1] == 'X'){
//                     num += 40 - 10;
//                 }
//                 else{
//                     num += 50;
//                 }
//             }
//             else if(s[i] == 'X'){
//                 if(i > 0 && s[i - 1] == 'I'){
//                     num += 9 - 1;
//                 }
//                 else{
//                     num += 10;
//                 }
//             }
//             else if(s[i] == 'V'){
//                 if(i > 0 && s[i - 1] == 'I'){
//                     num += 4 - 1;
//                 }
//                 else{
//                     num += 5;
//                 }
//             }
//             else{
//                 num += 1;
//             }
//         }
//         return num;
//     }
// };

/*

This is rather mathematical correction thinking
eg. "CM" 
    C already +100 ho chuka hai(pichli iteration me)
    Ab M mila aur pichla char C hai
    To actual contrbutin of "CM" = 900, but 100 already add ho chuka hai
    Isliye sirf 900 - 100 = 800 add karna hai

This is 'accounting correction' - jo pehle extra add hua tha, uska hisaab current step me adjust kar diya

My code checking for one character before -> sufficient -> kyunki valid Roman numerals me subtraction prefix kabhi DOUBLE NAHI HOTA
Isliye i - 1 check karna guaranteed sufficient hai

My code(Look-behind) -> Bahut saare if-else blocks
                     -> num += 900 - 100 (Correction method)
                     -> Thoda repetitive and complex

Standard code(Look-ahead) -> Sirf ek clean if block
                          -> sum += 1000 ya sum -= 100 (Direct rule)
                          -> Simple

Therefore, Roman numeral ska simple rule: 
" Agar current character ki value NEXT character ki value se chhoti hai -> Subtract karo. Warna add karo"

*/

class Solution{
public: 
    int romanToInt(string s){
        int num = 0;
        // sum final integer value store karega

        for(int i = 0; i < s.length(); i++){
            int curr = value(s[i]);
            // Current character ki value nikaali

            if(i + 1 < s.length() && curr < value(s[i + 1])){
                // i + 1 < s.length() safety check hai
                // Warna last character pe s[i + 1] out-of-bounds hota
                
                // curr < next ka LOGIC:
                // Ye character subtraction prefix ka hissa hai (IV, IX, XL, XC, CD, CM) -> only possible subtractions] -> Agar current value, next value se chhoti hai
                // to current ko SUBTRACT karna hai

                // "CM" example: C(100) < M(1000) -> C ko -100
                // phir M ko +1000 -> total: 900. No correction math needed
                num -= curr;
            }
            else{
                // Normal case: value add karo
                num += curr;
            }
        }
        return num;
    }

    int value(char c){
        // har roman symbol ko Integer me convert karta hai
        // Switch-case/ if-chain ek hi jagah centralized hai
        // Isse main loop clutter-free rehta hai

        if(c == 'I') return 1;
        if(c == 'V') return 5;
        if(c == 'X') return 10;
        if(c == 'L') return 50;
        if(c == 'C') return 100;
        if(c == 'D') return 500;
        return 1000; // 'M'
    }
};

/*

eg. "MCMXCIV"
    M(1000): next C(100), 1000 < 100? No -> +1000
    C(100): next M(1000), 100 < 1000? yes -> -100
    M(1000): next X(10), 1000 < 10? No -> +1000
    X(10): next C(100), 10 < 100? yes -> -10
    C(100): next I(1), 100 < 1? No -> +100
    I(1): next V(5), 1 < 5? yes -> -1
    V(5): last char -> +5
    Total = 1000 - 100 + 1000 - 10 + 100 - 1 + 5 = 1994

My version was "first adding, then correcting"
This version "first decides the right sign"
Both versions are correct, second one is 1 single if instead of 7 repetitive blocks 

TC -> O(n) (string ki har character ke liye ek constant-time value() call + comparison) | SC -> O(1)

*/