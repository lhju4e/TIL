def solution(numbers):
    answer = ''
    arr = sorted(numbers, key=lambda x: str(x)[0])

    print(arr)
    return answer

if __name__ == "__main__":
    numbers = [6, 11, 10, 13, 2]
    print(solution(numbers))