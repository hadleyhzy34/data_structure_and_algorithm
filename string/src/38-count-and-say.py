class Solution:
    def countAndSay(self, n: int) -> str:
        res = []
        res.append("1")
        for i in range(1, n + 1):
            cur = self.countString(res[i - 1])
            res.append(cur)

        return res[n - 1]

    def countString(self, s: str) -> str:
        res = ""
        n = len(s)
        cur = 1
        num = s[0]
        for i in range(1, n):
            if s[i] == num:
                cur += 1
            else:
                res += chr(cur)
                res += num
                cur = 1
                num = s[i]

        if cur > 0:
            res += chr(cur)
            res += num

        return res
