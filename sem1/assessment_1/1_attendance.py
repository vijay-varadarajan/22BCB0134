total_classes = int(input())
attended_classes = int(input())
proof = int(input())

percentage = (attended_classes / total_classes) * 100
print(percentage)

if percentage >= 75:
    print("Allowed")
else:
    if proof == 1:
        print("Allowed")
    else:
        print("Not allowed")