import datetime

def check(money):
    if money>=0 and money < 10000:
        return 0
    elif money>= 10000 and money < 20000:
        return 1
    elif money >= 20000 and money < 50000:
        return 2
    elif money >= 50000 and money < 100000:
        return 3
    elif money >= 100000:
        return 4


def solution(input_):
    level = [] #날자. 0 : 브론즈. 1 : 실버. 2 : 골드. 3 : 플래 4: 다이아
    for i in range(5):
        level.append(0)
    input_parse = []

    for i in range(len(input_)):
        times =  input_[i].split(" ")[0]
        money = input_[i].split(" ")[1]
        day = datetime.date(int(times.split("/")[0]), int(times.split("/")[1]), int(times.split("/")[2])) - datetime.date(2019, 1,1)
        day_tuple = (day.days, day.days+30)
        input_parse.append((day_tuple,  int(money)))

    idx = 0
    idx2 = 0
    money = 0

    for day in range(1, 366):
        if idx >= len(input_parse):
            level[0] += (366 - day)
            break
        if idx2 >= len(input_parse):
            idx2 = -1

        if day > input_parse[idx][0][1]:
            money -= input_parse[idx][1]
            idx += 1    
        elif day > input_parse[idx2][0][0] and idx2 != -1:
            money += input_parse[idx2][1]
            idx2 += 1
                
        level[check(money)] += 1
                
    return level

if __name__ == "__main__":
    input_ = ["2019/01/30 5000", "2019/04/05 10000", "2019/06/10 20000", "2019/08/15 50000",
"2019/12/01 100000"]
    print(solution(input_))