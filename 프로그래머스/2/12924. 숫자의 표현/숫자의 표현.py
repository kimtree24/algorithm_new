def solution(n):
    front = 0
    back = 0
    
    nums = [i for i in range(1, n + 1)]
    ans = 0
    while front < n:
        cur_sum = sum(nums[front : back + 1])
        if cur_sum == n:
            ans += 1
            if front == back:
                front += 1
                back += 1
            else:
                front += 1
            continue
        elif cur_sum > n:
            front += 1
        else:
            back += 1
    return ans
        