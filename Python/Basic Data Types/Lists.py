if __name__ == '__main__':
    l = list()
    N = int(input())
    for i in range(N):
        query = input().split()
        if query[0] == "insert":
            l.insert(int(query[1]), int(query[2]))
        elif query[0] == "print":
            print(l)
        elif query[0] == "remove":
            l.remove(int(query[1]))
        elif query[0] == "append":
            l.append(int(query[1]))
        elif query[0] == "sort":
            l.sort()
        elif query[0] == "pop":
            l.pop()
        elif query[0] == "reverse":
            l.reverse()