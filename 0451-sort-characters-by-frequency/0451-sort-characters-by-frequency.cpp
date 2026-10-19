class Solution{
public:
    string frequencySort(string&s){
        // Step 1: Count frequencies using ifxed 256-size array
        // Array is faster than unordered_map for small bounded key ranges (ASCII)
        int mpp[256] = {0};
        for(int i = 0; i < s.length(); i++){
            mpp[s[i]]++;
        }

        // Step 2: Bucket Sort - index = frequency, value = concatenated character
        // bucket[f] stores all characters that appear exactly f times, repeated f times
        // Size is s.length() + 1 because max possible frequency = length of string
        vector<string> bucket(s.length() + 1);
        for(int i = 0; i < 256; i++){
            if(mpp[i] != 0){
                bucket[mpp[i]] += string(mpp[i], (char)i);
            }
        }

        string answer = "";
        for(int i = s.length(); i >= 0; i--){
            if(!bucket[i].empty()){
                answer += bucket[i];
            }
        }
        return answer;
    }
};