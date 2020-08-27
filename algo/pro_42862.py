def solution(n, lost, reserve):
    answer = 0
    student = [1]*31
    for i in lost:
        student[i] -= 1
    for i in reserve:
        student[i] += 1
    print(student[1:6])
    for i in range(1, n+1):
        if student[i] > 1:
            if student[i-1] == 0:
                student[i-1] += 1
                student[i] -= 1
            elif student[i+1] == 0:
                student[i+1] += 1
                student[i] -= 1
        print(student[1:6])
    print(student[1:6])
    for i in range(1, n+1):
        if student[i] != 0:
            answer += 1

    return answer

if __name__ == "__main__":
    n = 5
    lost = [3, 4, 5]
    reserve = [2, 3, 4]
    print(solution(n, lost, reserve))