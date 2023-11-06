// Date: November 6, 2023
class Solution {
public:
    int longestStrChain(vector<string>& words) {
        // like DP + hash map
        sort(words.begin(), words.end(), [](const auto& a, const auto& b){
            return a.length() < b.length();
        });
        unordered_map<string, int> s2index;
        int res = 0;
        vector<int> dp(words.size()+1, 1);
        
        for(int i = 1; i < dp.size(); ++i) {
            int index = i-1;
            string cur = words[index];
            for(int j = 0; j < cur.size(); ++j) {
                string pred = cur.substr(0, j) + cur.substr(j+1);
                if(s2index.count(pred)) dp[i] = max(dp[i], dp[s2index[pred]]+1);
            }
            res = max(res, dp[i]);
            s2index[cur] = i;
        }
        return res;
    }
};
