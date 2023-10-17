class Solution:
    def maxFont(self, text: str, w: int, h: int, fonts: List[int], fontInfo : 'FontInfo') -> int:
        def isValid(size):
            sum_w = 0
            hei = fontInfo.getHeight(size)
            for c in text:
                wid = fontInfo.getWidth(size, c)
                sum_w += wid
            return sum_w <= w and hei <= h
        lo, hi = 0, len(fonts)
        while lo < hi:
            mid = lo + (hi - lo) // 2
            if isValid(fonts[mid]): lo = mid + 1
            else: hi = mid
        return -1 if lo == 0 else fonts[lo-1]
