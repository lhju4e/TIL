def solution(land):
    answer = 0
    for i in range(1, len(land)):
        for j in range(4):
            tmp = 0
            for k in range(4):
                if k!= j:
                    tmp = max(tmp, land[i-1][k])
            land[i][j] = tmp + land[i][j]
    
    for i in range(4):
        if answer < land[len(land)-1][i]:
            answer = land[len(land)-1][i]
    return answer


if __name__ == "__main__":
    land = [[1,2,3,5],[5,6,7,8],[4,3,2,1]]
    print(solution(land))