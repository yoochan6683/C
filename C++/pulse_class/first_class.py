cnt = 0
def f(n):
    print(n)
    cnt += 1
    if n < 2: return
    f(n-1); f(n-1);

f(int(input()))
print(cnt)