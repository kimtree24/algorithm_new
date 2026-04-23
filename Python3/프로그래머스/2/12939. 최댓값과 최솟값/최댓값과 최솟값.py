def solution(s):
    num_list = list(map(int,s.split()))
    max_num = max(num_list)
    min_num = min(num_list)
    return f"{min_num} {max_num}"