class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int count = 0; // count stores kitne numbers me even number of digits hain

        // if digits would have been declared here,  digits never get reset and gets acculmulating across numbers
        // isliye loop ke andar rakhna hoga digits = 0
        // taki har number ke liye 0 se digits count hon

        for(int i = 0; i < nums.size(); i++){
            int digits = 0; // Current number ke digits count karne ke liye

            int temp = nums[i]; // Isse nums array destroy nahi hoga, current number ko dusre variable me store kar liya

            // while(temp != 0){ // isme ye catch hai ki number agar 0 ho to digit 0 hi reh jayega, par yahan okay hai kyunki numbers positive hain
            //     digits++;
            //     temp /= 10;
            // }
            // so FIX -> if(temp == 0){digits = 1;} else{}; 
            //        -> OR do while

            do{
                digits++;
                temp /= 10; // Har baar number ko 10 se divide karne par
                            // ek last digit remove ho jaati hai
                            // isliye loop jitni baar chalega, utne digits honge
            }while(temp != 0); // do-while ensures loop runs at least once
                               // so even if number is 0, digits become 1

            if(digits % 2 == 0){
                count++; // agar digits even -> count increase
            }
        }
        return count; // final even-digit numbers ka count return
    }
};

/*

this is TC O(n) only and not O(n^2)
because the inner while loop is not running n times for every element
it runs according to the number of digits in that number
to O(n*d) ho jayegi complexity , where d is from 1 to 10^5
to d constant 
to O(n) hi ho gayi TC 

aur SC O(1)  

Small general case note: if n = 0, this gives digits = 0, but digit count of 0 should be 1. LeetCode 1295 has positive numbers, so it’s fine.

*/