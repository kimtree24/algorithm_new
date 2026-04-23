def solution(s):
    ans = []
    flag = True
    
    for ch in s:
        if ch == ' ':
            ans.append(ch)
            flag = True
        else:
            if flag:
                ans.append(ch.upper())
                flag = False
            else:
                ans.append(ch.lower())
    return ''.join(ans)