// Date: August 29, 2023
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        vector<int> miles(cost.size());
        // preprocess
        for(int i = 0; i < gas.size(); ++i) {
            miles[i] = gas[i]-cost[i];
        }
        
        int curSum = 0, totalSum = 0, start=0;
        for(int i = 0; i < miles.size(); ++i) {
            totalSum += miles[i];
            curSum += miles[i];
            if(curSum < 0) {
                start=i+1;
                curSum = 0;
            }
        }
        return totalSum < 0 ? -1 : start;
    }
};
