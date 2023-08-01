class Solution:
    def arrangeCoins(self, n: int) -> int:
        lo, hi = 0, n + 1
        while lo < hi:
            mid = lo + (hi-lo) // 2
            sum_v = mid * (mid + 1) / 2
            if sum_v > n: hi = mid
            else: lo = mid + 1
        return lo-1
