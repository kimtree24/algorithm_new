def solution(numbers):
    new_list = []
    for num in numbers:
        new_list.append(str(num))
    
    new_list.sort(key=lambda x: x*3, reverse=True)
    
    return str(int(''.join(new_list)))