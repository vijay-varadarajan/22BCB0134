def prime(n):
    for i in range(2, n//2+1):
        if n%i == 0:
            return False
    return True

a, b = int(input()), int(input())

for i in range(a, b+1):
    if not prime(i):
        print(i, end=', ')

print('\b\b.')

