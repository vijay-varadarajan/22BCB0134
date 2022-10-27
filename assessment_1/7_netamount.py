code  = int(input("Enter product code: "))
amount = float(input("Enter order amount: "))
DISC = 0

if code == 1:
    if amount > 1000:
        DISC = 0.1
elif code == 2:
    if amount > 750:
        DISC = 0.05
elif code == 3:
    if amount > 500:
        DISC = 0.1
else:
    print("Invalid code")

amount -= amount * DISC
print(f"Net amount: {amount:.2f}")