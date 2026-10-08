class Solution {
public:
    bool isPalindrome(int x) {
        // ===============================
        // EDGE CASE 1: Negative Numbers
        // ===============================
        // All negative numbers are NOT palindromes
        // Example: x = -121. Reverse ho kar "121-" banta hai
        // minus sign start me hota hai par reverse hone par end me chala jata hai
        // isliye negative numbers kabhi palindrome nahi ho sakte
        if(x < 0){
            return false;
        }

        int num = x;
        // Original x ki value save kar li 
        // Kyunki while loop me x ki value reduce ho kar 0 ho jayegi
        // isliye comparison ke liye original number ki copy hone zaroori hai

        int rev = 0;
        // Reversed number build karne ke liye

        while(x != 0){
            int digit = x % 10;
            // Current number ka last digit extract kiya

            x = x / 10;
            // Last digit ko number se drop kiya

            // ==================================
            // OVERFLOW CHECK (32-bit safety)
            // ==================================
            // Next step me `rev = rev * 10 + digit` karne wale hain
            // Agar rev pehle se hi INT_MAX / 10 se bada hai, to * 10 karte hi 32-bit integer overflow ho jayega

            // Agar overflow ho gaya, to wo number original x ke equal waise bhi nahi ho sakta(kyunki x khud ek valid 32-bit int hai)
            // isliye directly return false
            if(rev > INT_MAX / 10 || rev < INT_MIN / 10){
                return false;
            }

            rev = rev * 10 + digit;
            // Digit ko reversed number ke units place par attach kiya
        }
        return rev == num;
        // Agar reversed number original number ke equal hai, to number palindrome hai(eg. 121 == 121 -> true)
    }
};

/*

TC -> O(log10x)(loop maximum 10 iteration chalega -> O(1) constant time)
SC -> O(1)

*/

// Agar overflow check kiye(INT_MAX ka use kiye bina) karna ho to? 
// Trick: Pura number reverse karne ke bajaye sirf AADHA(HALF) number reverse karo!

/*

class Solution{
public:
    bool isPalindrome(int x){
        // Negative numbers aur 10 ke multiples(except 0) palindrome nahi ho sakte
        if(x < 0 || (x % 10 == 0 && x != 0)) return false;

        int rev = 0;
        // Jab tak rev x se chhota hai, aadha number reverse karte jao
        while(x > rev){
            rev = rev * 10 + x % 10;
            x /= 10;
        }    

        // Even digits(e.g. 1221 -> x = 12, rev = 12): x == rev
        // Odd digits (e.g. 12321 -> x = 12, rev = 123): x == rev / 10 (middle digit 3 drop ho gaya)
        return x == rev || x == rev / 10;
    }
};

TC -> O(log10 N/2) [<= 5 iterations] ~ O(1)

*/