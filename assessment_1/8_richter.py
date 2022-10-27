n = int(input("Earthquakes count: "))
low, med, high = 0, 0, 0

if n < 0:
    print("Invalid input")
elif n == 0:
    print("No earthquake predicted")
else:
    for i in range(n):
        mag = float(input(f"Mag {i+1}: "))
        if mag <= 5.4:
            low += 1
        elif 5.4 < mag <= 7.0:
            med += 1
        else:
            high += 1

    print(low, med, high, sep='\n') 
