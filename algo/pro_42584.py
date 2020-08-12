def solution(prices):
    answer = []
    for i in range(len(prices)-1):
        t = len(prices) - i - 1
        for j in range(i+1, len(prices)):
            if prices[i] > prices[j]:
                t = j - i
                break
        answer.append(t)
    answer.append(0)

    return answer

if __name__ == "__main__":
    prices = [1,2,3,2,3]
    print(solution(prices))