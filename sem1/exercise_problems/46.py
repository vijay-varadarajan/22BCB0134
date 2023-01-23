from math import sqrt, floor, ceil

def isPerfectSquare(x):
    if x >= 0:
        sr = int(sqrt(x))
        return (sr * sr) == x
    return False

def sumofdigits(num):
    summ = 0
    for i in str(num):
        summ += int(i)
    return summ

for i in range(int(input("Lower: ")), int(input("Upper: "))):
    if isPerfectSquare(i) and sumofdigits(i) < 10:
        print(i)
