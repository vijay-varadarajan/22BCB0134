import math

length = float(input("Length of ladder in feet: "))
angle = int(input("Angle in degrees: "))
rads = angle * (math.pi /180)
height = length * math.sin(rads)

print(f"Height of tower: {height:.2f} ft")