// Date: September 29, 2022
class Solution {
public:
    string reorganizeString(string s) {
        // create hashmap for keeping a pair of <frequency, char>
        map<char, int> m;
        for (auto ch: s) {
            m[ch]++;
        }
        
        // prioirty queue for storing pair of <freq, char> (we should use the character with highest frequency)
        priority_queue<pair<int, char>> q;
        for (auto [ch, freq]: m){
            q.push({freq, ch});
        }
        string res = "";
        // every time, we pop two different char
        while (!q.empty()) {
            int k = min(2, (int)q.size());
            vector<pair<int, char>> tmp; // used for storing two popped pair
            for (int i = 0; i < k; i++) { // !use for loop !
                auto [freq, ch] = q.top();
                q.pop();
                freq--;
                if (ch == res.back()) return "";
                res+=ch;
                if (freq > 0) tmp.push_back({freq, ch});
            }
            for (auto t: tmp) q.push(t);
        }
        return res;
    }
};
