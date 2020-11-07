paper = []

def solution(n, x, y):
    answer = [0, 0]
    # if n == 1:
    #     if paper[x][y]:
    #         return [0, 1]
    #     else:
    #         return [1, 0]
    white = 0
    black = 0

    for i in range(x, x+n):
        for j in range(y, y+n):
            if paper[i][j] == 0:
                white += 1
            else:
                black += 1

    if white == 0:
        return [0, 1]
    elif black == 0:
        return [1, 0]

    n = int(n/2)
    ans = solution(n, x, y)
    answer[0] += ans[0]
    answer[1] += ans[1]

    ans = solution(n, x+n, y)

    answer[0] += ans[0]
    answer[1] += ans[1]

    ans = solution(n, x, y+n)

    answer[0] += ans[0]
    answer[1] += ans[1]

    ans = solution(n, x+n, y+n)

    answer[0] += ans[0]
    answer[1] += ans[1]
    return answer

if __name__ == "__main__":
    n = int(input())
    for i in range(n):
        paper.append(list(map(int, input().split())))
    # print(paper[3][:3])
    answer = solution(n, 0, 0)
    for i in answer:
        print(i)
