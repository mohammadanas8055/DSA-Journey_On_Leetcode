class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        queue<int> q;
        int time = 0;
        for(int i = 0; i < tickets.size(); i++){
            q.push(i);
        }
        while(tickets[k] != 0){
            if(tickets[q.front()] > 1){
                tickets[q.front()]--;
                q.push(q.front());
                time++;
                q.pop();
            }
            else{
                tickets[q.front()]--;
                time++;
                q.pop();
            }
        }
        return time;
    }
};