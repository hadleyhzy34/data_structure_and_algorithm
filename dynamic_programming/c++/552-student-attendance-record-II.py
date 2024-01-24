import numpy as np


class Solution:
    def checkRecord(self, n: int) -> int:
        transition = np.array(
            [
                [1, 1, 0, 1, 0, 0],
                [1, 0, 1, 1, 0, 0],
                [1, 0, 0, 1, 0, 0],
                [0, 0, 0, 1, 1, 0],
                [0, 0, 0, 1, 0, 1],
                [0, 0, 0, 1, 0, 0],
            ]
        )
        cur = np.array([[1, 1, 0, 1, 0, 0]])
        for i in range(n - 1):
            cur = np.matmul(cur, transition) % 1000000007

        return cur.sum() % 1000000007
