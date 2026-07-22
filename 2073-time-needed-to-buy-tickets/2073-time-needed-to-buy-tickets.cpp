class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int i = 0;
        int x = tickets[k];
        int time = 0;
        for(int i = 0; i < tickets.size(); i++){
            if(i <= k){
                time = time + min(tickets[i], x);
            }
            else{
                time = time + min(tickets[i], x - 1);
            }
        }
        return time;
    }
};