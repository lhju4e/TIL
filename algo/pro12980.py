def solution(n):
    ans = 0
    dist = [i for i in range(n+1)]
    # for i in range(1, n+1):
    #     if i%2 == 0:
    #         dist[i] = min(dist[int(i/2)], dist[i-1] + 1)
    #     else:
    #         dist[i] = dist[i-1] + 1
    idx = n
    while idx != 0:
        if idx%2 == 1:
            ans += 1
            idx -= 1
        else:
            idx = idx / 2

    return ans

if __name__ == "__main__":
    n = 5000
    print(solution(n))
