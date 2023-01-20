num = int(input())
asc = sorted(str(num))
desc = sorted(str(num), reverse=True)
choice = input("A / D / B: ").upper().strip()
if choice == 'A':
    print("ASCENDING:", *asc, sep="")
elif choice == 'D':
    print("DESCENDING:", *desc, sep="")
elif choice == 'B':
    print("ASCENDING:", *asc, sep="")
    print("DESCENDING:", *desc, sep="")
else:
    print("Wrong choice")
