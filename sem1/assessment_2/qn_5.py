one = {'A', 'J', 'S'}
two = {'B', 'K', 'T'}
three = {'C', 'L', 'U'}
four = {'D', 'M', 'V'}
five = {'E', 'N', 'W'}
six = {'F', 'O', 'X'}
seven = {'G', 'P', 'Y'}
eight = {'H', 'Q', 'Z'}
nine = {'I', 'R'}

def main():
    vowels = {'A', 'E', 'I', 'O', 'U'}

    name = input()
    destiny = 0
    soul = 0
    dream = 0
    for letter in name:
        if letter in vowels:
            soul += value(letter)
        elif letter not in vowels:
            dream += value(letter)
        destiny += value(letter)

    print(add_digits(destiny))
    print(add_digits(soul))
    print(add_digits(dream))

def add_digits(num):
    while len(str(num)) > 1:
        new_num = 0
        for i in range(len(str(num))):
            new_num += int(str(num)[i])
        num = new_num
    return num

def value(letter):
    val = 0
    if letter in one:
        val += 1
    elif letter in two:
        val += 2
    elif letter in three:
        val += 3
    elif letter in four:
        val += 4
    elif letter in five:
        val += 5
    elif letter in six:
        val += 6
    elif letter in seven:
        val += 7
    elif letter in eight:
        val += 8
    elif letter in nine:
        val += 9
    return val

main()