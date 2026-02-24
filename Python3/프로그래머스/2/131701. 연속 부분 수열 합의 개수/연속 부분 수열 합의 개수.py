def solution(elements):
    n = len(elements)
    circle_list = elements * 2
    
    front = 0
    
    sum_list = []
    
    while front < n:
        for back in range(front, front + n):
            cur_sum = sum(circle_list[front:back + 1])
            sum_list.append(cur_sum)
        front += 1
    return len(set(sum_list))