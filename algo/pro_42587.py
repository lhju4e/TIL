from collections import deque

def solution(priorities, location):
    answer = 0
    label = [0]*len(priorities)
    label[location] = 1
    order = deque([])
    for i, j in zip(priorities, label):
        order.append((i, j))
    
    while order:
        n = order.popleft()
        if order and n[0] < max(order)[0]:
            order.append(n)
        else:
            answer+= 1
            if n[1] == 1:
                return answer    

if __name__ == "__main__":
    priorities = [3, 3, 4, 2]
    location = 3
    print(solution(priorities, location))