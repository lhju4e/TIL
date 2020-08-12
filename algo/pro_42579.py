import collections
def solution(genres, plays):
    answer = []
    dic = {}
    gener_list = {}
    for i in range(len(geners)):
        if geners[i] in dic:
            dic[geners[i]] += plays[i]  
        else:
            dic[geners[i]] = plays[i]
            gener_list[geners[i]] = []
        gener_list[geners[i]].append((plays[i], i))

    dic = sorted(dic.items(), key=(lambda x: x[1]), reverse=True)
    # print(dic)
    # print(sorted(gener_list["classic"], reverse=True))
    for i, j in dic:
        # gener_list[i] = sorted(gener_list[i], key=(lambda x: x[1]))
        # print(gener_list[i])
        gener_list[i] = sorted(gener_list[i], key=(lambda x: x[0]), reverse=True)[:2]
        for x in gener_list[i]:
            answer.append(x[1])
    return answer

if __name__ == "__main__":
    geners = ["classic", "pop", "classic", "classic", "pop"]
    plays = [500, 600, 150, 800, 600]
    print(solution(geners, plays))