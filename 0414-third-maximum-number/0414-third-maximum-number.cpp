// class Solution {
// public:
//     int thirdMax(vector<int>& nums) {
//         long long first = -3000000000LL;
//         long long second = -3000000000LL;
//         long long third= -3000000000LL;
           // Start with 3 "empty" shelves(top 3 distinct shelves)
           // "empty" ko represent karne ke liye aisi value se initialize karo jo kisi real int input se chota hai
           // isse pata chalega ki shelf abhi "empty" hai ya filled
           // normal int into chota nahi hota(-2^31 = -2147483648 to 2^31 - 1 = 2147483647)
           // LL means "this number should be treated as a long long literal"
           // long long? -> -3000000000 normal int me fit nahi hota, but long long me fit ho jata hai

//         for(int i = 0; i < nums.size(); i++){
//             if(nums[i] == first || nums[i] == second || nums[i] == third){
               // Duplicate check must come first
               // Because problem asks for third distinct maximum

//                 continue;
//             }
//             if(nums[i] > first){
//                 third = second;
//                 second = first ;
//                 first = nums[i];
                   // Shifting order is important
                   // because when current number becomes new largest
                   // old first must not disappear
                   // it becomes second
                   // old second must not disappear
                   // it becomes third

                   // so save old second into third
                   // save old first into second
                   // put new number into first
//             }
//             else if(nums[i] > second){
               // This means current number is not biggest
               // but it is better than current second 
//                 third = second;
//                 second = nums[i];
                   // so old second drops to third
                   // current becomes new second
                   // first untouched rahega because current number usse bada nahi hai
//             }
//             else if(nums[i] > third){
               // it couldn't become first
               // it couldn't become second
               // but it is still better than current third
//                 third = nums[i];
                   // so only third shelf update hogi
//             }
//         }
//         if(third == -3000000000LL){
           // if third still equals the special "empty" marker, then third distinct maximum never got filled
           // That means array had fewer than 3 distinct values
           // so in that case return maximum, i.e. first
//             return first;
//         }
//         return third;
//     }
// };

/*

Most important trap -> Duplicates skip karo
And first, second and third should not be initialised as INT_MIN, because what if the array migh contain INT_MIN

Also shifting order is important
first se bada number mila to pehle third ko second banao, second ko first banao aur phir first ko wo number banao

TC -> O(n) | SC -> O(1)

Option 1: Use long long sentinels smaller than all int values
          (Agar 64 bits numbers hain to phir next two options) -> ABOVE
Option 2: Using count variable
          Jab bhi koi naya distinct number first/second/third me jaaye: count++
          End me agar count >= 3 -> third mila -> return third
          agar count < 3 -> third nahi mila -> return first
Option 3: Use boolean flags to track whether first/second/third are assigned

Or also the normal 3 scan method

All are TC -> O(n) | SC -> O(1)

*/

class Solution{
public: 
    int thirdMax(vector<int>& nums){
        int first = 0;
        int second = 0;
        int third = 0;
        // Instead of putting a weird fake number in the shelves, we just count how many distinct numbers we have seen so far
        // first, second, third are normal int variables. Their starting valued DO NOT MATTER 

        int count = 0;
        // tells how many shelves are legally occupied
        // count = 0 -> koi shelf filled nahi
        // count = 1 -> sirf first valid hai
        // count = 2 -> first and second valid hain
        // count = 3 -> first, second, third teeno valid hain

        for(int i = 0; i < nums.size(); i++){
            // if((count == 1 && nums[i] == first) || (count == 2 && (nums[i] == first || nums[i] == second)) || (count >= 3 && (nums[i] == first || nums[i] == second || nums[i] == third))){
            //     continue;
            // }
            // OR
            if((count >= 1 && nums[i] == first) || (count >= 2 && nums[i] == second) || (count >= 3 && nums[i] == third)){
                continue;
            }
            // second ko tabhi compare kar sakte hain jab count >= 2
            // third ko tabhi jab count >= 3
            // warna unki current values sirf dummy initialisation hain

            if(count == 0){ 
                // First number ever seen
                // Then put in it first directly

                first = nums[i];
                count++;
            }
            else if(count == 1){
                // Agar duplicate hai first ke to skip(done above)

                if(nums[i] > first){
                    // Agar first se bada hai, to second me first, aur first me naya number
                    second = first;
                    first = nums[i];
                }
                else{
                    // yani smaller hai first se
                    second = nums[i];
                }
                count++;
            }
            else if(count == 2){
                // if duplicate of first or second, skip

                if(nums[i] > first){
                    // if bigger than first, shift all down

                    third = second;
                    second = first;
                    first = nums[i];
                }
                else if(nums[i] > second){
                    // if between first and second, shift second down
                    third = second;
                    second = nums[i];
                }
                else{
                    // smaller than second
                    // so put in third
                    third = nums[i];
                }
                count++;
            }
            else if(count >= 3){
                if(nums[i] > first){
                    third = second;
                    second = first;
                    first = nums[i];
                }
                else if(nums[i] > second){
                    third = second;
                    second = nums[i];
                }
                else if(nums[i] > third){
                    third = nums[i];
                }
            }
        }
        if(count < 3){
            return first;
        }
        return third;
    }
};

/*

Option 3: Boolean flags method
Every shelf gets its own "Occupied sign"(a boolean flag)

Whenever checking a number, we don't just check if it's bigger, we also check if the shelf is even occupied


*/