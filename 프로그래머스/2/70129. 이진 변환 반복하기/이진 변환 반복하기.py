def solution(s):
    change_cnt = 0
    del_0 = 0
    
    while True:
        if s == '1':
            break
        cnt_0 = s.count('0')
        new_s = s.replace('0', '')
        del_0 += cnt_0
        c = len(new_s)
        # 이진법 변환
        temp = []
        while c > 0:
            remain = c % 2
            c //= 2
            temp.append(remain)
        temp.sort(reverse = True)
        temp = list(map(str, temp))
        trans = ''.join(temp)
        change_cnt += 1
        s = trans
    return [change_cnt, del_0]
    
        