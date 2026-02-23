def solution(s):
    s_list = list(s)
    
    start = True
    for idx, ch in enumerate(s_list):
        if start:
            s_list[idx] = ch.upper()
        else:
            s_list[idx] = ch.lower()
        
        if ch == ' ':
            start = True
        else:
            start = False
    return ''.join(s_list)