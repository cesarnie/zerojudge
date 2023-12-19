// https://zerojudge.tw/ShowProblem?problemid=m372

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int group_id = 0;
int group_cnt = 0;

int ROWS;
int COLS;
int* CELLS; // col*COLS+row
int* MMAP;  // col*COLS+row, to mark path
#define CELL(c, r) (*(CELLS + ((r) * COLS + (c))))
#define MCELL(c, r) (*(MMAP + ((r) * COLS + (c))))
// 如果能連到右邊，回傳1，否則回傳0
int do_right(char left, char right) {
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
int do_bottom(char top, char bottom) {
    if (strchr("XI7F", top) != NULL) {
        if (strchr("XILJ", bottom) != NULL) {
            return 1;
        }
    }
    return 0;
}

// 給定一個起始點，找出鄰居是否可通
// int do_neighbor(int r, int c, int rows, int cols, int cells[rows][cols]) {
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
int do_neighbor(int c, int r) {
    MCELL(c, r) = 1;
    int neighbor_cnt = 0;
    int connect_cnt = 0;
    int sum = 1;
    // 上
    if ((r - 1) >= 0 && MCELL(c, r - 1) != 1) {
        if (do_bottom(CELL(c, r - 1), CELL(c, r))) {
            // CELL(c, r - 1) = '0';
            sum += do_neighbor(c, r - 1);
        }
    }
    // 下
    if ((r + 1) < ROWS && MCELL(c, r + 1) != 1) {
        if (do_bottom(CELL(c, r), CELL(c, r + 1))) {
            // CELL(c, r + 1) = '0';
            sum += do_neighbor(c, r + 1);
        }
    }
    // 左
    if ((c - 1) >= 0 && MCELL(c - 1, r) != 1) {
        if (do_right(CELL(c - 1, r), CELL(c, r))) {
            // CELL(c - 1, r) = '0';
            sum += do_neighbor(c - 1, r);
        }
    }
    // 右
    if ((c + 1) < COLS && MCELL(c + 1, r) != 1) {
        if (do_right(CELL(c, r), CELL(c + 1, r))) {
            // CELL(c + 1, r) = '0';
            sum += do_neighbor(c + 1, r);
        }
    }
    // CELL(c, r) = '0';

    // printf("cn %d, %d, sum=%d\n", c, r, sum);
    return sum;
}

void print_layout() {
    for (int r = 0; r < ROWS; r++) {
        for (int c = 0; c < COLS; c++) {
            printf("%c", CELL(c, r));
        }
        printf("\n");
    }
}

int main(int argc, char** argv) {
    scanf("%d %d", &ROWS, &COLS);
    CELLS = (int*)malloc(sizeof(int) * COLS * ROWS);
    MMAP = (int*)malloc(sizeof(int) * COLS * ROWS);
    memset(MMAP, 0, sizeof(int) * COLS * ROWS);
    char str[500 + 1];
    for (int r = 0; r < ROWS; r++) {
        scanf("%s", str);
        for (int c = 0; c < COLS; c++) {
            CELL(c, r) = str[c];
        }
    }

    int max = 0;
    for (int c = 0; c < COLS; c++) {
        for (int r = 0; r < ROWS; r++) {
            if (MCELL(c, r) == 0 && CELL(c, r) != '0') {
                // printf("-----------(%d,%d) %d\n", c, r, do_neighbor(c, r));
                int sum = do_neighbor(c, r);
                if (sum > max) {
                    max = sum;
                }
            }
        }
    }
    printf("%d\n", max);

    // print_layout();

    free(CELLS);
    free(MMAP);
    return 0;
}
