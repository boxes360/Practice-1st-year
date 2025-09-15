def main():
    h, w = map(int, input().split())

    matrix = []
    for i in range(h):
        row = list(map(int, input().split()))
        matrix.append(row)

    min_row = h
    max_row = -1
    min_col = w
    max_col = -1

    for i in range(h):
        for j in range(w):
            if matrix[i][j] == 1:
                if i < min_row:
                    min_row = i
                if i > max_row:
                    max_row = i
                if j < min_col:
                    min_col = j
                if j > max_col:
                    max_col = j

    top_left_row = min_row - 1
    top_left_col = min_col - 1
    bottom_right_row = max_row + 1
    bottom_right_col = max_col + 1

    print(f"{top_left_row} {top_left_col} {bottom_right_row} {bottom_right_col}")

if __name__ == "__main__":
    main()
