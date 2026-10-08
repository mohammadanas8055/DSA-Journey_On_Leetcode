/*

class Solution {
public:
    int fib(int n) {
        // BASE CASE 1:
        // Fibonacci sequence starting: 0th term is 0
        // Jab n == 0 ho jaye, to further break karne ki zaroorai nahi hai
        if(n == 0){
            return 0;
        }

        // BASE CASE 2:
        // 1st term is 1
        // Jab n == 1 ho jaye, tab bhi exact answer pata hai, isliye return 1
        if(n == 1){
            return 1;
        }

        // RECRSIVE STEP:
        //Nth Fibonacci number nikalne ke liye pichle do numbers(n - 1 and n - 2) ka sum chahiye
        // Function khud ko hi smaller sub-problems ke liye call karta hai
        else{
            return fib(n - 1) + fib(n - 2);
        }
    }
};

TC -> O(2^n) 
har ek fib(n) call aage 2 nay ecalls karta hai(2^0 + 2^1 + ..... + 2^n = O(2^n) | SC -> O(n) (C++ uses Call Stack internally to track recursive calls)

*/

class Solution{
public: 
    int fib(int n){
        // BASE CASES:
        // Fibonacci definition ke according:
        // F(0) = 0
        // F(1) = 1
        // Agar n 0 ya 1 hai, to seedha return kar do.
        // Isse loop me ghusne ki zaroorat nahi padti.
        if(n <= 1){
            return n;
        }

        // a = F(i-2)  [do steps peeche wala Fibonacci number]
        // b = F(i-1)  [ek step peeche wala Fibonacci number]
        //
        // Starting values:
        // a = F(0) = 0
        // b = F(1) = 1
        //
        // Hum sirf pichle DO numbers ko yaad rakhte hain.
        // Poori array store karne ki zaroorat nahi padti.
        // Isliye Space Complexity O(1) rehti hai.
        int a = 0, b = 1;
        
        // c temporary variable hai jo current Fibonacci number store karega:
        // c = F(i) = F(i-1) + F(i-2) = b + a
        int c;

        // Loop i = 2 se n tak chalega.
        // Kyunki F(0) aur F(1) already base cases me handle ho chuke hain.
        // Har iteration me hum next Fibonacci number calculate karte hain.
        for(int i = 2; i <= n; i++){

            // Current Fibonacci number:
            // F(i) = F(i-1) + F(i-2)
            // Yani b + a
            c = a + b;

            // Ab window aage shift karte hain:
            //
            // Pehle:
            // a = F(i-2)
            // b = F(i-1)
            // c = F(i)
            //
            // Agli iteration ke liye:
            // a ko F(i-1) banana hai  → a = b
            // b ko F(i) banana hai    → b = c
            //
            // Order bahut important hai:
            // Pehle a = b karo, phir b = c.
            // Agar reverse order me karoge to purana b lose ho jayega.
            a = b;
            b = c;
        }

        // Loop ke baad b me F(n) pada hota hai.
        // Kyunki last update me b = c = F(n) hua tha.
        return b;
    }
};

/*

TC -> O(n) | SC -> O(1)

*/