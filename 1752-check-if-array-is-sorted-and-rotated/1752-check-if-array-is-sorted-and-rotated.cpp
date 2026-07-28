/*

Ek ek karke rotate kar ke sorted check nahi kar sakte
Aur na minimum check karke phir check karen uske baad sorted hai, aur phir shuru se bhi sorted hai ki nahi, ye bhi nahi kar sakte
Kyunki multiple minimum ho sakte hain

Main observation:
Agar array originally sorted non-decreasing thi, aur usko rotate kiya gaya hai, to "circular" traversal me - sirf EK JAGAH aisa ho sakta hai jahan order tootega
Matlab nums[i] > nums[i + 1] sirf ek baar true ho sakti at most

So find -> kitni jagah descending drop aa raha hai (break point) -> (big element -> small element)

Circular sorted sequence sochna hai
- usme sab jagah order increasing/non-decreasing rahega
- except exactly one place where biggest element se smallest element par wrap hota hai
That wrap point is the single allowed drop

Agar circular na socha 
to uska counter eg. [2, 1, 3, 4]
2 > 1 (1 drop)
1 <= 3 (good)
3 <= 4 (good)
par ye nahi hai sorted and rotated
kyunki last element bada hai first element se

If an array was originally sorted, the last element in the rotated array must be smaller than or equal to the first element. Why? Because the elements at the end used to be in the middle, and the elements at the front used to be at the very end (largest).

So a valid array will have exactly 1 drop(or 0 if all elements are identical)

*/

class Solution {
public:
    bool check(vector<int>& nums) {
        int n = nums.size();
        int decreaseCount = 0;
        // decreaseCount count karega ki pure array me kitni baar
        // strictly decrease ho raha hai order(yani break point)

        for(int i = 0; i < n; i++){
            // Circular traversal ke liye (i + 1) % n use karenge
            // Jab i last index (n - 1) hoga, tab (i + 1) % n = 0 ho jayega
            // isse last element ko pehle element se compare karna easy ho jata hai

            if(nums[i] > nums[(i + 1) % n] ){
                decreaseCount++;
            }
        }
        if(decreaseCount > 1){
            return false;
        } 
        // This can be written inside the for loop only
        // Agar decreaseCount 1 se zyada ho gaya
        // to array kabhi sorted + rotated nahi ho sakti 

        return true;
        // Agar decreaseCount 0 h ai(sabe same values) ya 1 hai
        // to array valid sorted + rotated hai
    }
};

/*

Last index ke liye special case banane ke bajaye % n use kar sakte

% n isliye lagaya kyunki last element ke liye next element pehla element hoga
to i = n - 1 -> so i + 1 = n to invalid access ho jayega 
n % n = 0 -> pehla element 
baaqi sab me i + 1 < n 
so  n se chota number % n = chota number only(yani next element)

To jab jab count break hoga, count badha do
maximum 1 hi baar hoga agar originally sorted hogi

TC -> O(n) | SC -> O(1)

*/