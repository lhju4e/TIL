from itertools import permutations

def func(expression, oper, n):
    if n == 2:
        # print("expression : ", expression)
        return str(eval(expression))
    if oper[n] == "+":
        exlist = expression.split(oper[n])
        for i in range(len(exlist)):
            exlist[i] = func(exlist[i], oper, n+1)
        expression = "+".join(exlist)
        return str(eval(expression))

        # expression = "+".join(exlist)
    elif oper[n] == "-":
        # print(expression)
        exlist = expression.split(oper[n])
        # print(" - exlist : ", exlist)
        for i in range(len(exlist)):
            exlist[i] = func(exlist[i], oper, n+1)
        # print("- exlist : ", exlist)
        expression = "-".join(exlist)
        # print("- expression : ", expression)
        return str(eval(expression))
  
    elif oper[n] == "*":
        exlist = expression.split(oper[n])
        # print(" * ", exlist)
        for i in range(len(exlist)):
            if not exlist[i].isdigit():
                exlist[i] = func(exlist[i], oper, n+1)
        # print(" * " , exlist)
        expression = "*".join(exlist)
        # print(" * " , expression)
        return str(eval(expression))

def solution(expression):
    
    answer = 0
    items = ['-', '+', '*']
    order_item = list(map(''.join, permutations(items)))
    for i in order_item:
        answer = max(abs(int(func(expression, i, 0))), answer)
    # answer = func(expression, "*-+", 0)
    return answer

if __name__ == "__main__":
    ex = "100-200*300-500+20"
    print(solution(ex))

    