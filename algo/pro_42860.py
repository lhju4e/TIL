def solution(name):
    answer = 0
    idx_list = [0] # 0번은 무조건 들어감. 시작위치
    for i in range(1, len(name)):
        if name[i] != 'A':
            idx_list.append(i)
    idx = 0 #현재 위치
    i = idx + 1 #현재 위치에서 오른쪽으로 한칸
    j = len(idx_list) - 1 #현재 위치에서 왼쪽으로 한칸
    while True:
        answer += min((ord(name[idx_list[idx]]) - ord("A")), 26-(ord(name[idx_list[idx]])-ord("A")))

        #오른쪽으 로
        if i != idx and i < len(idx_list):
            tmp = (idx_list[i] - idx_list[idx])
        else:
            tmp = 100
        #왼쪽으로
        if j != idx and j >=0:
            tmp2 = (len(name) - (idx_list[j] - idx_list[idx]))
        else:
            tmp2 = 100

        idx_list[idx] = -1
        if all(i==-1 for i in idx_list):
            break

        if tmp!= 100 and tmp2!= 100 and tmp <= tmp2:
            idx = i
            i += 1
            answer += tmp
        elif tmp!= 100 and tmp > tmp2:
            idx = j
            j -= 1
            answer += tmp2

    return answer

if __name__ == "__main__":
    print(solution("BBAABBB"))