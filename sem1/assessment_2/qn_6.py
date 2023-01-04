import re
number = input()

if re.search(r"[A-Z]{5}[0-9]{4}[A-Z]", number):
    print("Valid")
else:
    print("Invalid")