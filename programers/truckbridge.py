from collections import deque


def solution(bridge_length, weight, truck_weights):
    answer = 0
    num = 0
    w = 0
    bridge = deque([0] * bridge_length)

    while num < len(truck_weights):
        answer += 1
        truck = bridge.popleft()
        if truck != 0:
            w -= truck

        if w + truck_weights[num] <= weight:
            w += truck_weights[num]
            bridge.append(truck_weights[num])
            num += 1
        else:
            bridge.append(0)

    return answer + bridge_length


print(solution(100, 100, [10]))
