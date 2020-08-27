def solution(brown, yellow):
    answer = []
    for height in range(1, yellow+1):
        if yellow%height == 0:
            width = yellow/height
            if width < height:
                break
            if ((width+2) * (height+2)) - yellow == brown:
                answer = [int(width+2), int(height+2)]
    return answer

if __name__ == "__main__":
    brown = 10
    yello = 2
    print(solution(brown, yello))    