class Solution {
public:
    string reversePrefix(string word, char ch) {
        for(int i = 0; i < word.length(); i++){
            // left to right traverse kar rahe hain
            // taaki ch ka first occurence mile

            if(word[i] == ch){
                // Jaise hi first occurence mila
                // hame prefix [0......i] ko reverse karna hai

                int left = 0;
                int right = i;
                // reverse sirf prefix me hoga
                // isliye right = i set kiya, poori string end nahi

                while(left < right){
                    swap(word[left], word[right]);
                    // Prefix ke dono ends ke characters exchange kar diye

                    left++;
                    right--;
                    // Reverse karte hue pointers ko center ki taraf move kar diya 
                }
                break;
                // First occurence milte hi kaam khatam
                // Break isliye zaroori hai, warna agar same character baad me phir milta
                // to galti se aur aage tak reverse kar dete
            }
        }
        return word;
        // Agar ch mila tha, modified string return hogi
        // Agar ch kabhi mila hi nahi, to original unchanged string return ho jaayegi
    }
};

/*

ch ka first occurence dhoondho
us index tak prefix reverse karo
agar ch na mile, string unchanged return kar do

break is important because first occurence chahiye, uske baad nahi 

TC -> O(n) (First loop at most n tak jaa sakta hai, reverse part bhi at most n characters ka half process karega) -> Overall linear | SC -> O(1)

we can use reverse(word.begin(), word.begin() + i + 1); too

*/