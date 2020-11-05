parent = dict()

def solution(people):
    answer = []
    parent.clear()
    for i in range(len(people)):
        if not people[i][0] in parent:
            parent[people[i][0]] = "1"
        if not people[i][1] in parent:
            parent[people[i][1]] = "1"
        answer.append(Union(people[i][0], people[i][1]))
    return answer

def Find(x):
    if parent[x].isdigit():
        return x
    else:
        y = Find(parent[x])
        parent[x] = y
        return y

def Union(x, y):
    x = Find(x)
    y = Find(y)
    if x == y:
        return parent[x]
    tmp = int(parent[x])
    # print("x " , x, " num ", tmp)
    # print("y ", y, " num ", parent[y])
    parent[x] = y
    parent[y] = int(parent[y]) + tmp
    parent[y] = str(parent[y])
    return parent[y]

if __name__ == "__main__":
    t = int(input())
    answer = []
    people = []
    for tt in range(t):
        f = int(input())
        people.clear()
        for i in range(f):
            people.append(input().split())
        answer += solution(people)
    for i in answer:
        print(i)