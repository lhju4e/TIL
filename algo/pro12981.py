def solution(n, words):
    answer = [0, 0]
    dic = dict()
    for i in range(len(words)):
        if i >= 1:
            if words[i-1][-1] != words[i][0]:
                if (i+1)%n == 0:
                    answer[0] = n
                    answer[1] = int((i+1) / n)
                else:
                    answer[0] = int((i+1)%n)
                    answer[1] = int((i+1) / n) + 1
                return answer               
        if words[i] in dic:
            if (i+1)%n == 0:
                answer[0] = n
                answer[1] = int((i+1) / n)
            else:
                answer[0] = int((i+1)%n)
                answer[1] = int((i+1) / n) + 1
            return answer               
        else:
            dic[words[i]] = 1

    return answer

if __name__ == "__main__":
    n = 2
    words = ["hello", "one", "even", "never", "now", "world", "draw"]
    print(solution(n, words))