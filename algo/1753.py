import sys
import heapq
graph_arr = []
v,e  = map(int, sys.stdin.readline().split())
k = int(sys.stdin.readline())
for i in range(v+1):
    graph_arr.append([])
for i in range(e):
    tmp = list(map(int, input().split()))
    graph_arr[tmp[0]].append([tmp[1], tmp[2]])
dist = [100000000 for i in range(v+1)]
pq = []  

def solution(k):
    # print(graph_arr)
    # check_dist = [False for i in range(v+1)]
    heapq.heappush(pq, [0, k])
    dist[k] = 0
    while pq:
        # print("pq ", pq)
        # print(dist)
        value, node = heapq.heappop(pq)
        # check_dist[node] = True
        for i, j in graph_arr[node]:
            # if check_dist[i] == False:
            if dist[i] > value + j:
                dist[i] = value + j
                heapq.heappush(pq, [value + j, i])

    for i in range(1, v+1):
        if dist[i] == 100000000:
            print("INF")
        else:
            print(dist[i])
            
solution(k)