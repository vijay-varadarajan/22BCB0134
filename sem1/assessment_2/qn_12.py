from tabulate import tabulate

key = {1: 'A', 2: 'B', 3: 'B', 4: 'A', 5: 'C'}
cands = int(input())
opts = {}
for i in range(cands):
    choices = input().split()
    opts[i] = choices

scores = {}

for i in range(len(opts)):
    anss = opts[i]
    score = 0.00
    for ans in range(len(anss)):
        if anss[ans] == key[ans+1]:
            score += 2
        elif anss[ans] == 'X':
            pass
        else:
            score -= 0.25
    scores[i] = score

scores = dict(sorted(scores.items(), key=lambda item: item[1], reverse=True))
print(scores)
output = []
printed_cands = []
candidate_num = list(scores.keys())
cand_scores = list(scores.values())
for i in range(len(scores)):
    candidate_appended = False
    candidates = f'C{candidate_num[i]+1}'
    
    for cand in printed_cands:
        if candidates in cand:
            candidate_appended = True
    if candidate_appended:
        continue
    for j in range(i+1, len(scores)):
        if scores[i] == scores[j]:
            candidates += f',C{candidate_num[j]+1}'
    printed_cands.append(candidates)
    tot = '{total_score:.2f}'.format(total_score=cand_scores[i])
    line = {'rank':i+1, 'Candidates':candidates, 'Total':str(tot)}

    output.append(line)

print(*list(output[0].keys()))
for line in output:
    print(*list(line.values()), sep='\t')
    