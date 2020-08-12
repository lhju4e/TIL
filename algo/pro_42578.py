from collections import Counter
def solution(clothes):
    answer = 1
    # dic={}
    # for i in clothes:
    #     if i[1] in dic:
    #         dic[i[1]] = dic[i[1]] + 1
    #     else:
    #         dic[i[1]] = 1

    dic = Counter([kind for name, kind in clothes])

    num_list = list(dic.values())
    for i in num_list:
        answer = answer * (i+1)
    return answer - 1

if __name__ == "__main__":
    clothes = [["yellow_hat", "headgear"], ["blue_sunglasses", "eyewear"], ["green_turban", "headgear"]]
    print(solution(clothes))