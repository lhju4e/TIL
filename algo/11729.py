def solution(n, start, end):
    answer = []
    # print(n, start, end)
    if n == 1:
        return [(start, end)]
    else:
        answer = solution(n-1, start, 6 - start - end) + [(start, end)] + solution(n-1, 6 - start - end, end)       
        # print(type(solution(n-1, 1, 2)))
        return answer

if __name__ == "__main__":
    n = int(input())
    answer = solution(n, 1, 3)
    print(len(answer))
    for i in answer:
        print(i[0], i[1])