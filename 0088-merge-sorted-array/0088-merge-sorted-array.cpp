class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m - 1;
        int j = n - 1;
        int pos = m + n - 1;
        while(j >= 0){
            if(i >= 0 && nums1[i] > nums2[j]){// If nums1 still has elements left, and its current element is bigger, place it. Otherwise, place nums2’s current element.
            /* 
               There are two questions:
               1. Does nums1 still have valid real elements?
               2. If yes, is nums1[i] bigger than nums2[j]?
            */
                nums1[pos] = nums1[i];
                i--;
            }
            else{ // numbers equal hone ka case bhi yahan aa gaya, taaki nums2 se equal wala element aaya, nums1 wala pehle hi se rahega usse pehle . Aur ye wala case bhi jab nums1 exhaust ho gaya
                nums1[pos] = nums2[j]; 
                j--;
            }
            pos--;
        }
    }
};

/*

Time Complexity: O(m + n)
Space Complexity: O(1)

jo bada hai dono ke ends se shuru karte hue, usko nums1 ke last position pe place karna hai, ending with j >=0
- start from end of valid nums1
- start from end of nums2
- fill from back using pos

Why From the back?
If you try to merge from the front, you get a problem. Suppose you compare 1 and 2, okay. But then if you need to insert something into the front area, you may overwrite original values in nums1 before using them.
So, back side -> because that has empty space

kyunki dono array sorted hain, to jab tak nums2 se element khatam nahi ho jate, tab tak hi(compare karte hue) elements ko place karna hai, uske baad to nums1 sorted hi rahega
isliye condition j >= 0
agar dono i >= 0 aur j >= 0 ko consider kar lete to tab bhi chalta rahega loop even if i ya j negative ho jayega 
aur phir nums1[i] / nums2[j] -> invalid access

You only need to actively place elements from nums2.
Why?
If nums2 is finished, remaining nums1 elements are already in correct place.
Because jab tak nums2 ke elements bache hain, tab tak kaam karna hai.

while nums2 has elements left:
    if nums1 has elements left AND nums1[i] is bigger:
        place nums1[i]
        i--
    else:
        place nums2[j]
        j--
    pos--

nums1 ke pass elements bache bhi to hon, place karne ke liye, to wo condition bhi usi ke sath lagani hai, ki kon bada hai aur kon chota

if(i >= 0 && nums1[i] > nums2[j])
pehle i >= 0 hoga, SHORT CIRCUITING ke liye (C++ evaluates && left to right)
agar nums1[i] > nums2[j] check kara, aur i negative tha -> invalid access
isliye pehle i >= 0 -> agar false ho gaya, to invalid access hoga nahi agle wale expression me

else me -> nums2[j] hi bada/barabar hoga, ya i negative hoga, matlab nums1 me koi elements nahi bache hain

Therefore, finally, Loop should depend on j, because only nums2 must be fully inserted. If nums1 elements remain, they are already in correct place.

*/