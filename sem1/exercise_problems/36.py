from string import punctuation as puncs

spls = []
count = 0
for i in input():
    if i in puncs:
        spls.append(i)
    elif i.isspace():
        count += 1

print("Special characters", spls, sep=', ')
print("Number of special characters:", len(spls))
print("Number of spaces:", count)
