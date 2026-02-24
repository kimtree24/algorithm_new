def solution(k, tangerine):
    tan_dict = {}
    for tan in tangerine:
        if not tan_dict.get(tan):
            tan_dict[tan] = 0
        tan_dict[tan] += 1
    tan_values = sorted(tan_dict.values(), reverse = True)
    
    cur = 0
    ans = 0
    
    for i in tan_values:
        if cur >= k:
            break
        cur += i
        ans += 1
    return ans
        