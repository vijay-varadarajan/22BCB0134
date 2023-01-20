import string
vowels = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'}
puncs = string.punctuation

vow_count, cons_count = 0, 0
for i in input().strip():
    if i in vowels:
        vow_count += 1
    elif not i.isspace() and not i in puncs and not i.isnumeric():
        cons_count += 1

print("Vowels:", vow_count)
print("Consonants:", cons_count)
if vow_count > cons_count:
    print("Vowels more than consonants")
else:
    print("Consonants more than vowels")

