// Date: October 14, 2023
class Solution {
public:
    vector<int> memLeak(int memory1, int memory2) {
        int i = 0;
        while(max(memory1, memory2) >= i) {
            if(memory1 >= memory2) memory1 -= i;
            else memory2 -= i;
            i++;
        }
        vector<int> res(3,0);
        res[0] = i;
        res[1] = memory1;
        res[2] = memory2;
        return res;
    }
};
