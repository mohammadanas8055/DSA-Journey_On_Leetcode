// class Solution {
// public:
//     int numSpecial(vector<vector<int>>& mat) {
//         int totalCount = 0;
//         // totalCount final answer store karega
//         // kitni special positions mili
        
//         for(int i = 0; i < mat.size(); i++){
//             int count = 0;
//             // count current row me total kitne 1s hain, ye batayega

//             int col; 
//             // Agar row me exactly ek hi 1 mila,
//             // to uska column index yahan store rahega
//             // Uninitialised hai, par use hone se pehle col = j set ho jayega, jab count == 1 hoga(jab row me 1 milega)
//             // But cleaner style, int col = -1

//             for(int j = 0; j < mat[0].size(); j++){
//                 if(mat[i][j] == 1){
//                     count++;
//                     col = j;
//                     // Current row me 1 mila
//                     // count badhaya
//                     // aur uska column store kiya
                    
//                     // Agar row me multiple 1s milte hain
//                     // to col repeatedly update hota rahega
//                     // but that doesn't matter because
//                     // ham column check tabhi karenge jab count == 1 ho
//                     // us case me col = column where last 1 appears
//                     // to count 1 se bada hone pe row skip kar sakte hain
//                 }
//             }
//             if(count == 1){
//                 // Sirf wahi rows special position de sakti hain
//                 // jisme exactly ek hi 1 ho

//                 // Ab check karna hai ki jis column me ye 1 mila
//                 // kya us column me koi aur bhi 1 hai?
                
//                 for(int k = 0; k < mat.size(); k++){
//                     if(k != i && mat[k][col] == 1){
//                         count = 0;
//                         // Agar same column me kisi aur row me bhi 1 mila
//                         // to current cell special nahi ho sakta

//                         // count ko 1 se kam kar diya(ya equal to 0 kar diya) taaki baad me final if(count == 1) fail ho jaye

//                         // Ye code logically ek "invalid" marker ki tarah use ho raha hai
//                         break;
//                         // Ek baar column me extra 1 mil gaya
//                         // to aur scan karne ki zaroorat nahi
//                     }
//                 }
//             }
//             if(count == 1){
//                 // agar count abhi bhi 1 hai, iska matlab:
//                 // 1. current row me exactly ek hi 1 tha
//                 // 2. uske column me koi aur 1 nahi mila

//                 // To current row exactly ek special position contribute karti hai
//                 totalCount++;
//             }
//         }
//         return totalCount;
//     }
// };

/*

Row-by-row chalo, row me 1 count karo
count = row me kitne 1 hain
col = last seem 1 ka column index(Agar count == 1, tab col us specail candidate 1 ka column hoga)
Sirf tabhi column scan karo(agar row me exactly ek hi 1 tha, tabhi check meaningful hai ki uske column me aur koi 1 to nahi)
Agar another 1 mil gaya in same column(except the existing 1(k != i)), then this position special nahi ho sakti, so you reduce count(or count = 0)
Phir count 1 sirf tab bachega jab: row me xactly one 1 tha, aur column me bhi wahi only 1 tha
So that row contibutes exactly one special position

Instead of count, we could have used bool isSpecial = truevariable
Agar column me ek aur 1 mila: isSpecial = false

TC -> O(m * n + m * m) | SC -> O(1)

We can get a cleaner TC by precomputing 1s in all the rows and columns
*/

class Solution{
public:
    int numSpecial(vector<vector<int>>& mat){
        int m = mat.size();
        int n = mat[0].size();
        // m = total rows
        // n = total columns

        // Problem constraints ke according matrix non-empty hai
        // isliye mat[0].size() access safe hai

        int count = 0;
        // Final answer:
        // total kitne special positions mili

        vector<int> rowCount(m, 0);
        vector<int> colCount(n, 0);
        // rowCount[i] batayega:
        // i-th row me total kitne 1s hain

        // colCount[j] batayega
        // j-th column me total kitne 1s hain

        // Ye precomputation isliye useful hai because
        // special position ki definition exactly row-count and column-count par based hai:
        // a cell is special iff:
        // mat[i][j] == 1
        // rowCount[i] == 1
        // colCount[j] == 1

        for(int i = 0; i < m; i++){
            // Har row me traverse karenge

            for(int j = 0; j < n; j++){
                // Har column me traverse karenge
                if(mat[i][j] == 1){
                    rowCount[i]++;
                    colCount[j]++;
                    // Agar current cell 1 hai
                    // to is row me 1s ki count badhao
                    // aur is column me bhi 1s ki count badhao

                    // Ye line yahin likhi gayi hai because 
                    // ek hi 1 ek saath apni row aur apni column dono ko affect karta hai
                }
            }
        }


        for(int i = 0; i < m; i++){
            if(rowCount[i] == 1){ 
            // Optimization: If row diesn't have exactly one 1, skip it
            // This saves from checking colCount[j] for rows that are already invalid

                for(int j = 0; j < n; j++){
                    if(mat[i][j] == 1 && colCount[j] == 1){
                        count++;
                        // Current cell tabhi special hai jab:
                        // 1. khud cell ki value 1 ho
                        // 2. uski row me aur koi dusra 1 na ho -> rowCount[i] == 1
                        // 3. uski column me aur koi dusra 1 na ho -> colCount[j] == 1

                        // In 3 conditions ka combination exactly problem definition hai
                        // rowCount pehle hi check kar liya, agar 1 hai tabhi proceed kiya colCount check karne me
                    }
                }
            }
        }
        return count;
        // total special positions return kar di
    }
};

/*

Instead of "for each row, if exactly one 1 then scan its column", we first precompute: 
rowCount[i] = row i me kitne 1s hain
colCount[j] = column j me kitne 1s hain

Then second pass me har 1 ke liye simply ask: "Kya iske row me exactly 1 one hai? Kya iske column me exactly 1 one hai"
If both yes: special position mil gayi

first pass = information gather 
second pass = decision

mat[i][j] == 1 check again in second pass is needed
Because rowCount[i] == 1 and colCount[j] == 1 by themselves enough nahi hain
We still need to ensure current cell itself is the 1
Otherwise imagine rowCount/colCount conditions match for some indices, but current cell 0 ho
Phir wo 0 special thodi na ho jayega
So mat[i][j] == 1 must be checked

TC -> O(m * n) | SC -> O(m + n)

*/