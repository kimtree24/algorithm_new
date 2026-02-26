def solution(s):
    n = len(s)
    answer = 0
    
    pair = {
        ')': '(',
        ']': '[',
        '}': '{'
    }
    
    for i in range(n):
        rotated = s[i:] + s[:i]
        stack = []
        valid = True
        
        for ch in rotated:
            if ch in '([{':
                stack.append(ch)
            else:
                if not stack or stack[-1] != pair[ch]:
                    valid = False
                    break
                stack.pop()
        
        if valid and not stack:
            answer += 1
    
    return answer