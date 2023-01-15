left = int(input("Enter number to print mult. tables of: "))
right = int(input("Enter the limit: "))

for i in range(1, right+1):
    print(f"{left:.0f} x {i} =", left*i)
