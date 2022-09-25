# 1396. Design Underground System

Careful: No
Date: September 25, 2022
Difficulty: Medium
Elegant Code (Template): Design
Index: 1396
Programming Language: C++
Skills: 1. Two hash maps 2. pair of key as storage
Tags: Design, Hash Table
Link: https://leetcode.com/problems/design-underground-system/

```cpp
class UndergroundSystem {
map<pair<string,string>, pair<int, int>> m;
unordered_map<int, pair<string, int>> records;
public:
    UndergroundSystem() {
        
    }
    
    void checkIn(int id, string stationName, int t) {
        records[id] =  {stationName, t};
    }
    
    void checkOut(int id, string stationName, int t) {
        pair<string, string> inOut = {records[id].first, stationName};
        auto totalTime = t - records[id].second;
        m[inOut].first += totalTime;
        m[inOut].second++;
    }
    
    double getAverageTime(string startStation, string endStation) {
        return (m[{startStation, endStation}].first + 0.0) / m[{startStation,endStation}].second;
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */
```