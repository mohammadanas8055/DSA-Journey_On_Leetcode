class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        stack<int> st;
        for(int i = sandwiches.size() - 1; i >= 0; i--){
            st.push(sandwiches[i]);
        }
        queue<int> q;
        for(int i = 0; i < students.size(); i++){
            q.push(students[i]);
        }
        int rotation = 0;
        while(!st.empty()){
            if(q.front() != st.top()){
                int temp = q.front();
                q.pop();
                q.push(temp);
                rotation++;
                if(rotation == q.size()){
                    break;
                }
            }
            else{
                q.pop();
                st.pop();
                rotation = 0;
            }
        }
        return q.size();
    }
};