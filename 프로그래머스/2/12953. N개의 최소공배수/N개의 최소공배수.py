def gcd(a, b):
    while b != 0:
        a, b = b, a % b
    return a
    
def lcm(a, b):
    return a * b // gcd(a, b)

def solution(arr):
    ans = arr[0]
    
    for i in range(1, len(arr)):
        ans = lcm(ans, arr[i])
    return ans
    