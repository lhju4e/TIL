from queue import PriorityQueue

# def solution(scoville, K):
#     answer = 0
#     q = PriorityQueue()
#     for i in scoville:
#         q.put(i)

#     while q.qsize()>1:
#         food1 = q.get()
#         print("food1 : ", food1)
#         if food1 >= K:
#             return answer
#         else:
#             answer += 1
#             food2 = q.get()
#             print("food2 : ", food2)
#             new_food = food1 + (2*food2)
#             q.put(new_food)

#     return -1
import heapq
def solution(scoville, K):
    answer = 0
    heapq.heapify(scoville)
    while scoville:
        food1 = heapq.heappop(scoville)
        if food1 >= K:
            return answer
        elif len(scoville) >0:
            answer += 1
            food2 = heapq.heappop(scoville)
            new_food = food1 + (2*food2)
            heapq.heappush(scoville, new_food)
    return -1


if __name__ == "__main__":
    scoville = [1, 2, 3, 9, 10, 12]
    K = 500
    print(solution(scoville, K))