class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int i = 0;
        int x = tickets[k];
        int time = 0;
        while(i <= k){
            time = time + min(tickets[i], x);
            i++;
        }
        while(i < tickets.size()){
            time = time + min(tickets[i], x - 1);
            i++;
        }
        return time;
    }
};