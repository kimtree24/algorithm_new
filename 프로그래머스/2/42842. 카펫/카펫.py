def solution(brown, yellow):
    
    for yello_row in range(yellow, 0, -1):
        yello_col = yellow // yello_row
        yello_col_remain = yellow % yello_row
        
        if yello_col_remain != 0:
            continue
            
        brown_num = yello_row * 2 + yello_col * 2 + 4
        
        if brown_num == brown:
            return [yello_row + 2, yello_col + 2]
    return 0
        
        
        