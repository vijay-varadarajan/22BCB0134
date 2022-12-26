import re

string = input()
corrected_string = []
data = string.rstrip(']').lstrip('[').split(',')

for datum in data:
    datum = datum.strip()
    if match := re.search(r"^\{(?:[\"]|[\'])(.*)(?:[\"]|[\']):([0-9]+)\}$", datum):
        name, age = match.group(1), match.group(2)
        corrected_string.append({'name': name, 'age': int(age)})
    elif match := re.search(r"^\{([0-9]+):(?:[\"]|[\'])(.*)(?:[\"]|[\'])\}$", datum):
        name, age = match.group(2), match.group(1)
        corrected_string.append({'name': name, 'age': int(age)})
    else:
        print("None")

print(corrected_string)

name_merge = False
age_merge = False
no_merge = False
for n in range(len(corrected_string)):
    age = corrected_string[n]['age']
    name = corrected_string[n]['name']
    for data in corrected_string[1: ]:
        if data['age'] == age:
            name_merge = True
            break
        elif data['name'] == name:
            age_merge = True
            break
    if not name_merge and not age_merge:
        no_merge = True
    if name_merge or age_merge or no_merge:
        break

print(name_merge)
print(age_merge)
print(no_merge)
final_string = []

if name_merge:
    merged_names = []
    merged = False
    for n in range(len(corrected_string)):
        age = corrected_string[n]['age']
        name = corrected_string[n]['name']
        for data in corrected_string:
            if data['name'] != name and name not in merged_names and data['age'] == age:
                name += data['name']
                age = age**(1/3)
                merged_names.append(data['name'])
            if name in merged_names:
                merged = True
                break
        if merged:
            continue
        final_string.append({'name': name, 'age': int(age)})

elif age_merge:
    merged_ages = []
    merged = False
    for n in range(len(corrected_string)):
        age = str(corrected_string[n]['age'])
        name = corrected_string[n]['name']
        for data in corrected_string[1: ]:
            if data['name'] == name and str(age) not in merged_ages and str(data['age']) != str(age):
                age += str(data['age'])
                merged_ages.append(str(data['age']))
            if age in merged_ages:
                merged = True
                break
        if merged:
            continue
        final_string.append({'name': name, 'age': int(age)})

else:
    final_string = corrected_string

final_string = str(final_string).replace(" ", "")
if name_merge:
    for c in final_string:
        if c == ',':
            final_string.insert(" ", index(c))

print(final_string)