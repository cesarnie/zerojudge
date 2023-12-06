// https://zerojudge.tw/ShowProblem?problemid=m370

#include <stdio.h>

int main(int argc, char** argv) {
    int mouse_pos;
    int food_cnt;
    scanf("%d %d", &mouse_pos, &food_cnt);
    int n;
    int ret;
    int left_sum = 0;
    int right_sum = 0;
    int left_pos = mouse_pos;
    int right_pos = mouse_pos;

    for (int i = 0; i < food_cnt; ++i) {
        if ((ret = scanf("%d", &n)) == 0) {
            break;
        }
        if (n < mouse_pos) {
            left_sum += 1;
            if (n < left_pos) {
                left_pos = n;
            }
        }
        else {
            right_sum += 1;
            if (n > right_pos) {
                right_pos = n;
            }
        }
    }

    if (left_sum > right_sum) {
        printf("%d %d\n", left_sum, left_pos);
    }
    else {
        printf("%d %d\n", right_sum, right_pos);
    }

    return 0;
}