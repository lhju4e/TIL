def solution(phone_book):
    answer = True
    phone_book = sorted(phone_book)
    for i in range(len(phone_book)-1):
        for j in range(len(phone_book) -i -1):
            if phone_book[j+i+1].startswith(phone_book[i]):
                return False
    return answer

if __name__ == "__main__":
    phone_book = ["123","456","789"]
    print(solution(phone_book))
