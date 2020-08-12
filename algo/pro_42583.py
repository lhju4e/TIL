from collections import deque

def solution(bridge_length, weight, truck_weights):
    wait = deque(truck_weights)
    bridge = deque([])

    time = 0
    now_weight = 0

    while wait :
        if bridge:
            if time - bridge[0][1] == bridge_length:
                now_weight -= bridge[0][0]
                bridge.popleft()

        if now_weight + wait[0] <= weight and len(bridge) <= bridge_length:
            now_weight += wait[0]
            bridge.append((wait.popleft(), time))
        time += 1
    return time + bridge_length

if __name__ == "__main__":
    bridge_length = 100
    weight = 100
    truck_weights=[10,10,10,10,10,10,10,10,10,10]
    print(solution(bridge_length, weight, truck_weights))