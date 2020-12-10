###################################
# input format
# 1 1 5 (N, M, K)
# {"머릿결" : "5", "시술목록" : "커트, 파마, 염색"}
# {"머릿결" : "2", "시술목록" : "파마, 염색"}
# {"머릿결" : "0", "시술목록" : "드라이, 클리닉"}
# {"머릿결" : "1", "시술목록" : "커트, 드라이"}
# {"머릿결" : "3", "시술목록" : "염색"}
###################################

###################################
# output format
# 3시간 40분, 98만원
###################################

from collections import deque
import heapq

def clinic_check(dq):
    check = False
    for i in dq:
        if i == '클리닉':
            return True
    return check

if __name__ == "__main__":
    n, m, k = map(int, input().split())
    customers = []
    money = 0
    for i in range(k):
        tmp = input().split('"')
        tmp2 = []
        tmp2.append((0, i)) # (시간, 우선순위)
        tmp2.append(int(tmp[3])) # 머릿결
        tmp2.append(deque(tmp[7].replace(" ", "").split(','))) # 시술목록
        customers.append(tmp2) 
        
    #customers : (시간, 도착순위)_우선순위, 머릿결, 시술목록(큐)를 이차원 리스트로 관리
    # => 앞의 시간, 도착순위를 이용하여 우선순위큐로 손님 순서를 정함

    #employees : (시간, 직급)_우선순위
    employees = []
    employees.append([(0,2), (0,2)])
    employees.append([(0,1) for i in range(n)])
    employees.append([(0,0) for i in range(m)])
    employees = sum(employees, []) #2차원배열 -> 1차원 배열

    #직급에 따라 시술받을 수 있는 것이 다름 - 체크하기 위한 코드
    onezang_check = ['파마', '염색', '드라이', '커트']
    silzang_check = ['파마', '염색', '커트']
    designer_check = ['염색', '커트', '클리닉']

    employee_check = []
    employee_check.append(designer_check)
    employee_check.append(silzang_check)
    employee_check.append(onezang_check)

    # print(customers)
    heapq.heapify(employees)
    heapq.heapify(customers)
    # print("employee ", employees)

    while customers: # 손님이 존재하면
        # print("=========================================")

        #손님 선정 및 헤어 시술 선정
        customer = heapq.heappop(customers)
        # heapq.heappush(customers, customer)

        customer_time = customer[0][0]
        customer_prior = customer[0][1]
        # print("time, prior ", customer_time, customer_prior)
        condition = customer[1]
        # print("condition : ", condition)
        hair = customer[2].popleft() #큐에서 우선순위 헤어 빼기

        print("=================")
        print("customer_proior ", customer_prior)
        print("hair_condition ", condition)
        print(hair)

#이부분 약간.. 위험
        if hair == '파마' or hair == '염색':
            if condition < 2: #머리 상태가 2보다 안좋으면 못하는 시술들
                print("bad condition")
                if clinic_check(customer[2]) : #클리닉이 있으면
                    customer[2].appendleft(hair) # 뺏던거 다시 넣고
                    customer[2].remove('클리닉')
                    hair = '클리닉' #클리닉 먼저 받기
                else:
                    hair = None #코테 이후 추가
                    while customer[2]: #커트랑 드라이가 있는지 체크
                        hair = customer[2].popleft()
                        if hair == '커트':
                            break
                        if hair == '드라이':
                            break
                        #인덴트 안넣음!!!!!!!!!!!
                        hair = None #break에 안걸리고 customer가 다 비워졌다면 할 수 있는 hair가 없는것 -> 머릿결이 안좋고, 클리닉과 커트가 없음
        
        if hair == '드라이':
            if condition < 1:
                if clinic_check(customer[2]) : #클리닉이 있으면
                    customer[2].appendleft(hair) # 뺏던거 다시 넣고
                    customer[2].remove('클리닉')
                    hair = '클리닉' #클리닉 먼저 받기
                else:
                    hair = None #코테 이후 추가!
                    while customer[2]: #커트랑 드라이가 있는지 체크
                        hair = customer[2].popleft()
                        if hair == '커트':
                            break
                        #여기도 마찬가지로..
                        hair = None #break에 안걸리고 customer가 다 비워졌다면 할 수 있는 hair가 없는것 -> 머릿결이 안좋고, 클리닉과 커트가 없음

        print("hair? ", hair)

        if hair:
                
            #디자이너 선택
            tmp = []
            tmp.append(heapq.heappop(employees))
            while not hair in employee_check[tmp[-1][1]]:
                tmp.append(heapq.heappop(employees))
            
            employee_time = tmp[-1][0]
            employee_prior = tmp[-1][1]

            #대기시간 맞추기
            if employee_time > customer_time:
                customer_time = employee_time
            else:
                employee_time = customer_time

            #시술
            if hair == '파마':
                condition -= 2
                customer_time += 120
                employee_time += 120
                money += 20
            elif hair == '클리닉':
                condition += 2
                customer_time += 30
                employee_time += 30
                money += 10
            elif hair == '염색' :
                condition -= 2
                customer_time += 60
                employee_time += 60
                money += 12
            elif hair == '드라이':
                condition -= 1
                customer_time += 20
                employee_time += 20
                money += 7
            elif hair == '커트':
                customer_time += 40
                employee_time += 40
                money += 5


            tmp[-1] = (employee_time, employee_prior)
            # print("employees ", employees)
            for i in tmp:
                employees.append(i)
            # print("employees ", employees)

            # print("customer1 ", customers)

        if customer[2]: #헤어 시술할 것이 남아있다면
            customer[0] = (customer_time, customer_prior)
            customer[1] = condition
            customers.append(customer) #다시 넣어주기


    time = 0
    for i in employees:
        if i[0] > time:
            time = i[0]
    
    print(time//60, "시간 ", time%60, "분 ", money, "만원")




        






    













