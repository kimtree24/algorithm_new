def solution(arr):
    st = []
    
    for i in arr:
        if len(st) == 0:
            st.append(i)
        else:
            if st[-1] == i:
                continue
            else:
                st.append(i)
    return st