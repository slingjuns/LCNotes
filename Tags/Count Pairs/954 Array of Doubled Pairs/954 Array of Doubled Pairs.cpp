// Date: April 16, 2023
def canReorderDoubled(self, arr: List[int]) -> bool:
        if sum(arr)%3 != 0: return False
        counter = Counter(arr)
        
        if 0 in counter:
            if counter[0]%2: return False
            counter.pop(0)
            
        for num in list(counter.keys()):
            if num not in counter: 
                continue
            while num % 2 == 0 and num//2 in counter: 
                num = num // 2
            while counter[num] > 0 and 2*num in counter:
                counter[2*num] -= counter[num]
                counter.pop(num)
                num = 2*num
            if counter[num] != 0: return False

        return True
