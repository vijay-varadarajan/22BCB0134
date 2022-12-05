kmtr = float(input())

if kmtr <= 1000:
    print(0)
elif 1000 < kmtr <= 10000:
    print(50)
elif 10000 < kmtr <= 20000:
    print(150)
elif 20000 < kmtr <= 40000:
    print(250)
elif 40000 < kmtr <= 60000:
    print(350)
else:
    print(500)