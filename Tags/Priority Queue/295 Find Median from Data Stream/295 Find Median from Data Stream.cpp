// Date: January 30, 2024
class MedianFinder {
priority_queue<int> lower; // max heap, should store lower half
priority_queue<int, vector<int>, greater<int>> upper; // min heap, should store upper half
public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        lower.push(num);
        upper.push(lower.top());
        lower.pop();
        if(upper.size() > lower.size()) {
            lower.push(upper.top());
            upper.pop();
        }
    }
    
    double findMedian() {
        if(lower.size() > upper.size()) return lower.top();
        else return (lower.top() + upper.top()) / 2.0;
    }
};
