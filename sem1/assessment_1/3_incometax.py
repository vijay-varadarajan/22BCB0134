income = float(input())

if income <= 500000:
    print("NIL")
elif 500000 < income <= 1000000:
    print(f"{income * 2 / 100}")
else:
    print(f"{income * 4 / 100}")
