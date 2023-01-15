n = eval(input("Enter a list of integers: "))
count = 0
for i in n:
    if i > 0:
        count += 1
print("Number of positive integers: ", count)
