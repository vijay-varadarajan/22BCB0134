n = eval(input("Enter a list of numbers: "))
nums = []
for i in n:
    if i%2 == 0:
        nums.append(i)

print("Numbers divisible by 2:",*nums, sep=', ')

