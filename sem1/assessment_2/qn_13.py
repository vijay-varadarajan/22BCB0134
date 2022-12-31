import csv

count, countnull = 0, 0
with open('diabetes.csv', 'r') as file:
    reader = csv.DictReader(file)
    for row in reader:
        count += 1
        for data in row:
            if row[data] == '0':
                countnull += 1

print(count)
print(countnull)

with open('output.csv', 'w') as newfile:
    writer = csv.DictWriter(newfile, fieldnames=['rows', 'nulls'])
    writer.writeheader()
    writer.writerow({"rows": count, "nulls": countnull})