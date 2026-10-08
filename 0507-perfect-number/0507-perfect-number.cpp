class Solution {
public:
    bool checkPerfectNumber(int num) {
        // EDGE CASE: 1 is NOT a perfect number
        // Definition: sum of all positive divisors EXCLUDING the number itself
        // For num = 1, its only divisor is 1(which is itself), so proper divisor sum = 0 != 1
        if(num == 1) return false;

        // Initialize sum with 1, because '1' is a proper divisor for all numbers > 1
        // This allows us to start our loop from i = 2
        int sum = 1;

        //SQRT(N) DIVISOR PAIRING PROPERTY:
        // Divisors always exist in pairs(e.g. for 28: 2 & 14, 4 & 7)
        // If we find one divisor 'i', we automatically know the paired divisor 'num / i'
        // Therefore, we only need to search up to sqrt(num), i.e. i * i <= num
        for(int i = 2; i * i <= num; i++){

            // Check if 'i' is a factor/divisor of 'num'
            if(num % i == 0){
                sum += i; // Add the smaller divisor

                // SAFETY CHECK FOR PERFECT SQUARES:
                // if num = 36 and i = 6, then num / i = 6
                // We should only add '6' ONCE, not twice
                if(i != num / i){
                    sum += num / i; // Add the larger paired divisor 
                }
            }
        }

        // A number is Perfect if the sum of its proper divisors equals the number itself
        return sum == num;
    }
};

/*

TC -> O(sqrt(N)) | SC -> O(1)

*/