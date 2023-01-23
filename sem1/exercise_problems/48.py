def leap(n):
    if (n%4 == 0 and n%100 != 0) or n%400 == 0:
        return True
    return False

l = int(input("Enter year: "))
if leap(l):
    print("Leap year")
    cnt = 4
    while True:
        if leap(l + cnt):
            print("Next leap year: ", l + cnt)
            break
        cnt += 4
else:
    print("Not a leap year")
    print("Previous leap year: ", l - l%4)