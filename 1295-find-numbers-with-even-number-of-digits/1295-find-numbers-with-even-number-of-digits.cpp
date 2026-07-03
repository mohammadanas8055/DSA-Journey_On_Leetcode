class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int count = 0;
        // if declaring here,  digits never get reset and gets acculmulating across numbers
        // isliye loop ke andar rakhna hoga digits = 0
        // taki har number ke liye 0 se digits count hon
        for(int i = 0; i < nums.size(); i++){
            int n = nums[i];
            int digits = 0;
            while(n > 0){
                digits++;
                n = n / 10;
            }
            if(digits % 2 == 0){
                count++;
            }
        }
        return count;
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

*/