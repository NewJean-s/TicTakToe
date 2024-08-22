#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void clearBoard(char board[3][3]) {
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      board[i][j] = ' ';
    }
  }
}

int isEndGame(char board[3][3]) {
  // 1: 1번 플레이어 승
  // 2: 2번 플레이어 승
  // 3: 비김
  // 0: 끝나지 않음

  int end = 0, cnt = 0;
  for (int i = 0; i < 3; i++) {
    if (board[i][0] == 'o' && board[i][1] == 'o' && board[i][2] == 'o') {
      end = 1;
    }

    if (board[i][0] == 'x' && board[i][1] == 'x' && board[i][2] == 'x') {
      end = 2;
    }
  }
  for (int j = 0; j < 3; j++) {
    if (board[0][j] == 'o' && board[1][j] == 'o' && board[2][j] == 'o') {
      end = 1;
    }
    if (board[0][j] == 'x' && board[1][j] == 'x' && board[2][j] == 'x') {
      end = 2;
    }
  }

  if (board[0][0] == 'o' && board[1][1] == 'o' && board[2][2] == 'o') {
    end = 1;
  }
  if (board[0][0] == 'x' && board[1][1] == 'x' && board[2][3] == 'x') {
    end = 2;
  }

  if (board[0][2] == 'o' && board[1][1] == 'o' && board[2][0] == 'o') {
     end = 1;
  }
  if (board[0][2] == 'x' && board[1][1] == 'x' && board[2][0] == 'x') {
     end = 2;
  }

  if (end == 1 || end == 2) {
    return end;
  }

  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; i++) {
      if (board[i][j] != ' ') {
        cnt++;
      }
    }
  }

  if (cnt == 9) {
    end = 3;
  }

  return end;
}

void displayBoard(char board[3][3]) {
  printf("\n╭-----------╮\n");
  printf("| %c | %c | %c |\n",board[0][0],board[0][1],board[0][2]);
  printf("|-----------|\n");
  printf("| %c | %c | %c |\n",board[1][0],board[1][1],board[1][2]);
  printf("|-----------|\n");
  printf("| %c | %c | %c |\n",board[2][0],board[2][1],board[2][2]);
  printf("╰-----------╯\n\n");
}

int main() {
  int player = 1, row, col;
  char board[3][3];
  clearBoard(board);
  displayBoard(board);

  while (isEndGame(board) == 0) {
    printf("플레이어 %d 순서입니다.\n", player);
    printf("행(0~2)과 열(0~2)을 순서대로 입력: ");
    scanf("%d%d", &row, &col);
    while (board[row][col] != ' ') {
      printf("다시 입력하세요. (이미 채워진 칸) \n");
      printf("행(0~2)과 열(0~2)을 순서대로 입력: ");
      scanf("%d%d", &row, &col);
    }
    if (player == 1) {
      board[row][col] = 'o';
      player = 2;
    }
    else {
      board[row][col] = 'x';
      player = 1;
    }
    displayBoard(board);
  }

  printf("플레이어 %d이/가 승리했노.",isEndGame(board));
}
