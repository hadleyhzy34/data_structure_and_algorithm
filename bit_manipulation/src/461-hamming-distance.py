class Solution:
    def hammingDistance(self, x: int, y: int) -> int:
        res = 0
        for i in range(32):
            if ((x >> i) & 1) == ((y >> i) & 1):
                res += 1

        return res
