#include <stdio.h>
#include <stdlib.h>

void Field(int myach_height, int myach_widht, int right_rocket_position, int left_rocket_position);
int playerOneMove(char move, int left_rocket_position);
int playerTwoMove(char move, int right_rocket_position);

int main() {
    int myach_height = 13, myach_widht = 41, right_rocket_position = 13, left_rocket_position = 13,
        start_right_rocket_position = 13, start_left_rocket_position = 13, player_one_score = 0,
        player_two_score = 0, myach_movement_x = 1, myach_movement_y = 1, start_myach_height = 13,
        start_myach_widht = 40;
    const int RIGHT_BORDER = 81, LEFT_BORDER = 0, UPPER_BORDER = 27, BOTTOM_BORDER = 0;
    while (player_one_score <= 21 || player_two_score <= 21) {
        system("clear");
        Field(myach_height, myach_widht, right_rocket_position, left_rocket_position);
        printf("                    Player 1  score : %d    Player 2 score: %d \n", player_one_score,
               player_two_score);

        if (player_one_score == 21) {
            printf("Player 1 win!");
            break;
            return 0;
        } else if (player_two_score == 21) {
            printf("Player 2 win!");
            break;
            return 0;
        }

        char move;
        scanf("%c", &move);
        // XXX: Магические числа = таблица ascii(A,Z,a,z)
        if (move == 65 || move == 90 || move == 97 || move == 122) {
            left_rocket_position = playerOneMove(move, left_rocket_position);
            if (myach_widht == LEFT_BORDER + 1 && (myach_height <= left_rocket_position + 1) &&
                (myach_height >= left_rocket_position - 1)) {
                myach_movement_x *= -1;
                myach_movement_y *= 1;
                myach_height += myach_movement_y;
                myach_widht += myach_movement_x;
            } else if (myach_widht == RIGHT_BORDER - 2 && (myach_height <= right_rocket_position + 1) &&
                       (myach_height >= right_rocket_position - 1)) {
                myach_movement_x *= -1;
                myach_movement_y *= 1;
                myach_height += myach_movement_y;
                myach_widht += myach_movement_x;
            } else if (myach_height == BOTTOM_BORDER + 1 || myach_height == UPPER_BORDER - 1) {
                myach_movement_x *= 1;
                myach_movement_y *= -1;
                myach_height += myach_movement_y;
                myach_widht += myach_movement_x;
            } else if (myach_widht == LEFT_BORDER + 2) {
                player_two_score++;
                myach_movement_x *= -1;
                myach_movement_y *= 1;
                myach_height = start_myach_height;
                myach_widht = start_myach_widht;
                left_rocket_position = start_left_rocket_position;
                right_rocket_position = start_right_rocket_position;
            } else if (myach_widht == RIGHT_BORDER - 1) {
                player_one_score++;
                myach_height = start_myach_height;
                myach_widht = start_myach_widht;
                left_rocket_position = start_left_rocket_position;
                right_rocket_position = start_right_rocket_position;
            } else {
                myach_height += myach_movement_y;
                myach_widht += myach_movement_x;
            }
        }
        // XXX: Магические числа = таблица ascii(K,M,k,m)
        else if (move == 75 || move == 77 || move == 107 || move == 109) {
            right_rocket_position = playerTwoMove(move, right_rocket_position);
            if (myach_widht == LEFT_BORDER + 2 && (myach_height <= left_rocket_position + 1) &&
                (myach_height >= left_rocket_position - 1)) {
                myach_movement_x *= -1;
                myach_movement_y *= 1;
                myach_height += myach_movement_y;
                myach_widht += myach_movement_x;
            } else if (myach_widht == RIGHT_BORDER - 2 && (myach_height <= right_rocket_position + 1) &&
                       (myach_height >= right_rocket_position - 1)) {
                myach_movement_x *= -1;
                myach_movement_y *= 1;
                myach_height += myach_movement_y;
                myach_widht += myach_movement_x;
            } else if ((myach_height == BOTTOM_BORDER + 1 || myach_height == UPPER_BORDER - 1)) {
                myach_movement_x *= 1;
                myach_movement_y *= -1;
                myach_height += myach_movement_y;
                myach_widht += myach_movement_x;
            } else if (myach_widht == LEFT_BORDER + 1) {
                player_two_score++;
                myach_movement_x *= -1;
                myach_movement_x *= -1;
                myach_height = start_myach_height;
                myach_widht = start_myach_widht;
                left_rocket_position = start_left_rocket_position;
                right_rocket_position = start_right_rocket_position;
            } else if (myach_widht == RIGHT_BORDER - 1) {
                player_one_score++;
                myach_movement_x *= -1;
                myach_movement_x *= 1;
                myach_height = start_myach_height;
                myach_widht = start_myach_widht;
                left_rocket_position = start_left_rocket_position;
                right_rocket_position = start_right_rocket_position;
            } else {
                myach_height += myach_movement_y;
                myach_widht += myach_movement_x;
            }
        }
        // XXX: Магические числа = таблица ascii(SpaceBar)
        else if (move == ' ') {
            if ((myach_height == BOTTOM_BORDER + 1 || myach_height == UPPER_BORDER - 1)) {
                myach_movement_x *= 1;
                myach_movement_y *= -1;
                myach_height += myach_movement_y;
                myach_widht += myach_movement_x;
            } else if (myach_widht == LEFT_BORDER + 2 && (myach_height <= left_rocket_position + 1) &&
                       (myach_height >= left_rocket_position - 1)) {
                myach_movement_x *= -1;
                myach_movement_y *= 1;
                myach_height += myach_movement_y;
                myach_widht += myach_movement_x;
            } else if (myach_widht == LEFT_BORDER + 1) {
                player_two_score++;
                myach_movement_x *= -1;
                myach_movement_x *= 1;
                myach_height = start_myach_height;
                myach_widht = start_myach_widht;
                left_rocket_position = start_left_rocket_position;
                right_rocket_position = start_right_rocket_position;
            } else if (myach_widht == RIGHT_BORDER - 2 && (myach_height <= right_rocket_position + 1) &&
                       (myach_height >= right_rocket_position - 1)) {
                myach_movement_x *= -1;
                myach_movement_y *= 1;
                myach_height += myach_movement_y;
                myach_widht += myach_movement_x;
            } else if (myach_widht == RIGHT_BORDER - 1) {
                player_one_score++;
                myach_movement_x *= -1;
                myach_movement_y *= -1;
                myach_height = start_myach_height;
                myach_widht = start_myach_widht;
                left_rocket_position = start_left_rocket_position;
                right_rocket_position = start_right_rocket_position;
            } else {
                myach_height += myach_movement_y;
                myach_widht += myach_movement_x;
            }
        } else if (move == 81) {
            break;
            return 0;
        } else {
            printf("Miss communication!\n");
        }
    }

    return 0;
}

int playerOneMove(char move, int left_rocket_position) {
    if (move == 65 || move == 97) {
        if (left_rocket_position < 25) {
            left_rocket_position++;
            return left_rocket_position;
        }
    } else if (move == 90 || move == 122) {
        if (left_rocket_position > 2) {
            left_rocket_position--;
            return left_rocket_position;
        }
    }
    return left_rocket_position;
}

int playerTwoMove(char move, int right_rocket_position) {
    if (move == 75 || move == 107) {
        if (right_rocket_position < 25) {
            right_rocket_position++;
            return right_rocket_position;
        }
    } else if (move == 77 || move == 109) {
        if (right_rocket_position > 2) {
            right_rocket_position--;
            return right_rocket_position;
        }
    }
    return right_rocket_position;
}

void Field(int myach_height, int myach_width, int right_rocket_position, int left_rocket_position) {
    const int RIGHT_BORDER = 81, LEFT_BORDER = 0, UPPER_BORDER = 27, BOTTOM_BORDER = 0;
    for (int height = UPPER_BORDER; height >= 0; height--) {
        for (int width = LEFT_BORDER; width <= RIGHT_BORDER; width++) {
            if (height == UPPER_BORDER || height == BOTTOM_BORDER || width == LEFT_BORDER ||
                width == RIGHT_BORDER) {
                printf("$");
                if (width == RIGHT_BORDER) {
                    printf("\n");
                }
            } else if (((height == right_rocket_position || height == right_rocket_position - 1 ||
                         height == right_rocket_position + 1) &&
                        (width == RIGHT_BORDER - 1)) ||
                       ((height == left_rocket_position || height == left_rocket_position - 1 ||
                         height == left_rocket_position + 1) &&
                        (width == LEFT_BORDER + 1))) {
                printf("|");
            } else if (myach_height == height && myach_width == width) {
                printf("@");
            } else {
                printf(" ");
            }
        }
    }
}
