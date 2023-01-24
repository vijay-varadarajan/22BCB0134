file = open('test.csv', 'w')
file.write("New input line 1")
file.write("New input line 2")
file.close()

file = open('test.csv', 'a')
file.writelines(f"nEW LINE \n old line")
file.close()

file = open('test.csv', 'r')
red = file.read()
print(red)
file.close()
