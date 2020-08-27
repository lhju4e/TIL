from itertools import permutations
from math import sqrt
def solution(numbers):
    answer = 0
    all_numbers = []
    per = []
    for i in numbers:
        all_numbers.append(i)
    for i in range(1, len(numbers)+2):
        tmp = list(map(''.join, permutations(all_numbers, i)))
        per = per + tmp
    per = list(map(int, per))
    per = set(per)
    per = list(per)
    per.sort()
    print(per)
    for i in range(2, int(sqrt(per[-1]))):
        for j in range(len(per)):
            if per[j] != -1:
                if per[j]%i == 0 and per[j]!= i:
                    per[j] = -1
    print(per)
    for i in per:
        if i!= -1 and i!= 0  and i!= 1:
            answer += 1
    return answer

if __name__ == "__main__":
    numbers = "011"
    print(solution(numbers))