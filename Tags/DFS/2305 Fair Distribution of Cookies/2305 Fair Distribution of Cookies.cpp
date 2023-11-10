// Date: November 10, 2023
class Solution {
int min_val;
public:
    int distributeCookies(vector<int>& cookies, int k) {
        min_val = INT_MAX;
        vector<int> bags(k, 0);
        dfs(cookies, 0, bags, 0);
        return min_val;
    }
    
    void dfs(vector<int>& cookies, int index, vector<int>& bags, int cur_max) {
        if(index == cookies.size()) {
            min_val = min(min_val, cur_max);
            return;
        }
        
        for(int i = 0; i < bags.size(); ++i) {
            bags[i] += cookies[index];
            int tmp = cur_max;
            cur_max = max(cur_max, bags[i]);
            if(cur_max < min_val) dfs(cookies, index+1, bags, cur_max);
            bags[i] -= cookies[index];
            cur_max = tmp;
        }
    }
};
