pos, poscount = 0, 0
neg, negcount = 0, 0
while True:
    num = int(input("Enter number: "))
    if num == -1:
        break
    if num >= 0:
        pos += num
        poscount += 1
    elif num < 0:
        neg += num
        negcount += 1
print(f"Average of positive numbers: {pos/poscount:.2f}")
print(f"Average of negative numbers: {neg/negcount:.2f}")
