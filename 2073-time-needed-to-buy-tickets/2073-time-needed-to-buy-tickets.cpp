class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        queue<int> q;
        int time = 0;
        for(int i = 0; i < tickets.size(); i++){
            q.push(i);
        }
        while(tickets[k] != 0){
            int temp = q.front();
            q.pop();
            if(tickets[temp] > 1){
                q.push(temp);
                time++;
            }
            
            else{
                time++;
            }
            tickets[temp]--;
        }
        return time;
    }
};