if __name__ == '__main__':
    students = {}
    score_arr = set()
    for _ in range(int(input())):
        name = input()
        score = float(input())
        if score not in students:
            students[score] = list()
        students[score].append(name)
        score_arr.add(score)
    score_arr = sorted(score_arr)
    res = sorted(students[score_arr[1]])
    for s in res:
        print(s)