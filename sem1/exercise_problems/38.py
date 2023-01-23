m, n = int(input("m: ")), int(input("n: "))
choice = int(input("Enter 1 for multiplication, 2 for division: "))
if choice == 1: 
    for i in range(1, n+1):
        print(f"{m}*{i}=", m*i)
elif choice == 2:
    for i in range(1, n+1):
        print(f"{m}/{i}=", m/i) 
