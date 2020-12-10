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

def min_(list_):
    mins_ = list_[0].return_prior()
    idx = 0
    for i in range(1, len(list_)):
        prior_ = list_[i].return_prior()
        if mins_[0] > prior_[0]:
            mins_ = prior_
            idx = i
        elif mins_[0] == prior_[0] and mins_[1] > prior_[1]:
            mins_ = prior_
            idx = i
    # print("idx ", idx, " " , list_[idx])
    return list_[idx]

class Customer:
    def __init__(self, time, comes, hair_condition, clinic_list):
        self.prior = (time, comes)
        self.hair_condition = hair_condition
        self.clinic_list = deque(clinic_list)
    def return_prior(self):
        return (self.prior[0], self.prior[1])
    def change_time(self, time):
        self.prior = (self.prior[0] + time, self.prior[1])
    def clinic_check(self):
        check = False
        for i in self.clinic_list:
            if i == '클리닉':
                return True
        return check
    def get_hair(self): #머리 컨디션 체크, 어떤 헤어 할지
        if not self.clinic_list:
            return None

        hair = self.clinic_list.popleft()
        condition = self.hair_condition
        if hair == '파마' or hair == '염색':
            if condition < 2: #머리 상태가 2보다 안좋으면 못하는 시술들 
                if self.clinic_check() : #클리닉이 있으면
                    self.clinic_list.appendleft(hair) # 뺏던거 다시 넣고
                    self.clinic_list.remove('클리닉')
                    hair = '클리닉' #클리닉 먼저 받기
                else:
                    hair = None
                    while self.clinic_list: #커트랑 드라이가 있는지 체크
                        hair = self.clinic_list.popleft()
                        if hair == '커트':
                            break
                        if hair == '드라이':
                            break
                        hair = None #break에 안걸리고 customer가 다 비워졌다면 할 수 있는 hair가 없는것 -> 머릿결이 안좋고, 클리닉과 커트가 없음

        if hair == '드라이':
            if condition < 1:
                if self.clinic_check() : #클리닉이 있으면
                    self.clinic_list.appendleft(hair) # 뺏던거 다시 넣고
                    self.clinic_list.remove('클리닉')
                    hair = '클리닉' #클리닉 먼저 받기
                else:
                    hair = None
                    while self.clinic_list: #커트랑 드라이가 있는지 체크
                        hair = self.clinic_list.popleft()
                        if hair == '커트':
                            break
                        hair = None #break에 안걸리고 customer가 다 비워졌다면 할 수 있는 hair가 없는것 -> 머릿결이 안좋고, 클리닉과 커트가 없음
        return hair

    def change_condition(self, hair):
        if hair == '파마':
            self.hair_condition -= 2
            self.change_time(120)
        elif hair == '클리닉':
            self.hair_condition += 2
            self.change_time(30)
        elif hair == '염색' :
            self.hair_condition -= 2
            self.change_time(60)
        elif hair == '드라이':
            self.hair_condition -= 1
            self.change_time(20)
        elif hair == '커트':
            self.change_time(40)
  
class Employee:
    # level 1 : 디자이너 2 : 실장 3 : 원장
    money = 0
    def __init__(self, time, level):
        self.time = time
        self.level = level
    def change_time(self, time):
        self.time += time
    def return_prior(self):
        return (self.time, self.level) 
    def check_skill(self, hair):
        if self.level == 3 and hair == '클리닉':
            return False
        elif self.level == 2 and (hair == '드라이' or hair == '클리닉'):
            return False
        elif self.level == 1 and (hair == '드라이' or hair == '파마'):
            return False
    def do_clinic(self, hair):
        if hair == '파마':
            self.change_time(120)
            Employee.money += 20
        elif hair == '클리닉':
            self.change_time(30)
            Employee.money += 10
        elif hair == '염색' :
            self.change_time(60)
            Employee.money += 12
        elif hair == '드라이':
            self.change_time(20)
            Employee.money += 7
        elif hair == '커트':
            self.change_time(40)
            Employee.money += 5
  

if __name__ == "__main__":
    n, m, k = map(int, input().split())
    money = 0
    customers = []

    for i in range(k):
        tmp = input().split('"')
        customer = Customer(0, i, int(tmp[3]), tmp[7].replace(" ", "").split(','))
        customers.append(customer)
        # customers.append(tmp2) 
    
    # #customers : (시간, 도착순위)_우선순위, 머릿결, 시술목록(큐)를 이차원 리스트로 관리
    # # => 앞의 시간, 도착순위를 이용하여 우선순위큐로 손님 순서를 정함

    # #employees : (시간, 직급)_우선순위
    employees = []
    employees.append(Employee(0, 3))
    employees.append(Employee(0, 3))
   
    for i in range(n):
        employee = Employee(0, 2)
        employees.append(employee)
    for i in range(m):
        employee = Employee(0, 1)
        employees.append(employee)
    
    while customers: # 손님이 존재하면
        # print("=========================================")

        #손님 선정 및 헤어 시술 선정
        customer = min_(customers)
        customers.remove(customer)
        # heapq.heappush(customers, customer)

        (customer_time, customer_prior) = customer.return_prior()
        
        # print("customer time, prior ", customer_time, customer_prior)

        hair = customer.get_hair()

        # print(hair)

        employee_tmp_list = []

        if hair:
            employee = min_(employees)
            employees.remove(employee)
            while employee.check_skill(hair) == False: #헤어 시술 못하면(거짓이면) 계속 돌림
                employee_tmp_list.append(employee)
                employee = min_(employees)
                employees.remove(employee)
        
            for i in employee_tmp_list:
                employees.append(i)

            (employee_time, _) = employee.return_prior()
            
            # for i in employees:
            #     print("employee? ", i.return_prior()[0], i.return_prior()[1])
            # print("employee time, prior ", employee_time, _)


        #대기시간 맞추기
            if employee_time > customer_time:
                customer.change_time(employee_time - customer_time)
            else:
                employee.change_time(customer_time - employee_time)
                    
                    
            # print("customer time, prior ", customer.return_prior()[0], customer_prior)

            customer.change_condition(hair)

            # print("customer time, prior ", customer.return_prior()[0], customer_prior)

            employee.do_clinic(hair)

            employees.append(employee)
            customers.append(customer)

    #최종 계산
    answer_time = 0
    answer_money = Employee.money
    for employee in employees:
        if employee.time > answer_time:
            answer_time = employee.time
    
    print(answer_time//60, "시간 ", answer_time%60, "분 ", answer_money, "만원")