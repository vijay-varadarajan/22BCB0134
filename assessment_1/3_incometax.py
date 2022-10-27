income = float(input("Annual income: "))

if income <= 500000:
    print("tax: NIL")
elif 500000 < income <= 1000000:
    print(f"tax: {income * 2 / 100}")
elif income > 1000000:
    print(f"tax: {income * 4 / 100}")
else:
    print("Invalid amount")