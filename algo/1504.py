import sys, heapq

graph = []
INF = sys.maxsize

def dijkstra(start):
    dist = [INF for _ in range(v+1)]
    pq = []
    heapq.heappush(pq, [0, start])
    dist[start] = 0

    while pq:
        value, node = heapq.heappop(pq)
        for i, j in graph[node]:
            if dist[i] > value + j:
                dist[i] = value + j
                heapq.heappush(pq, [dist[i], i])
    # print("dist : ", dist)
    return dist

if __name__ == "__main__":
    answer = 0
    v, e = map(int, input().split())
    for i in range(v+1):
        graph.append([])
    for i in range(e):
        a, b, c = map(int, input().split())
        graph[a].append([b, c])
        graph[b].append([a, c])
    must_go1, must_go2 = map(int, input().split())

    dist1 = dijkstra(1)
    dist2 = dijkstra(must_go1) 
    dist3 = dijkstra(must_go2)

    #1 -> go1 -> go2 -> n
    #1 -> go2 -> go1 -> n
    answer = min(dist1[must_go1] + dist2[must_go2] + dist3[v], dist1[must_go2] + dist3[must_go1] + dist2[v])
    
    if answer >= INF:
        print(-1)
    else:
        print(answer)