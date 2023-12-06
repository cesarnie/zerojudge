line1 = input()
str1, str2 = line1.split(" ")
mouse_pos, food_cnt = int(str1), int(str2)
line2 = input()
foods = []
food_pos_str = line2.split(" ")
for i in range(food_cnt):
    foods.append(int(food_pos_str[i]))

left_sum = 0
right_sum = 0
left_pos = mouse_pos
right_pos = mouse_pos
for i in foods:
    if i > mouse_pos:
        right_sum += 1
        if i > right_pos:
            right_pos = i
    else:
        left_sum += 1
        if i < left_pos:
            left_pos = i

if left_sum > right_sum:
    print(left_sum, left_pos)
else:
    print(right_sum, right_pos)
