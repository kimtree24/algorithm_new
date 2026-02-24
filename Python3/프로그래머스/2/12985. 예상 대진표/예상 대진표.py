def solution(n,a,b):
    bi_a = bin(a - 1)[2:]
    bi_b = bin(b - 1)[2:]
    max_time = max(len(bi_a), len(bi_b))
    
    bi_a = '0' * (max_time - len(bi_a)) + bi_a
    bi_b = '0' * (max_time - len(bi_b)) + bi_b
    
    point = 0
    
    for i in range(max_time):
        if bi_a[i] != bi_b[i]:
            point = i
            break
    return (max_time - point)