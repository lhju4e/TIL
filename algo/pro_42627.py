import heapq
def solution(jobs):
    answer = 0
    time = 0
    wait = []
    heapq.heapify(wait)
    task = []
    heapq.heapify(task)
    for i in jobs:
        heapq.heappush(task, (i[0], i[1]))

    while wait or task:
        while task:
            if time >= task[0][0]:
                a, b = heapq.heappop(task)
                heapq.heappush(wait, (b, a))
            else:
                break
        
        if wait:
            b, a = heapq.heappop(wait)
            answer += (time - a) + b
            time += b 
        else:
            time += 1   

    answer = answer / len(jobs)

    return int(answer)

if __name__ == "__main__":
    jobs = [[0, 3], [1, 9], [2, 6]]
    print(solution(jobs))