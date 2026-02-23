def solution(s):
    stack = []
    
    for ch in s:
        if len(stack) == 0:
            stack.append(ch)
            continue
        
        if stack[-1] == '(' and ch == ')':
            stack.pop()
        else:
            stack.append(ch)
    if stack:
        return False
    else:
        return True
            