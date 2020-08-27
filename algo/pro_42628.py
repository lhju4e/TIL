import heapq

def solution(operations):
    answer = []
    # min_q = []
    # max_q = []
    # heapq.heapify(min_q)
    # heapq.heapify(max_q)
    # for i in operations:

    #     str_list = i.split()
    #     if str_list[0] == 'I':
    #         heapq.heappush(min_q, int(str_list[1]))
    #         heapq.heappush(max_q, -int(str_list[1]))
    #     elif str_list[0] == 'D':
    #         if str_list[1] == "1" and max_q:
    #             heapq.heappop(max_q)
    #             if max_q == [] or -max_q[0] < min_q[0]:
    #                 max_q = []
    #                 min_q = []
    #         elif str_list[1] == "-1" and min_q:
    #             heapq.heappop(min_q)
    #             if min_q == [] or min_q[0] > -max_q[0]:
    #                 min_q = []
    #                 max_q = []

    # if min_q == [] or max_q==[]:
    #     answer.append(0)
    #     answer.append(0)
    # else:
    #     answer.append(-heapq.heappop(max_q))
    #     answer.append(heapq.heappop(min_q))

    from collections import deque
    dq = deque()
    for i in operations:
        str_list = i.split()
        if str_list[0] == 'I':
            dq.append(int(str_list[1]))
            dq = deque(sorted(dq))
        elif str_list[0] == 'D':
            if str_list[1] == "-1" and dq:
                dq.popleft()
            elif str_list[1] == "1" and dq:
                dq.pop()
    if dq:
        answer.append(dq[-1])
        answer.append(dq[0])
    else:
        answer = [0,0]
    return answer

if __name__ == "__main__":
    # operations = ["I 16", "I -5643", "D -1", "D 1", "D 1", "I 123", "D -1"]
    operations = ["I 7", "I 5", "I -5", "D -1"]

    print(solution(operations))