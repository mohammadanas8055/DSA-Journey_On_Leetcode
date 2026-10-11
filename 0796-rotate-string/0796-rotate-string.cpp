class Solution {
public:
    bool rotateString(string s, string goal) {
        string st = s + s;
        return s.length() == goal.length() && st.find(goal) != string::npos;
    }
};