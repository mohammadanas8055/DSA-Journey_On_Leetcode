class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> heavy;
        // priority_queue by default max-heap hoti hai in C++
        // Isliye top() hamesha sabse bada element dega

        for(int i = 0; i < stones.size(); i++){
            heavy.push(stones[i]);
            // Saare stones heap me daal diye
            // Taaki baar baar largest stone efficiently mil sake
        }

        while(heavy.size() > 1){ // Jab tak kam se kam 2 stones hain
                                 // tab tak smash operation possible hai

            int heaviest = heavy.top();
            heavy.pop(); // Sabse bada stone nikala
                         // O(logn)

            int secondHeaviest = heavy.top();
            heavy.pop(); // Doosra sabse bada stone nikaala
                         // O(logn)
                         
            // if(heaviest - secondHeaviest == 0){
            //     continue;
            // }
            // heavy.push(heaviest - secondHeaviest);
            // Instead of repeated subtraction

            if(heaviest != secondHeaviest){ // Agar dono equal nahi the 
                                            // to bacha hua difference wapas stone bankar heap me jaayega
                                            // Agar same weight hai, to dono stones destroy ho gaye
                                            // Us case me kuch push nahi karna
                heavy.push(heaviest - secondHeaviest); //O(logn)
            }
        } // worst case, loop runs around n times -> total loop cost -> O(nlogn)

        if(heavy.empty()){
            return 0;
            // Agar koi stone nahi bacha(eg. 1 and 1 in last -> priority_queue empty) -> answer 0
        }

        return heavy.top(); // Agar ek stone bacha hai, wahi final answer hai
    }
};

/*

> I repeatedly need the 2 largest elements
That naturally points to:
max heap / priority_queue
Jab tak 2 ya usse zyada stones hain:
- 2 largest nikaalo
- agar equal nahi hain to difference wapas push karo
End me:
- heap empty -> 0
- warna top -> last stone weight

TC -> O(nlogn) (Each push takes O(logn), so total O(nlogn)) | SC -> O(n) (because priority_queue stores all stones)

Pattern:
“Repeatedly need largest/smallest element”
→ think priority_queue / heap

*/