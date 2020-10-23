def solution(board):
    for i in range(1, len(board)):
        for j in range(1, len(board[0])):
            if board[i][j] != 0:
                board[i][j] = min(min(board[i-1][j-1], board[i-1][j]), board[i][j-1]) + 1
    answer = 0
    
    # for i in range(1, len(board)):
    #     for j in range(1, len(board[0])):
    #         print(board[i][j], end = ' ')
    #     print()

    for i in range(len(board)):
        answer = max(answer, max(board[i]))
        
    answer = answer * answer

    return answer

if __name__ == "__main__":
    board = [[1,0],[0,0]]
    print(solution(board))