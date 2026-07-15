class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int n = s.length();
        for(int i = 0; i < n / 2; i++){
            int len = i + 1;
            if(n % len != 0){
                continue;
            }
            bool match = true;
            for(int j = len; j < n; j++){
                if(s[j] != s[j % len]){
                    match = false;
                    break;
                }
            }
            if(match == true){
                return true;
            }
        }
        return false;
    }
};

/// “Kya string equal-sized blocks me divide ho sakti hai, aur kya saare blocks same hain?”

/// Agar string length n hai, to repeated piece ki length:

// n nahi ho sakti
// because then repeat kitni baar hua? only once
// So candidate lengths only:

// 1 se n/2 tak

/// sab lengths try karni hain?
// Nahi.

// Agar piece ki length len hai, to poori string usse exact divide honi chahiye.

// So:
// n % len == 0 hona chahiye



