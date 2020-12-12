def solution(register_list, new_id):

    S = ''.join(list(filter(lambda x : x.isalpha(), new_id)))
    N = ''.join(list(filter(lambda x : x.isdigit(), new_id)))

    while new_id in register_list:
        if N:
            n = int(N)
        else:
            n = 0
        n += 1
        N = str(n)

        new_id = S + N

    return new_id



if __name__ == "__main__":
    register_list = ["cow", "cow1", "cow2", "cow3", "cow4", "cow9", "cow8", "cow7", "cow6", "cow5"]
    new_id = "cow"
    print(solution(register_list, new_id))