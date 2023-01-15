array = input()
count = 0
for i in array:
    if str(i).islower():
        print(i)
        count += 1
print("Number of lowercases: ", count)
