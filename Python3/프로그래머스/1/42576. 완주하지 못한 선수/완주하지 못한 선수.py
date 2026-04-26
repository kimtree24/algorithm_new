from collections import defaultdict
def solution(participant, completion):
    answer = ''
    di = defaultdict(int)
    
    for p in participant:
        di[p] += 1
    for c in completion:
        di[c] -= 1
    
    keys = list(di.keys())
    
    for key in keys:
        if(di[key] != 0):
            return key
    
    return answer