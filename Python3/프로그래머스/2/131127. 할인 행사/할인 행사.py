def solution(want, number, discount):
    n = len(discount)
    cnt = 0
    for start in range(n - 10 + 1):
        counter = {}
        discount_list = discount[start : start + 10]
        
        for stuff in discount_list:
            if not counter.get(stuff):
                counter[stuff] = 0
            counter[stuff] += 1
        
        can = True
        
        for i in range(len(want)):
            stuff = want[i]
            stuff_num = number[i]
            
            if not counter.get(stuff):
                can = False
                break
            
            if counter[stuff] == stuff_num:
                continue
            else:
                can = False
                break
        if can:
            cnt += 1
    return cnt
        
        
        