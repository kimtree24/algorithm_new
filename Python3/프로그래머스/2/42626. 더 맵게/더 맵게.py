import heapq
def solution(scoville, K):
    h_sco = []
    
    for i in scoville:
        heapq.heappush(h_sco, i)
    
    cnt = 0
    while(h_sco[0] < K):
        if len(h_sco) < 2:
            return -1
        first = heapq.heappop(h_sco)
        second = heapq.heappop(h_sco)
        heapq.heappush(h_sco, first + (second * 2))
        cnt += 1
    return cnt