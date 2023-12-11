// https://zerojudge.tw/ShowProblem?problemid=m372

#include <stdio.h>
#include <string.h>

int group_id = 0;
int group_cnt = 0;

// 如果能連到右邊，回傳1，否則回傳0
int connect_right(char left, char right) {
    if (strchr("XHFL", left) != NULL) {
        if (strchr("XH7J", right)) {
            return 1;
        }
    }
    return 0;
}

// int is_left_connected(char a, char b) {
// 	if (strchr("XH7J", a)!=NULL) {
// 		return strchr("XHFL", b)!=NULL;
// 	}
// 	return 0;
// }

// int is_top_connected(char a, char b) {
// 	if (strchr("XILJ", a)!=NULL) {
// 		return strchr("XI7F", b)!=NULL;
// 	}
// 	return 0;
// }

// 如果能連到下面，回傳1，否則回傳0
int connected_bottom(char top, char bottom) {
    if (strchr("XI7F", top) != NULL) {
        if (strchr("XILJ", bottom) != NULL) {
            return 1;
        }
    }
    return 0;
}

// 給定一個起始點，找出鄰居是否可通
// int connect_neighbor(int r, int c, int rows, int cols, int cells[rows][cols]) {
//     // 上下左右
//     int neighbors[4][2] = { { r - 1, c }, { r + 1, c }, { r, c - 1 }, { r, c + 1 } };
//     for (int i = 0; i < 4; i++) {
//         int nr = neighbors[i][0];
//         int nc = neighbors[i][1];
//         if (nr >= 0 && nr < rows && nc >= 0 && nc < cols) {
//             if (cells[nr][nc] == 1) {
//                 return 1;
//             }
//         }
//     }
//     return 0;
// }

// 給定一個起始點，找出鄰居是否可通
int connect_neighbor(int r, int c, int rows, int cols, int cells[rows][cols], int sum) {
    int neighbor_cnt = 0;
    int connect_cnt = 0;
    cells[r][c] = 0;
    // 上
    if (r - 1 >= 0 && cells[r - 1][c] != 0) {
        if (connected_bottom(cells[r - 1][c], cells[r][c])) {
            cells[r - 1][c] = '0';
            sum++;
            sum = connect_neighbor(r - 1, c, rows, cols, cells, sum);
        }
    }
    // 下
    if (r + 1 < rows && cells[r + 1][c] != 0) {
        if (connected_bottom(cells[r][c], cells[r + 1][c])) {
            cells[r + 1][c] = '0';
            sum++;
            sum = connect_neighbor(r + 1, c, rows, cols, cells, sum);
        }
    }

    // 左
    if (c - 1 >= 0 && cells[r][c - 1] != 0) {
        if (connect_right(cells[r][c - 1], cells[r][c])) {
            cells[r][c - 1] = '0';
            sum++;
            sum = connect_neighbor(r, c - 1, rows, cols, cells, sum);
        }
    }
    // 右
    if (c + 1 < cols && cells[r][c + 1] != 0) {
        if (connect_right(cells[r][c], cells[r][c + 1])) {
            cells[r][c + 1] = '0';
            sum++;
            sum = connect_neighbor(r, c + 1, rows, cols, cells, sum);
        }
    }

    return 0;
}

void print_layout(int rows, int cols, int cells[rows][cols]) {
    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < cols; c++) {
            printf("%c", cells[r][c]);
        }
        printf("\n");
    }
}

int main(int argc, char** argv) {
    int rows, cols;
    scanf("%d %d", &rows, &cols);
    int cells[rows][cols];
    char str[cols];
    for (int r = 0; r < rows; r++) {
        scanf("%s", str);
        for (int c = 0; c < cols; c++) {
            cells[r][c] = str[c];
        }
    }

    connect_neighbor(0, 0, rows, cols, cells, 0);
    print_layout(rows, cols, cells);

    return 0;
}
