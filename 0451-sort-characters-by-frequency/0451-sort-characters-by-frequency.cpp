// bool mySort(pair<char,int> p1,pair<char,int> p2){
//         if(p1.second > p2.second){
//             return true;
//         }
//         if(p1.second < p2.second){
//             return false;
//         }
//         if(p1.first < p2.first){
//             return true;
//         }
//         return false;
//     }

// class Solution{	
// public:
// 	string frequencySort(string& s){
//         unordered_map<char,int> mpp;
//         for(int i = 0; i < s.length(); i++){
//             mpp[s[i]]++;
//         }
//         vector<pair<char,int>> arr;
//         for(auto it:mpp){
//             arr.push_back({it.first,it.second});
//         }
//         sort(arr.begin(), arr.end(), mySort);
//         string answer = "";
//         for(int i = 0; i < arr.size(); i++){
//             answer += string(arr[i].second,arr[i].first);
//         }
//         return answer;
// 	}
// };

// bool mySort(pair<char,int> p1,pair<char,int> p2){
//         if(p1.second > p2.second){
//             return true;
//         }
//         if(p1.second < p2.second){
//             return false;
//         }
//         if(p1.first < p2.first){
//             return true;
//         }
//         return false;
//     }

// class Solution{	
// public:
// 	vector<char> frequencySort(string& s){
//         unordered_map<char,int> mpp;
//         for(int i = 0; i < s.length(); i++){
//             mpp[s[i]]++;
//         }
//         vector<pair<char,int>> arr;
//         for(auto it:mpp){
//             arr.push_back({it.first,it.second});
//         }
//         sort(arr.begin(), arr.end(), mySort);
//         vector<char> answer;
//         for(int i = 0; i < arr.size(); i++){
//             answer.push_back(arr[i].first);
//         }
//         return answer;
// 	}
// };

class Solution{
public:
    string frequencySort(string&s){
        unordered_map<char,int> mpp;
        for(int i = 0; i < s.length(); i++){
            mpp[s[i]]++;
        }
        vector<string> bucket(s.length() + 1);
        for(auto it:mpp){
            bucket[it.second] += string(it.second,it.first);
        }

        string answer;
        for(int i = s.length(); i >= 0; i--){
            if(!bucket[i].empty()){
                answer += bucket[i];
            }
        }
        return answer;
    }
};