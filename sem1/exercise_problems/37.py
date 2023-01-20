def prime(n):
    if n == 0 or n == 1:
        return False
    for i in range(2, n//2 + 1):
        if n % i == 0:
            return False
    return True

for i in range(int(input('a: ')), int(input('b: '))):
    if not prime(i):
        print(i, end=', ')

print('\b\b.')
