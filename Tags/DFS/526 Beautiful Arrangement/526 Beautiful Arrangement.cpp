// Date: November 14, 2023
class Solution {
int res;
public:
    int countArrangement(int n) {
        dfs(n, 1, 0);
        return res;
    }
    
    void dfs(int n, int index, int visited) {
        if(index > n) {
            res += 1;
            return;
        }
        for(int num = 1; num <= n; ++num) {
            if(visited & (1 << num)) continue;
            if(num % index != 0 && index % num != 0) continue;
            
            visited |= 1 << num;
            dfs(n, index+1, visited);
            visited &= ~(1 << num);
        }
    }
};
