num = int(input("Enter number: "))
n = int(input("N: "))
count = 0
countprint = 0

print("First N factors: ")
for i in range(1, num//2 + 1):
    if num % i == 0:
        count += 1
        if countprint < n:
            print(i)
            countprint += 1

print("Total number of factors: ", count)
