symbol = input("Enter symbol: ")
shape = input("Enter square or rectangle: ").lower()
type = input("Enter hollow or full: ").lower()
if shape == 'rectangle':
    if type == 'hollow':
        for i in range(5):
            if i == 0 or i == 5:
                print(symbol*8)
            else:
                print(symbol + ' '*6 + symbol)
    elif type == 'full':
        for i in  range(5):
            print(symbol*8)
    else:
        print("Wrong type choice")
elif shape == 'square':
    if type == 'hollow':
        for i in range(5):
            if i == 0 or i == 5:
                print(symbol*5)
            else:
                print(symbol + ' '*3 + symbol)
    elif type == 'full':
        for i in range(5):
            print(i*5)
    else:
        print("Wrong type choice")
else:
    print("Wrong shape chosen")

