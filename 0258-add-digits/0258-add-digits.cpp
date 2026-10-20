class Solution{
public:
	int addDigits(int num){
		// Digital Root Formula (O(1) mathematical approach):
        // The repeated digit sum of any positive integer converges to its "digital root"
        // which follows a cyclic pattern of period 9: 1,2,3,4,5,6,7,8,9,1,2,3...

        // Case 1: Zero is a special case(digital root of 0 is 0, not 9)
        if(num == 0){
            return 0;
        }

        // Case 2: Already a single digit, no reduction needed
        if(num < 10){
            return num;
        }

        // Case 3: Multiples of 9 always have digital root = 9
        // (e.g., 18 -> 1 + 8 = 9, 27 -> 2 + 7 = 9, 99 -> 9 + 9 = 18 -> 1 + 8 = 9)
        if(num % 9 == 0){
            return 9;
        }

        // Case 4: All other numbers -> digital root = num % 9
        // (e.g., 38 % 9 = 2, and 3 + 8 = 11 -> 1 + 1 = 2)
        return num % 9;

        // One-liner alternative: return num == 0 ? 0 : 1 + (num - 1) % 9
	}
};

/*

TC -> O(1) | SC -> O(1)

*/