play = []
def solution(n, x, y):
    answer = ""
    if n == 1:
        return play[x][y]
    cnt_1 = 0
    cnt_0 = 0
    for i in range(x, x+n):
        for j in range(y, y+n):
            if play[i][j] == "0":
                cnt_0 += 1
            else:
                cnt_1 += 1
    if cnt_1 == 0:
        return "0"
    elif cnt_0 == 0:
        return "1"
        
    answer += "("
    n = n//2
    answer += solution(n, x, y)
    
    answer += solution(n, x, y+n)
    
    answer += solution(n, x+n, y)
    
    answer += solution(n, x+n, y+n)
    answer += ")"
    return answer


if __name__ == "__main__":
    n = int(input())
    for i in range(n):
        play.append(list(input()))
    answer = solution(n, 0, 0)
    print(answer)