string =  list(input("Enter a string: "))

for j in range(len(string) - 1):
    for i in range(0, len(string) - j - 1):
        if string[i] > string[i+1]:
            string[i], string[i+1] = string[i+1], string[i]
print("In ascending order: ", *string, sep='')
