// class Solution{
// public:
//     string frequencySort(string&s){
//         // Step 1: Count frequencies using ifxed 256-size array
//         // Array is faster than unordered_map for small bounded key ranges (ASCII)
//         int mpp[256] = {0};
//         for(int i = 0; i < s.length(); i++){
//             mpp[s[i]]++;
//         }

//         // Step 2: Bucket Sort - index = frequency, value = concatenated character
//         // bucket[f] stores all characters that appear exactly f times, repeated f times
//         // Size is s.length() + 1 because max possible frequency = length of string
//         vector<string> bucket(s.length() + 1);
//         for(int i = 0; i < 256; i++){
//             if(mpp[i] != 0){
//                 // string(count, char) creates a string with 'char' repeated 'count' times
//                 // e.g. string(3, 'e') = "eee"
//                 bucket[mpp[i]] += string(mpp[i], (char)i);
//             }
//         }

//         // Step 3: Iterate buckets from highest frequency to lowest
//         // No sorting needed - bucket index IS the frequency(already ordered)
//         string answer = "";
//         for(int i = s.length(); i >= 0; i--){
//             if(!bucket[i].empty()){
//                 answer += bucket[i]; // Append all characters with frequency i
//             }
//         }
//         return answer;
//     }
// };

/*

TC -> O(n) but with higher constant factor
SC -> O(n) 

So this is THEORETICALLY optimal, but not practically, due to the n + 1 heap allocations overhead

*/

class Solution{
public:
    string frequencySort(string& s){
        // Step 1: Frequency count using fixed 256-size array(covers full ASCII)
        // Array preferred over unordered_map for O(1) deterministic lookups
        int mpp[256] = {0};
        for(int i = 0; i < s.length(); i++){
            mpp[s[i]]++;
        }

        // Step 2: Collect only non-zero frequency characters into a vector of pairs
        // pair<char, int> = {character, its frequency}
        vector<pair<char,int>> v;
        for(int i = 0; i < 256; i++){
            if(mpp[i] != 0){
                v.push_back({(char)i, mpp[i]});
            }
        }

        // Step 3: Sort by frequency DESCENDING using lambda comparator
        // Option 1: static keyword laga do(agar function global nahi hai to) -> jab class ke andar rakhna ho but object pe depend na kare
        // Option 2: function global bana do(class ke bahar) -> jab comparator simple ho aur dobara use na karna ho
        // Option 3: Lambda function -> sort() ke andar inline -> localized, no name pollution, modern C++
        // Lambda is inline, no separate function needed, no static/global hassle
        sort(v.begin(), v.end(), [](pair<char,int> p1, pair<char,int> p2){
            if(p1.second > p2.second) return true; // Higher frequency comes first
            // if(p1.second < p2.second) return false; // Tie-breaker not required on LeetCode
            // if(p1.first > p2.first) return true;
            return false;
        });

        // Step 4: Build return string
        // string(count, char) repeats 'char' exactly 'count' times in one shot
        string result = "";
        for(int i = 0; i < v.size(); i++){
            if(v[i].second != 0){
                result += string(v[i].second, v[i].first); // e.g. string(2, 'e') -> "ee"
            }
        }
        return result;
    }
};

/*

TC -> O(n + klogk)
      O(n) frequency counting
      Sorting unique characters: O(klogk) where k = number of unique characters(k <= 256)
      String building: O(n) total characters appended
      Since k <= 256(constant), klogk s bounded -> effectively O(n)
SC -> O(k) auxiliary
      v vector stores at most 256 pairs -> O(1) bounded
      Output string takes O(n) but that's required return space

*/