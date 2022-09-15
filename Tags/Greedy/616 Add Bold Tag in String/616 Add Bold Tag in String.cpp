// Date: September 15, 2022
class Solution {
public:
    string addBoldTag(string s, vector<string>& dict) {
        vector<pair<int, int>> ranges = findpairs(s, dict);
        // print ranges
        // transform(ranges.begin(), ranges.end(), std::ostream_iterator<string>(std::cout, " "), [](pair<int, int> &p1){
        //     std::ostringstream oss;
        //     oss << "( " << p1.first << ", " << p1.second << " )";
        //     return oss.str();
        // });
        ranges = merge(ranges);
        
        for (auto it = ranges.rbegin(); it != ranges.rend(); it++) {
            s.insert(it->second, "</b>");
            s.insert(it->first, "<b>");
        }
        return s;
    }

private:
   vector<pair<int, int>> findpairs(string s, vector<string>& dict) {
        vector<pair<int, int>> res;
        for (string w : dict) {
            int n = w.size();
						int i = 0;
						while((i = s.find(w, i)) != string::npos) {
								res.push_back(pair<int, int>(i, i + n));
								i++;
						}
        }
        return res;
    }

    vector<pair<int, int>> merge(vector<pair<int, int>>& a) {
        vector<pair<int, int>> r;
        sort(a.begin(), a.end(), compare);
        for (int i = 0, j = -1; i < a.size(); i++) {
            if (j < 0 || a[i].first > r[j].second) {
                r.push_back(a[i]);
                j++;
            }
            else {
                r[j].second = max(r[j].second, a[i].second);
            }
        }
        
        return r;
    }

    static bool compare(pair<int, int>& a, pair<int, int>& b) {
        return a.first < b.first || a.first == b.first && a.second < b.second;
    }
};
