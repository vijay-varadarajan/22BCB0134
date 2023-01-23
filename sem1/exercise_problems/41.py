def prime(n):
    if n == 0 or n == 1:
        return False
    for i in range(2, n//2+1):
        if n%i == 0:
            return False
    return True

n = int(input("Enter a number: "))
count, primecount = 0, 0
while primecount < n:
    if prime(count):
        primecount += 1
    count += 1
newcount, primecount = count, 0
while primecount < n:
    if prime(newcount):
        print(newcount)
        primecount += 1
    newcount += 1

