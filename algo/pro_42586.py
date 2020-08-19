import collections
def solution(progresses, speeds):
    answer = []
    days = []
    for i, j in zip(progresses, speeds):
        day = (100 - i) / j
        if (100 - i) % j != 0:
            day += 1
        days.append(int(day))
  
    idx = 0
    next_idx = idx + 1
    ans = 1
    while next_idx < len(days):
        if days[idx] >= days[next_idx]:
            ans += 1
            next_idx += 1
        else:
            idx = next_idx
            next_idx = idx + 1
            answer.append(ans)
            ans = 1
    answer.append(ans)
    return answer

if __name__ == "__main__":
    progresses = [93, 30, 55]
    speeds = [1, 30, 5]
    print(solution(progresses, speeds))