// Date: April 14, 2023
class Solution {
public:
    int numOfPairs(vector<string>& nums, string target) {
        sort(nums.begin(), nums.end(), [](const string& a, const string& b){
            return a.length() < b.length();
        });
        unordered_map<string, int> count;
        int res = 0;
        for(int i = 0; i < nums.size(); ++i) {
            string curr = nums[i];
            if(curr.size() > target.size()) break;
            if(curr == target.substr(0, curr.size())) { // match prefix
                string remain = target.substr(curr.size());
                res += count[remain];
            }
            if(curr == target.substr(target.size()-curr.size())) { // match suffix
                string remain = target.substr(0, target.size()-curr.size());
                res += count[remain];
            }
            count[curr]++;
        }
        return res;
    }
};
