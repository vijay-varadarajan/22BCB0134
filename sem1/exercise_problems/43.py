uppers, lowers, spls, nums = 0, 0, 0, 0

while True:
    char = input("Enter a character: ")
    if char == '*':
        break
    elif char.isupper():
        uppers += 1
    elif char.islower():
        lowers += 1
    elif char.isdigit():
        nums += 1
    elif not char.isspace():
        spls += 1

print("Uppercases:", uppers)
print("Lowercases:", lowers)
print("Numbers:", nums)
print("Special characters:", spls)
