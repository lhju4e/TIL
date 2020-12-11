import sys
parent = []
def find(x):
    if x == parent[x]:
        return x
    else:
        parent[x] = find(parent[x])
        return parent[x]

def union(x, y):
    x = find(parent[x])
    y = find(parent[y])
    parent[x] = y


def solution(g, plane):
    answer = 0
    check = [True for _ in range(g+1)]
    for i in range(g+1):
        parent.append(i)
    for pp in plane:
        next_gate = find(pp)
        while True: # true찾을때까지 -1씩 하면서 찾아다님
            if next_gate == 0:
                return answer
            if check[next_gate] == True: #게이트에 자리있으면 넣어줌
                check[next_gate] = False
                answer += 1 #비행기 대수 증가
                break #while문 빠져나가는,,
            else:
                union(next_gate, next_gate-1)
                next_gate -= 1

    return answer

##도킹 숫자가 높은 곳에 ㅎㅏ는게 좋음!
# 이미 비행기가 있다 -> 한칸 낮춰서 도킹
# -> 0번째다? 그럼 프로그램 끝


if __name__ == "__main__":
    plane = []
    g = int(sys.stdin.readline().split()[0])
    p = int(sys.stdin.readline().split()[0])

    for i in range(p):
        plane.append(int(sys.stdin.readline().split()[0]))
    print(solution(g, plane))