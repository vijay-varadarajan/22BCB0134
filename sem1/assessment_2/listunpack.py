lst = input().rstrip(']').lstrip('[')
print(lst)
elements = lst.split(',')
print(elements)
pres = False
for element in lst:
    if element == ']' or element == '[':
        pres = True
if pres:
    print(len(elements))
else:
    print("cannot unpack")