class Solution {
public:
    string largestOddNumber(string num) {
        // ===============================================
        // RIGHT-TO-LEFT SCANNING FOR RIGHTMOST ODD DIGIT
        // ===============================================
        // Number ki overall value largest rakhne ke liye hame left side ke zyada se zyada digits retain karne hain
        // Number ODD tabhi banega jab uska LAST character ODD digit('1', '3', '5', '7', '9') ho
        // isliye ham rightmost odd digit dhundhne ke liye string ko peeche(End) se scan karte hain

        for(int i = num.length() - 1; i >= 0; i--){

            // ASCII trick: (char - '0') converts char digit to int digit
            // (num[i] - '0') % 2 != checks if the digit is ODD
            if((num[i] - '0') % 2 != 0){

                // Found the rightmost odd digit at index 'i'!
                // Index '0' se 'i' tak ki substring hi sabse badi odd string hai
                // Length of substring from 0 to i = (i + 1)

                // In-place optimization:
                // num.resize(i + 1) index 'i + 1' ke aage ke saare even digits ko cut kar deta hai without allocating any new string O(1) auxiliary space
                num.resize(i + 1);
                return num;
            }
        }
        // Agar puri string scan hone ke baad bhi ek bhi ODD digit nahi mila(eg. "2468")
        // to koi bhi odd number substring nah iban sakti. Return empty string
        return "";
    }
};