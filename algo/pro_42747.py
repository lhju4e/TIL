
def solution(citations):
    answer = 0
    citations.sort()
    idx = 0
    for i in range(len(citations)+1):
        while idx < len(citations) and citations[idx] <= i:
            idx += 1

        h = len(citations) - idx
        print(i, h)
        if h >= i:
            answer = h
    return answer


if __name__ == "__main__":
    citations = [10,3,6,8,17,21]
    print(solution(citations))

