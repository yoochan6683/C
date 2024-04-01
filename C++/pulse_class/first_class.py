import math
def seive(n):
    prime = []
    isprime = [1 for _ in range(n + 1)]
    for i in range(2, math.isqrt(n) + 1):
        if isprime[i]:
            q = i * i
            for j in range(q, n + 1, i):
                isprime[j] = 0
    for i in range(2, n + 1):
        if isprime[i]:
            prime.append(i)
    return prime

prime = seive(100)
print(*prime)