// Date: June 3, 2023
class Solution {
public:
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        vector<pair<int, int>> zip;
        for(int i = 0; i < scores.size(); ++i) {
            zip.push_back({ages[i], scores[i]});
        }
        sort(zip.begin(), zip.end());
        vector<int>  dp(scores.size(), 0); // 选ith player的最大得分
        dp[0] = zip[0].second;
        for(int i = 1; i < dp.size(); ++i) {
            for(int j = 0; j < i; ++j) {
                if(zip[j].first < zip[i].first && zip[j].second > zip[i].second) continue; // conflict
                dp[i] = max(dp[i], dp[j]);
            }
            dp[i] += zip[i].second;
        }
        
        return *max_element(dp.begin(), dp.end());
    }
};
