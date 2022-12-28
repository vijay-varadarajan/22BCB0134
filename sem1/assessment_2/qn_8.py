def main():
    hair = input("Hair sample sequence: ").upper()
    person = input("Person sequence: ").upper()

    hairstart, hairreps = startnreps(hair)
    personstart, personreps = startnreps(person)
    codons = ('A', 'G', 'C', 'T')

    mismatch = False
    for letter in hair:
        if letter not in codons:
            mismatch = True
            break
    for letter in person:
        if letter not in codons:
            mismatch = True
            break
    
    print(hairstart, hairreps)
    print(personstart, personreps)

    if hairstart == personstart and hairreps == personreps and not mismatch:
        print("MATCH")
    else:
        print("MISMATCH")


def startnreps(dna):
    start_point, repeats = 0, 0
    if len(dna) > 3:
        for i in range(len(dna)-3):
            quad = ''
            for j in range(i, i+4):
                quad += dna[j]
            if quad == 'AGCT':
                start_point = i
                repeats += 1
            
        start_point -= 4*(repeats - 1)

    return start_point, repeats


main()