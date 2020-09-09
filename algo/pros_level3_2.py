from collections import deque
def solution(board):
    answer = 0
    dq = deque()
    board_cost = []
    board_cost = [[[0 for col in range(4)] for row in range(len(board[0]))] for depth in range(len(board))]
    
    dxy = [(0, 1),(0, -1), (-1, 0), (1, 0)]
    dq.append((0, 0, -1))
    board[0][0] = 1

    # print(board[4, 2])
    # print(board_cost[4, 2, 3])
    # board_cost에 방향마다의 최소값을 넣어주어야 함.
    while dq:
        (x, y, direction) = dq[0]
        dq.popleft()
        for idx in range(len(dxy)):
            x_ = x + dxy[idx][0]
            y_ = y + dxy[idx][1]
            if x_>=0 and y_>=0 and x_<len(board) and y_<len(board[0]) and board[x_][y_] == 0:
                if board_cost[x_][y_][idx] == 0:
                    dq.append((x_, y_, idx))
                    board_cost[x_][y_][idx] = board_cost[x][y][direction] + 100
                    if direction != idx:
                        board_cost[x_][y_][idx] += 500
                else:
                    tmp = board_cost[x][y][direction] + 100
                    if direction != idx:
                        tmp += 500
                    if board_cost[x_][y_][idx] > tmp:
                        dq.append((x_, y_, idx))
                        board_cost[x_][y_][idx] = tmp
    answer_list = []
    for i in range(4):
        if board_cost[len(board)-1][len(board[0])-1][i] != 0:
            answer_list.append(board_cost[len(board)-1][len(board[0])-1][i])
    answer = min(answer_list)
    answer -= 500
    # 맨 처음 direction값 때문에 -500 해줘야함

    # for i in range(len(board_cost)):
    #     for j in range(len(board_cost[0])):
    #         print(board_cost[i][j][0], end=' ')   
    #     print()     

    # print("===")
    
    # for i in range(len(board_cost)):
    #     for j in range(len(board_cost[0])):
    #         print(board_cost[i][j][1], end=' ')   
    #     print()   
    # print("===")
    # for i in range(len(board_cost)):
    #     for j in range(len(board_cost[0])):
    #         print(board_cost[i][j][2], end=' ')   
    #     print()  
    # print("===")

    # for i in range(len(board_cost)):
    #     for j in range(len(board_cost[0])):
    #         print(board_cost[i][j][3], end=' ')   
    #     print()          
    # print(board_cost)

    return answer

if __name__ == "__main__":
    # board = [[0,0,0],[0,0,0],[0,0,0]]
    board = [[0,0,0,0,0,0,0,1],[0,0,0,0,0,0,0,0],[0,0,0,0,0,1,0,0],[0,0,0,0,1,0,0,0],[0,0,0,1,0,0,0,1],[0,0,1,0,0,0,1,0],[0,1,0,0,0,1,0,0],[1,0,0,0,0,0,0,0]]
    # board = [[0,0,0],[0,0,0]]
    print(solution(board))