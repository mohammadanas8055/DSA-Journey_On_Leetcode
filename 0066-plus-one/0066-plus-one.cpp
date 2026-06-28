class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        for(int i = digits.size() - 1; i >= 0; i--){
            if(digits[i] < 9){
                digits[i] = digits[i] + 1;
                return digits; // yahan break laga ke koi matlab nahi hai, nahi to phir loop se bahar nikalne par(all-9s case me) 1 kaise add karenge, is wale me bhi add ho jayega na, phir result return hoga, isse acha is case ka return yahin kar den, phir all-9s case me loop se bahar nikal ke 1 shuru me add kar den(Manually or using STL Iterator, insert)
            }
            else{
                digits[i] = 0;
            }
            // How to insert??
        }
        digits.insert(digits.begin(), 1);
        return digits;
    }
};

/*

Time complexity is O(n) if all 9s, else O(1)
Average O(n)
Space complexity is O(n) for all-9s cases(insert creates a new larger array), O(1) for normal cases

STL Iterators
digits.begin() = "iterator pointing to first element"
digits.end() = "iterator pointing AFTER last element"
digits.insert(position, value) inserts at that position
OR
Manually
vector<int> result(digits.size() + 1, 0); //Creates an array, all elements zero
result[0] = 1;
return result;

"Loop with early exit + handle the remaining case after"

This pattern appears in many problems:

Plus One (your problem)
Add to Number As Linked List
Multiply Strings
Many "simulation" problems

*/