def solution(graph, trip):
    parent = [i for i in range(len(graph)+1)]
    for i in range(len(graph)):
        for j in range(i+1, len(graph)):
            if graph[i][j] == 1:
                Union(i+1, j+1, parent)

    answer = "YES"
    tmp = Find(trip[0], parent)
    # print(tmp)
    for i in range(1, len(trip)):
        # print(Find(trip[i], parent))
        if tmp != Find(trip[i], parent):
            answer = "NO"

    return answer

def Find(x, parent):
    if x == parent[x]:
        return x
    else:
        y = Find(parent[x], parent)
        parent[x] = y
        return y

def Union(x, y, parent):
    x = Find(x, parent)
    y = Find(y, parent)
    parent[x] = y

if __name__ == "__main__":
    n = int(input())
    m = int(input())
    graph = []
    for i in range(n):
        graph.append(list(map(int, input().split())))
    trip = list(map(int, input().split()))
    answer = solution(graph, trip)
    print(answer)