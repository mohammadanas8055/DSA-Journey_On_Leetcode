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
        if(n <= 1){
            return n;
        }
        int a = 0, b = 1, c;
        for(int i = 2; i <= n; i++){
            c = a + b;
            a = b;
            b = c;
        }
        return b;
    }
};

/*

TC -> O(n) | SC -> O(1)

*/