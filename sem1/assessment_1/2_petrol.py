points = int(input())
litres = 0
ml = 0

for i in range(points):
    litres += float(input())
    ml += float(input())

    if ml >= 1000:
        litres += 1
        ml -= 1000

print(litres)
print(ml)