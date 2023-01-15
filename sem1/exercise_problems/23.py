array = input("Enter a string: ")
count = 0
for i in array:
    if not str(i).isalpha() and not str(i).isspace() and not str(i).isnumeric():
        count += 1
print("Number of special chars: ", count)