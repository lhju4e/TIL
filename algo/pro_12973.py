def solution(s):
    answer = 0
    stack = []
    for i in s:
        if len(stack)>0:
            if stack[-1] == i:
                stack.pop()
            else:
                stack.append(i)
        else:
            stack.append(i)
    
    if stack:
        answer = 0
    else:
        answer = 1
    return answer

if __name__ == "__main__":
    s = "baabaa"
    print(solution(s))