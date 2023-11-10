// Date: November 10, 2023
#include "bits/stdc++.h"

using namespace std;
typedef long long LL;
#define INF 0x3f3f3f3f
const int MOD = 1e9+7;
typedef pair<int, int> P;

int nums[100];

bool dfs(int depth, int maxDepth, int target) {
    if (depth > maxDepth)
        return false;

    if (nums[depth-1] == target) 
        return true;

    // 这里不能用unordered_set，会TLE
    int seen[101] = {0};

    // 从后往前遍历，先取大数减少分支
    for (int i = depth-1; i >= 0; i--) {
        for (int j = i; j >= 0; j--) {
            int sum = nums[i] + nums[j];
            // sum 不能小等上一个数字 - 可行性
            // sum 不能已经被用过 
            // sum 不能超过target - 可行性
            // 这三个剪枝少一个都会TLE
            if (sum <= nums[depth-1] || seen[sum] || sum > target)
                continue;

            seen[sum] = 1;

            nums[depth] = sum;
            if (dfs(depth+1, maxDepth, target))
                return true;
        }
    }

    return false;
}

int main() {
    int n;
    while(cin >> n, n) {
        memset(nums, 0, sizeof(nums));
        nums[0] = 1;
        int depth = 1;
        while (!dfs(1, depth, n)) depth++;
        for (int i = 0; i < depth; i++) {
            cout << nums[i] << " ";
        }
        cout << endl;
    }

    return 0;
}
