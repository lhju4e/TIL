def solution(n, input_list):
    union_list =[i for i in range(n+1)]
    for i in input_list:
        if i[0] == 0:
            Union(i[1], i[2], union_list)
        elif i[0] == 1:
            if Find(i[1], union_list) == Find(i[2], union_list):
                print("YES")
            else:
                print("NO")

def Find(x, parent):
    if x == parent[x]:
        return x
    else:
        y = Find(parent[x], parent)
        parent[x] = y
        return y

def Union(x, y, parent):
    x = Find(x, parent)
    y = Find(y, parent)
    parent[x] = y

if __name__ == "__main__":
    nm = list(map(int, input().split()))
    input_list = []
    for m in range(nm[1]):
        input_list.append(list(map(int, input().split())))
    solution(nm[0], input_list)