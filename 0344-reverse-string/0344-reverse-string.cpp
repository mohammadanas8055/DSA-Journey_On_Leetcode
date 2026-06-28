class Solution {
public:
    void reverseString(vector<char>& s) {
        int i = 0; 
        int j = s.size() - 1;
        while(i < j){
            char temp = s[i]; // Ek character ko change karna hai to char use karenge
                              // Also arrays ke jaise elements ko access kar sakte, name[i] se
            s[i] = s[j];
            s[j] = temp;
            i++;
            j--;
        }
    }
};

/*

Time Complexity -> O(n) (Loop runs n/2 times)
Space complexity -> O(1)

*/