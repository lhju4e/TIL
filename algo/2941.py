import sys

def solution(strs):
    change_list = ["c=", "c-", "d-", "lj", "nj", "s=", "z="]
    answer = len(strs)
    if answer != 0:
        answer -= 1
    for i in change_list:
        idx = 0
        idx = strs.find(i) + 1
        while idx != 0 and idx < len(strs):
            answer -= 1
            idx = strs.find(i, idx) + 1
    idx = strs.find("dz=") + 1
    while idx != 0 and idx < len(strs):
        answer -= 1
        idx = strs.find("dz=", idx) + 1
    return answer



if __name__ == "__main__":
    ins = sys.stdin.readline()
    print(solution(ins))