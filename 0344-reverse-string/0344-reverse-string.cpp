class Solution {
public:
    void reverseString(vector<char>& s) {
        int i = 0; 
        // i left pointer hai
        // Ye string/vector ke start ke chalega
        // aur left side ka current character represent karega

        int j = s.size() - 1;
        // j right pointer hai
        // Ye vector ke last valid index se start karega
        // aur right side ka current character represent karega

        while(i < j){
            // Reverse karte waqt hame sirf tab tak swap karna hota hai
            // jab tak left pointer right pointer se pehle ho
            
            // Why i < j?
            // Agar i == j ho gaya -> dono pointers same middle element par hain
            // Middle element ko khud se swap karne ka fayeda nahi 
            // Agar i > j ho gaya, to matlab pointers cross kar chuke 
            // Aur reversing logically complete ho chuki hai

            // Isliye strict i < j hi correct stop condition hai

            swap(s[i], s[j]);
            // Left aur right side ke characters exchange kar diye
            
            i++;
            // Left pointer ko ek step aage badha diya

            j--;
             // Right pointer ko ek step peeche le aaye
        }
        // Function void hai, isliye kuch return nahi karna.
        // Vector in-place modify ho chuka hai.
    }
};

/*

TC -> O(n) (O(n/2)) | SC -> O(1)

*/