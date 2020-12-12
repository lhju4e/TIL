from collections import deque
import sys

INF = sys.maxsize
maps = []
dx = [-1, 1, 0, 0]
dy = [0, 0, 1, -1]
    
def bfs(maps):
    visit = [[INF for _ in range(len(maps))] for _ in range(len(maps))]
    # print(money_map)
    queue = deque([[0, 0]])
    visit[0][0] = maps[0][0]
    while queue:
        x = queue[0][0]
        y = queue[0][1]
        # cnt = queue[0][2]
        queue.popleft()

        for i in range(4):
            mx = dx[i] + x
            my = dy[i] + y
            if mx >=0 and my >=0 and mx < len(maps) and my < len(maps):
                if visit[x][y] + maps[mx][my] < visit[mx][my]:
                    visit[mx][my] = visit[x][y] + maps[mx][my]
                    queue.append([mx, my])
    # print(money_map)
    return visit[len(maps)-1][len(maps)-1]

if __name__ == "__main__":
    n = int(input())
    cnt = 0
    while n!= 0:
        cnt+= 1
        maps.clear()
        for i in range(n):
            maps.append(list(map(int, input().split())))
        print("Problem ", cnt, ": ", bfs(maps))
        n = int(input())