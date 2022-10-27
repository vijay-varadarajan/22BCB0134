points = int(input("Storage points: "))
litres = 0
ml = 0

for i in range(points):
    litres += float(input(f"Litres from source {i+1}: "))
    ml += float(input(f"Mls from source {i+1}: "))

    if ml >= 1000:
        litres += 1
        ml -= 1000

print(litres)
print(ml)