import sys


distance = float(input("Distance: "))
if distance < 0:
    print("Invalid distance")
    sys.exit()

print("Fare: ", end = '')
if 0 < distance <= 50:
    print(distance * 8)
elif 50 < distance <= 100:
    print(distance * 10)
else:
    print(distance * 12)