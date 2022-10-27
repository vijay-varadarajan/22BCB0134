total_classes = int(input("Total classes held: "))
attended_classes = int(input("Number of classes attended: "))
proof = int(input("Medical proof availability: "))

percentage = (attended_classes / total_classes) * 100
print(percentage)

if percentage >= 75:
    print("Allowed")
else:
    if proof == 1:
        print("Allowed")
    else:
        print("Not allowed")