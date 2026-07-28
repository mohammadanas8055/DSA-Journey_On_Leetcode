// class Solution {
// public:
//     bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
//         string s1;
//         string s2;
//         for(int i = 0; i < word1.size(); i++){
//             for(int j = 0; j < word1[i].length(); j++){
//                 s1.push_back(word1[i][j]);
//             }
//         }
//         for(int i = 0; i < word2.size(); i++){
//             for(int j = 0; j < word2[i].length(); j++){
//                 s2.push_back(word2[i][j]);
//             }
//         }
//         if(s1 == s2){
//             return true;
//         }
//         return false;
//     }
// };

/*

Here 
TC -> O(N * K) (N is number of words, K is length of words) -> O(Total characters) | SC -> O(Total characters) (Because we created two new strings)

So we need a O(1) Optimal approach
For which we need a driver and a passenger for each array
Pointer 1: Which word am i looking at
Pointer 2: Which character inside that word am I looking at

*/

class Solution{
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2){
        int w1 = 0;
        // word1 ke current string ka index

        int w2 = 0;
        // word2 ke current string ka index

        int c1 = 0;
        // word1[w1] ka current character ka index

        int c2 = 0;
        // word2[w2] ke current character ka index

        int m = word1.size();
        int n = word2.size();
        // dono vectors me total kitne strings hain

        while(w1 < m && w2 < n){
            // Jab tak dono sides me valid current word exist karta hai
            // tab tak character-by-character compare kar sakte hain

            if(word1[w1][c1] != word2[w2][c2]){
                return false;
                // Agar current characters mismatch ho gaye
                // to dono combined strings equal nahi ho sakte
            }
            c1++;
            c2++;
            // match mil gaya, isliye dono character pointers aage badha diye

            if(c1 == word1[w1].size()){
                w1++;
                c1 = 0;
                // Agar word1 ka current string pura ho traverse ho gaya
                // to next string par shift karo
                // aur character index reset kar do
            }
            if(c2 == word2[w2].size()){
                c2 = 0;
                w2++;
                // same logic for word2 
            }
        }
        return w1 == m && w2  == n;
        // loop ke baad true tabhi hoga jab dono vectors exactly ek saath khatam hue hon
        // agar ek vector khatam ho gaya but doosre me words bache hain
        // to strings equal nahi hain
    }
};

/*
while(w1 < m || w2 < n) likhenge to out of bounds ka rish hai number of characters different hone pe
to while(w1 < m && w2 < n) -> jaise hi koi sa khatam hua to exit 
dono sides valid honi chahiye na
uske baad return ensure karta hai no leftover words remain on either side

And now
agar ab tak same chalte chale aa rahe the words aur ab dusre vector me aur words the to tab wo to check hi nahi hue, False aana tha par true aa gaya
to ab answer ispe depend karega ki w1 khatam hue ki nahi, aur w2 hue ki nahi(matching to hote hue aa hi rahe hain upar se, agar macth na karte to upar hi false return ho jata)
loop khatam hone ka matlab hai ki dono me se koi ek(ya dono) vector khatam ho gaye
For equality, both must have finished exactly together
for eg. A = "abc" and B = "abcd"
w1 khatam, abc check karke bahar loop se
return true karenge to galat hoga, kyunki B me abhi characters bache hain

So, loop ke bahar aane ke baad, true sirf tabhi aana chahiye jab dono vectors puri tarah se ek saath khatam hue hon
Agar word1 puri tarah khatam ho gaya, to w1 kiske barabar hoga? -> m ke
Aur w2? -> n ke

TC -> O(total characters) | SC -> O(1)

*/