class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int count = 0;
        // count me track kar rahe hain ab tak kitne flowers plant kar chuke hain
        // Jab ye n ke barabar ya usse zyada ho jaye, answer true

        int i = 0;
        // Current index jise ham check kar rahe hain flowerbed me

        int size = flowerbed.size();
        // size ko variable me store kar liya taaki baar-baar flowerbed.size() na likhna pade
        // Ye chhoti se optimization hai, aur code bhi cleaner lagta hai

        while(i < size){
            // Pure flowerbed ko traverse karenge

            if(flowerbed[i] == 0 && (i == 0 || flowerbed[i - 1] == 0) && (i == size - 1 || flowerbed[i + 1] == 0)){
                // 3 conditions ek saath check ho rahi hain (saari && se judi hain)

                // 1. flowerbed[i] == 0
                //    Current slot khali hona chahiye
                //    Kyunki filled slot par plant nahi kar sakte

                // 2. (i == 0 || flowerbed[i - 1] == 0)
                //    Left side safe hona chahiye
                //    Ya to current slot pehla hi ho(i == 0, koi left neighbor nahi)
                //    Ya left slot khali ho

                // 3. (i == size - 1 || flowerbed[i + 1] == 0)
                //    Right side safe hone chahiye
                //    Ya to current slot last ho(i == size - 1, koi right neighbor nahi)
                //    Ya right wala slot khali ho

                // Same short-circuit logic yahan bhi kaam karta hai
                // Agar i == size - 1 hai to flowerbed[i + 1] check nahi hoga

                flowerbed[i] = 1;
                // Yahan flower plant kar diya
                // Important: array ko actually update karna zaroori hai
                // Warna next iteration me left neighbor check galat ho jayega
                // Warna next iteration me left neighbor check galat ho jayega
                // (agla slot sochega left empty hai, jabki hamne mentally plant kar diya)

                count++;
                // Successfully ek flower plant hua, count badhaya

                i += 2;
                // Next slot par plant nahi kar sakte(adjacent ho jayega)
                // Isliye 2 steps aage jump kiya
                // Ye ek optimization hai - 1 step ka fayeda nahi jab hame pata hai next slot definitely reject hoga
            }
            else{
                i++;
                // Condition fail hui(kisi bhi reason se)
                // To sirf ek step aage badho aur next slot try karo
            }

            if(count >= n){
                return true;
                // Early termination:
                // Jaise hi required number of flowers plant ho gaye
                // aage check karne ki zaroorat nahi
                // Ye bade arrays ke liye kaafi faster hai
                // Ye bade arrays ke liye kaafi faster hai
            }
        }
        return false;
        // Pura array ghum liya, par n flowers plant paye
        // Matlab possible nahi hai
    }
};

/*

Core rule: No two flowers can be adjacent
To agar i par flower plant karna hai, to check karna padega:
. flowerbed[i] khud 0 hai
. flowerbed[i - 1] bhi 0 hai(ya i == 0)
. flowerbed[i + 1] bhi 0 hai(ya i == size - 1)
Sirf flowerbed[i] == 0 dekh ke count nahi badha sakte

So for each index i:
1. Is flowerbed[i] == 0(current slot empty)
2. Is left side empty(i == 0 or flowerbed[i - 1] == 0) (Left side safe)
3. Is right side empty(i == size - 1 or flowerbed[i + 1] == 0) (Right side safe)

If all 3 true -> plant here, det flowerbed[i] = 1, count++ and move i += 2(Kyunki next pe to place kar nahi sakte)
Else -> just i++(not i += 2)

Left/right boundary check important hai, Agar i == 0, to flowerbed[i - 1] access invalid ho jayega
Similarly, agar i == size - 1, to flowerbed[i + 1] invlaid access
flowerbed[i] = 1 kar ke next iteration me automatic check ho jayega

Short-circuit evaluation me i == 0, i == size - 1 true ho gaya, to flowerbed[i - 1] and flowerbed[i + 1] invalid access se bach jayega

TC -> O(size) | SC -> O(1)

*/