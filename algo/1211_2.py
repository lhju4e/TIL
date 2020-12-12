def solution(ip_address, langs, scores):
    answer = len(ip_address)
    dic = dict()
    for i in range(len(ip_address)):
        if ip_address[i] not in dic:
            dic[ip_address[i]] = [i]
        else:
            dic[ip_address[i]].append(i)
    
    for i in range(len(langs)):
        if langs[i] in ["C", "C++", "C#"]:
            langs[i] = "C" #같은군집 그냥 같은 언어로 치환

    for ip, value_list in dic.items():
        if len(value_list) >= 4:
            answer -= len(value_list)
        elif len(value_list) == 3:
            if (langs[value_list[0]] == langs[value_list[1]]) and (langs[value_list[1]] == langs[value_list[2]]):
                answer -= 3
        elif len(value_list) == 2:
            if langs[value_list[0]] == langs[value_list[1]] and scores[value_list[0]] == scores[value_list[1]]:
                answer -= 2

    return answer





if __name__ == "__main__":
    ip_addrs = ["7.124.10.0", "7.124.10.0", "0.0.0.0", "7.124.10.0", "0.0.0.0", "7.124.10.0"] 
    langs = [ " C++" ,
"Java", "C#", "C#", "C", "Python3"]
    scores = [314, 225, 45, 0, 155, 400]
    print(solution(ip_addrs, langs, scores))