def solution(participant, completion):
    d = {}
    for i in participant:
        d[i] = 0
    for i in participant:
        d[i] = d[i] + 1
    for i in completion:
        d[i] = d[i] - 1
        if d[i] == 0:
            del(d[i])
    answer = d.keys()
    answer = list(answer)
    return answer[0]

if __name__ == "__main__":
    participant = ["leo","kiki","eden"]
    completion = ["eden","kiki"]
    print(solution(participant, completion))
    