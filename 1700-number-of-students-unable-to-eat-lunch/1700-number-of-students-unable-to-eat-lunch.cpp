class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        vector<int> count(2, 0);
        for (int i = 0; i < students.size(); i++) {
            if (students[i] == 0) {
                count[0]++;
            } else {
                count[1]++;
            }
        }
        for (int i = 0; i < sandwiches.size(); i++) {
            if(sandwiches[i] == 0 && count[0] != 0){
                count[0]--;
            }
            else if(sandwiches[i] == 1 && count[1] != 0){
                count[1]--;
            }
            else{
                break;
            }
        }
        int answer = 0;
        for(int i = 0; i < 2; i++){
            answer += count[i];
        }
        return answer;    
    }
};