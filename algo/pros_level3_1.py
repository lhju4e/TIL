def solution(geners, plays):
    answer = []
    dic = {}
    for i in range(len(geners)):
        if dic.get(geners[i]):
            dic[geners[i]] += plays[i]
        else:
            dic[geners[i]] = plays[i]

    genere_list = []
    for i, j in dic.items():
        genere_list.append((i, j))
    genere_list = sorted(genere_list, key = lambda x : x[1], reverse=True)
    # print(genere_list)

    for k in genere_list:
        tmp_list = []
        for i in range(len(geners)):
            if k[0] == geners[i]:
                tmp_list.append((plays[i], i))
        tmp_list = sorted(tmp_list, key = lambda x : x[0], reverse = True)
        # print(tmp_list)
        answer.append(tmp_list[0][1])
        if len(tmp_list) >1:
            answer.append(tmp_list[1][1])

    return answer
    

if __name__ == "__main__":
    geners = ["classic", "pop", "classic", "classic", "pop", "toxic"]
    plays = [500, 600, 800, 800, 2500, 100]
    print(solution(geners, plays))