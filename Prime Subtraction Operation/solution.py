from bisect import bisect_right

class Solution:
    def primeSubOperation(self, nums: List[int]) -> bool:
        n = len(nums)
        L = 1000
        prime = [True] * L
        prime[0] = prime[1] = False
        for i in range(2, L):
            if not prime[i]:
                continue
            for j in range(i * i, L, i):
                prime[j] = False
        primes = [i for i in range(L) if prime[i]]

        prev = 0
        for num in nums:
            # Want prev < num - (some prime), therefore
            # (some prime) <= num - prev - 1
            i = bisect_right(primes, num - prev - 1)
            if i > 0:  # Found a prime to subtract from `num`
                prev = num - primes[i-1]
            elif prev >= num:
                return False
            else:
                prev = num
        return True