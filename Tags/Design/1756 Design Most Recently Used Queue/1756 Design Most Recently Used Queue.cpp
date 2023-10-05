// Date: October 5, 2023
class MRUQueue {
// skip-list, creating index
list<int> l;
vector<decltype(l)::iterator> index;
int step;
public:
    MRUQueue(int n) {
        step = (int)sqrt(n);
        for(int i = 0; i < n; ++i) {
            l.push_back(i+1);
            if(i % step == 0) index.push_back(--l.end());
        }
    }
    
    int fetch(int k) {
        k = k-1;
        int bucket = k / step;
        decltype(l)::iterator target = index[bucket];
        for(int i = 0; i < k%step; ++i) target = next(target);
        if(k%step == 0 && next(target) != l.end()) index[k/step] = next(target);
        // move to the end
        l.splice(l.end(),l,target);
        // update all buckets after k/step+1 bucket
        for(int i = k/step+1; i < index.size(); ++i) {
            index[i] = next(index[i]);
        }
        return *target;
    }
};
