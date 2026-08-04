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
                // or count = 1;
            }
            else if(count == 1){
                // Agar duplicate hai first ke to skip(done above)
                // ab tak sirf first filled hai, ya to first se bada hoga
                // ya first se chhota hoga

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
                // or count = 2;
            }
            else if(count == 2){
                // if duplicate of first or second, skip
                // ab tak first aur second valid hain
                // teesra distinct number aaya hai

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
                    // so put in third directly
                    third = nums[i];
                }
                count++;
                // or count = 3;
            }
            else{
                // count == 3
                // teeno shelves already filled hain
                // ab sirf standard shifting logic chalega

                if(nums[i] > first){
                    third = second;
                    second = first;
                    first = nums[i];
                    // new largest mil gaya -> sab shift down
                }
                else if(nums[i] > second){
                    third = second;
                    second = nums[i];
                    // new second largest mila
                }
                else if(nums[i] > third){
                    third = nums[i];
                    // new third largest mila
                }
                // agar x third se bhi chhota hai, to ignore
                // yahan count badhane ki zaroorat nahi hai
                // sirf teen hi shelf ka count rakhna tha
                // ya to count = 0 ya count = 1 ya count = 2 ya count = 3
            }
        }

        // Agar 3 distinct shelves fill ho gayi hain
        // to third distinct maximum return karna hai
        // warna problem ke according maximum return hoga
        return (count == 3) ? third : first;
    }
};

/*

Option 3: Boolean flags method
Every shelf gets its own "Occupied sign"(a boolean flag)

Whenever checking a number, we don't just check if it's bigger, we also check if the shelf is even occupied

*/

// class Solution{
// public:
//     int thirdMax(vector<int>& nums){
//         int first = 0;
//         int second = 0;
//         int third = 0;
//         bool hasFirst = false;
//         bool hasSecond = false;
//         bool hasThird = false;
//         // Yahan values ke saath saath ham explicitly track kar rahe hain
//         // ki shelf filled hai ya nahi
//         // isse initialization dummy value se problem nahi hoti

//         for(int i = 0; i < nums.size(); i++){
//             if((hasFirst && nums[i] == first) || (hasSecond && nums[i] == second) || (hasThird && nums[i] == third)){
//                 continue;
//             }
//             // Duplicate tabhi compare karna hai jab respective shelf filled ho

//             if(!hasFirst || nums[i] > first){
//                 // Agar first shelf empty hai ya current first se bada hai
//                 // to nums[i] new largest banega

//                 if(hasSecond){
//                     third = second;
//                     hasThird = true;
//                     // old second ko third me shift karna zaorori hai
//                     // before second overwrite ho
//                 }

//                 if(hasFirst){
//                     second = first;
//                     hasSecond = true;
//                 }

//                 first = nums[i];
//                 hasFirst = true;
//             }
//             else if(!hasSecond || nums[i] > second){
//                 // yahan nums[i] first se bada nahi hai
//                 // but second shelf empty ho sakti hai
//                 // ya current second se bada ho sakta hai

//                 if(hasSecond){
//                     third = second;
//                     hasThird = true;
//                     // existing second ko third me shift karo
//                     // before second overwrite ho
//                 }

//                 second = nums[i];
//                 hasSecond = true;
//             }
//             else if(!hasThird || nums[i] > third){
//                 // yahan nums[i] first aur second dono se chhota hai
//                 // but third shelf empty ho sakti hai
//                 // ya current third se bada ho sakta hai

//                 third = nums[i];
//                 hasThird = true;
//             }
//             // agar nums[i] third se bhi chhota hai, to ignore
//         }

//         // Agar third shelf filled hai, third distinct maximum exist karta hai
//         // warna maximum return karna hai
//         return hasThird ? third : first;
//     }
// };

/*

> Main observation:
first shelf me koi real value hai ya nahi
second shelf me koi real value hai ya nahi
third shelf me koi real value hai ya nahi

eg. [2,2,3,1]
first = 0, second = 0, third = 0, hasFirst = false, hasSecond = false, hasThird = false
Shelves actually me empty hain
nums[0] = 2
if(!hasFirst || nums[i] > first) -> !hasFirst -> first shelf empty hai
So directly current number first band sakta hai
first = 2, second = 0, third = 0, hasFirst = true, hasSecond = false, hasThird = false

nums[1] = 2
Duplicate check -> hasFirst = true && nums[i] == first -> skip 
hasFirst && needed because if shelf empty hoti, then us dummy value se compare nahi karna chahiye

nums[2] = 3
if(!hasFirst || nums[i] > first) -> hasFirst = false(Because first shelf filled hai)
nums[i] > first -> true
so 3 new largest banega
To ab old first ko second me shift karna hoga 
if(hasSecond) nahi chalega kyunki hasSecond = false;

then if(hasFirst) -> this runs because old first exists 
so second = 2, hasSecond = true 
then first = 3, hasFirst = true;
first = 3, second = 2, third = 0, hasFirst = true, hasSecond = true, hasThird = false

nums[3] = 1 
if(!hasFirst || nums[i] > first) -> false(first me hai bhi element, aur na current element use replace hi kar sakta hai)
second condition
if(!hasSecond || nums[i] > second) -> false
third condition
if(!hasThird || nums[i] > third) -> true(third me nahi hai kuch, to ab naya distinct third me aa jayega)
third = 1;
hasThird = true;
first = 3, second = 2, third = 1, hasFirst = true, hasSecond = true, hasThird = true

now, hasThird = true, to third ko return kar diya

if(hasFirst && nums[i] == first) means: Duplicate check tabhi valid hai jab first shelf actually filled ho
                                        Agar first ke barabar na ho to aage check karte hain(hasSecond ho bhi aur phir same check karen)
                                        similarly, proceed to third if not equal to second and hasThird = true
if(!hasFirst || nums[i] > first) means: "If first shelf empty hai OR current number top shelf se better hai"
if(hasSecond) means: Old second ko third me shift sirf tabhi kar sakte ho jab second shelf filled thi
Similarly, jab first me raha hoga, tabhi to usko first me shift karenge
phir new value ko first me overwrite kar denge
phir aage badhega, agar second se bada hoga, to second me overwrite karna hai
agar second me pehle se tha to third me jayega wo, aur phir second me overwrite to hona hi hai
aur phir agar sirf third se bada hai, to seedhe overwrite kar dena hai

TC -> O(n) | SC -> O(1)

*/

/*

class Solution {
public:
    int thirdMax(vector<int>& nums) {
        int first = 0, second = 0, third = 0;
        // Ye 3 variables shelves ki tarah hain:
        // first  = largest distinct value
        // second = second largest distinct value
        // third  = third largest distinct value
        //
        // Inki initial value 0 abhi "real answer" nahi hai.
        // Real ya fake hone ka decision flags karenge.

        bool hasFirst = false, hasSecond = false, hasThird = false;
        // Ye 3 flags batate hain ki shelf actually filled hai ya nahi.
        //
        // hasFirst = false means:
        // first variable me jo bhi pada hai (abhi 0), usse serious mat lo.
        // Shelf empty hai.
        //
        // Same logic second and third ke liye.

        for (int x : nums) {
            // Har number ko ek-ek karke process karenge.

            if ((hasFirst && x == first) ||
                (hasSecond && x == second) ||
                (hasThird && x == third)) {
                continue;
            }
            // Duplicate skip karna zaroori hai because problem DISTINCT maximum maang raha hai.
            //
            // Dhyan do: x == first tabhi compare kar rahe hain jab hasFirst true ho.
            // Agar hasFirst false hai, to first me pada hua 0 sirf dummy hai.
            // Us dummy 0 ko actual duplicate nahi maana ja sakta.

            if (!hasFirst || x > first) {
                // Do possibilities:
                // 1. first shelf empty hai -> x ko first me daal do
                // 2. x current first se bada hai -> x new largest banega
                //
                // In dono cases me x ko first shelf me jaana hai.

                if (hasSecond) {
                    third = second;
                    hasThird = true;
                    // Agar second shelf me koi real value thi,
                    // aur ab x first banne ja raha hai,
                    // to old second ko third me shift karna padega.
                    //
                    // Ye line first ko overwrite karne se pehle isliye nahi,
                    // balki second ko lose hone se bachane ke liye hai.
                }

                if (hasFirst) {
                    second = first;
                    hasSecond = true;
                    // Agar first shelf me koi real value thi,
                    // to wo ab second shelf me shift hogi
                    // kyunki x new largest ban raha hai.
                }

                first = x;
                hasFirst = true;
                // Ab x officially largest distinct value ban gaya.
            }
            else if (!hasSecond || x > second) {
                // Yahan tak aane ka matlab:
                // x first se bada nahi hai
                // (warna pehle if me chala jaata)
                //
                // Ab 2 possibilities:
                // 1. second shelf empty hai -> x ko second me daal do
                // 2. x second se bada hai -> x new second banega

                if (hasSecond) {
                    third = second;
                    hasThird = true;
                    // Agar second me pehle se real value thi,
                    // aur x uski jagah le raha hai,
                    // to old second ko third me shift karna hoga.
                }

                second = x;
                hasSecond = true;
                // x ab official second largest distinct value hai.
            }
            else if (!hasThird || x > third) {
                // Yahan tak aane ka matlab:
                // x first se bada nahi
                // x second se bada nahi
                //
                // Ab 2 possibilities:
                // 1. third shelf empty hai -> x ko third me daal do
                // 2. x third se bada hai -> x new third banega

                third = x;
                hasThird = true;
                // x ab official third largest distinct value hai.
            }
            // Agar x third se bhi chhota hai,
            // to hame usse koi farq nahi padta.
            // Kyunki hame top 3 distinct maximums hi chahiye.
        }

        if (hasThird) {
            return third;
        }
        // Agar third shelf actually filled hai,
        // to third distinct maximum exist karta hai.
        // Wahi answer hoga.

        return first;
        // Agar third shelf kabhi fill hi nahi hui,
        // to 3 distinct numbers the hi nahi.
        // Problem ke according then maximum return karna hai.
    }
};

*/