array = input()
count = 0
for i in array:
    if str(i).isupper():
        count += 1
print("Number of uppercases: ", count)
