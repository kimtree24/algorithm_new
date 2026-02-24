def solution(n):
    nex = n
    while True:
        nex += 1
        cur_cnt = bin(n)[2:].count('1')
        nex_cnt = bin(nex)[2:].count('1')
        
        if cur_cnt == nex_cnt:
            return nex