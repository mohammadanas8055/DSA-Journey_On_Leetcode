class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> heavy;
        for(int i = 0; i < stones.size(); i++){
            heavy.push(stones[i]);
        }
        while(heavy.size() > 1){
            int HeavyRightNow = heavy.top();
            heavy.pop();
            int SecondHeavy = heavy.top();
            heavy.pop();
            if(HeavyRightNow - SecondHeavy == 0){
                continue;
            }
            heavy.push(HeavyRightNow - SecondHeavy);
        }
        if(heavy.empty()){
            return 0;
        }
        return heavy.top();
    }
};