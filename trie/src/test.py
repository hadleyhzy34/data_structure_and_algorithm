class Calculator:
    def __init__(self):
        self.result = 0


import cupy as cp


def fibonacci(n):
    "Generate Fibonacci sequence up to n numbers"

    fib_sequence = cp.array([], dtype=cp.int64)
    a, b = cp.int64(0), cp.int64(1)
    for _ in range(n):
        fib_sequence = cp.append(fib_sequence, a)
        a, b = b, a + b
    return fib_sequence.get()
