if __name__ == '__main__':
    n = int(input())
    arr = map(int, input().split())
    new_arr = list(arr)
    tmp = max(new_arr)
    cnt = new_arr.count(tmp)

    for i in range(cnt):
        new_arr.remove(tmp)
    
    print(max(new_arr))