n = input("Name of month: ").lower()
thirties = ('apr', 'jun', 'sep', 'nov')
thirtyones = ('jan', 'mar', 'may', 'jul', 'aug', 'oct', 'dec')
if 'feb' in n:
    print("28 days")
else:
    found = False
    for m in thirties:
        if m in n:
            print("30 days")
            found = True
            break
    if not found:
        for m in thirtyones:
            if m in n:
                print("31 days")
                found = True
                break

