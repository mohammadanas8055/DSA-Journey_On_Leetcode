class Solution {
public:
    int reverse(int x) {
        int rev = 0;
        // rev me reversed number step-by-step build hoga

        while(x != 0){
            // Note: x != 0(not x > 0) use kiya hai kyunki negative numbers me bhi modulo (%) C++ me correctly negative remainder deta hai
            // Example: -123 % 10 = -3

            int digit = x % 10;
            // Last digit extract kar li

            // ===============================================
            // OVERFLOW PREVENTION CHECK (32-bit Constraint)
            // ===============================================
            // Next step me ham 'rev = rev * 10 + digit' karne wale hain

            // Agar rev > INT_MAX / 10 (yani > 214,748,364) ho chuka hai
            // to * 10 karte hi value 2,147,483,640 se upar nikal jayegi(2,147,483,650 or greater)
            // aur 32-bit integer limits (INT_MAX = 2,147,483,647) ko CROSS kar jayegi

            // Same logic negative side ke liye: rev < INT_MIN / 10

            // Isliye overflow hone se PEHLE hi return 0 kar do
            x = x / 10;
            if(rev > INT_MAX / 10 || rev < INT_MIN / 10){
                return 0;
            }
            rev = rev * 10 + digit;
            // Safe zone me hain, new digit ko units place par attach kar do
        }
        return rev;
        // Completely reversed valid 32-bit integer return kar diya
    }
};

/*

TC -> O(log10|x|) ≈ O(1) {Max 10 digits in 32-bit})
SC -> O(1)

One small check:
if(rev > INT_MAX / 10 || (rev == INT_MAX / 10 && digit > 7))
Par code pass ho gaya 
Math Reason:
. 32-bit signed integer ki maximum value 2,147,483,647(first digit is 2) hoti hai
. Agar 10-digit ka integer x valid 32-bit int hai, to uska first digit max-to-max 1 ya 2 hi ho sakta hai
. Matlab reverse hote waqt aakhri digit HAMESHA 1 ya 2 hi hoga - wo kabhi 7 ya 8 tak pahunch hi nahi sakta
. Isliye rev > INT_MAX / 10 wala single check 100% mathematically sufficient hai

*/