// Date: October 10, 2023
class Solution {
private:

public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        vector<vector<string>> dp(s.length()+1, vector<string>(0));
        set<string> m(wordDict.begin(), wordDict.end());
        
        dp[0] = {""};
        for(int i = 1; i <= s.length(); ++i) {
            auto index = i-1;
            for(auto word: m) {
                int size = word.length();
                if(i-size >= 0 && s.substr(i-size, size) == word) {
                    for(int j = 0; j < dp[i-size].size(); ++j) {
                        dp[i].push_back(dp[i-size][j]+word+" ");
                    }
                }
            }
        }
        for(auto& s: dp[s.length()]) s.pop_back();
        return dp[s.length()];
    }
};
