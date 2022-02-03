// Date: February 3, 2022
class Solution:
    def shipWithinDays(self, weights: List[int], days: int) -> int:
        def isPossible(capacity):
            sum_w = 0
            day_used = 0
            for w in weights:
                if w > capacity: return False
                sum_w += w
                if sum_w > capacity: 
                    sum_w = w
                    day_used += 1
                if day_used > days:
                    return False
            day_used += 1
            return day_used <= days
        lo, hi = max(weights), sum(weights) + 1
        while lo < hi:
            mid = lo + (hi-lo) // 2
            if isPossible(mid): hi = mid
            else: lo = mid + 1
        return lo
