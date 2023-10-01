// Date: October 1, 2023
class Solution {
public:
    int findTheWinner(int n, int k) {
        // simulation
        list<int> ss;
        for(int i = 0; i < n; ++i) ss.push_back(i+1);
        decltype(ss)::iterator it = ss.begin();
        
        while(n > 1) {
            for(int j = 0; j < k-1; ++j) {
                it++;
                if(it == ss.end()) it = ss.begin();
            }
            auto tmp = it;
            tmp++; 
            if(tmp == ss.end()) tmp = ss.begin();
            ss.erase(it);
            it = tmp;
            n--;
        }
        
        return *ss.begin();
    }
};
