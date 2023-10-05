// Date: October 5, 2023
class TimeMap {
unordered_map<string, map<int, string>> m;
public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        m[key][timestamp] = value;
    }
    
    string get(string key, int timestamp) {
        auto it = m[key].upper_bound(timestamp);
        if(it == m[key].begin()) return "";
        --it;
        return it->second;
    }
};
