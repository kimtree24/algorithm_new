def solution(n, left, right):
    ans = []
    for idx in range(left, right + 1):
        r = idx // n
        c = idx % n
        ans.append(max(r + 1, c + 1))
    return ans
                
            