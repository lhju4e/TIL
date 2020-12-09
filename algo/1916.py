import sys, heapq

n = int(input())
INF = sys.maxsize
graph = []
track = []
for i in range(n+1):
    graph.append([])
    track.append([i])

def dijkstra(start):
    dist = [INF for i in range(n+1)]
    check = [False for i in range(n+1)]
    pq = []
    heapq.heappush(pq, [0, start])
    dist[start] = 0
    while pq:
        value, node = heapq.heappop(pq)
        check[node] = True
        for i, j in graph[node]:

            if check[i] == False and dist[i] > value + j:
                dist[i] = value + j
                track[i] = track[node].copy()
                track[i].append(i)
                heapq.heappush(pq, [dist[i], i])
    return dist

if __name__ == "__main__":
    m = int(input())
    for i in range(m):
        a, b, c = map(int, input().split())
        graph[a].append([b, c])
    start, end = map(int, input().split())
    dist = dijkstra(start)
    print(dist[end])

    print(len(track[end]))
    for i in track[end]:
        print(i, end=' ')
