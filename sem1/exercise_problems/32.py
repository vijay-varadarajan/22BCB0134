names = eval(input("Enter a list of names: "))
asc = sorted(names)
desc = sorted(names, reverse=True)
choice = input("A / D / B: ").upper().strip()
if choice == 'A':
    print("ASCENDING:", *asc, sep=", ")
elif choice == 'D':
    print("DESCENDING:", *desc, sep=", ")
elif choice == 'B':
    print("ASCENDING:", *asc, sep=", ")
    print("DESCENDING:", *desc, sep=", ")
else:
    print("Wrong choice")
