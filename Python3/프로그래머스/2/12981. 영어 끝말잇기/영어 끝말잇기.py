def solution(n, words):
    ans = [0,0]
    idx = 0
    
    say_words = {}
    say_words[words[0]] = True
    
    for i in range(1, len(words)):
        before = words[i - 1]
        cur = words[i]
        
        # 처음 말하는 경우
        if not say_words.get(cur):
            say_words[cur] = True
        else: # 중복 -> 잘못된 경우
            idx = i
            break
            
        # 잘못된 경우
        if before[-1] != cur[0]:
            idx = i
            break
    
    if idx == 0:
        return [0,0]
    
    times = idx // n
    people = idx % n + 1
    return [people, times + 1]
        
    
    
    
        