﻿#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define NUM_NICKNAMES 3
#define MAX_NICKNAME_LENGTH 20
#define MAX_NAME_STYLE_LENGTH 50
#define MAX_NAME_DECO_LENGTH 20
#define MAX_NEW_NICKNAME_LENGTH 30
#define NUM_NAME_STYLE 3
#define NUM_NAME_DECO2 18

char *nameMaker1(char *nickname, char *name_deco);
char *nameMaker2(char *nickname, char (*name_deco)[20], int rows);
char *nameMaker3(char *nickname, char *name_deco);

char *new_nicknames[NUM_NICKNAMES];

char nickname[MAX_NICKNAME_LENGTH + 1];
char name_style[NUM_NAME_STYLE][MAX_NAME_STYLE_LENGTH] = {
    "본래 닉네임과 비슷한 닉네임", "웃긴 닉네임", "의미없는 닉네임"};
char name_deco1[] = {'.', ',', '_', '`'};
char name_deco2[NUM_NAME_DECO2 + 1][MAX_NAME_DECO_LENGTH] = {
    "Hilarious_", "Comical_",   "Amusing_",    "Witty_",     "Laughable_",
    "Silly_",     "Goofy_",     "Zany_",       "Slapstick_", "Sidesplitting_",
    "Dumb_",      "Foolish_",   "Dopey_",      "Dimwitted_", "Brainless_",
    "Dense_",     "Pigheaded_", "Blockheaded_"};
char name_deco3[] = {'1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B',
                     'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M',
                     'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X',
                     'Y', 'Z', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i',
                     'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't',
                     'u', 'v', 'w', 'x', 'y', 'z'};

int main(void) {
  srand(time(NULL));  // 난수 생성이 가능하게 함

  while (1) {
    printf(
        "=========================================================\n\n"
        "영문 닉네임 자동 추천 프로그램, '뉴네임메이커'가 실행되었습니다.\n"
        "사용하고자 하는 자신의 고유 영문 닉네임을 입력해주세요. (최대 "
        "20자)\n\n"
        "=========================================================\n\n");

    printf("자신의 닉네임: ");
    scanf_s("%20s", nickname, (int)sizeof(nickname));

    printf("\n입력된 닉네임: %s\n\n", nickname);
    printf(
        "당신은 어떤 스타일의 닉네임을 선호하시나요?\n"
        "다음의 종류 중 원하는 것을 선택하세요.\n\n"
        "1. %s  2. %s  3. %s\n\n",
        name_style[0], name_style[1], name_style[2]);

    int choice;
    printf("종류 선택 (1-3): ");
    scanf_s("%d", &choice);
    int ch = getchar();

    printf("\n선택된 종류: %d. %s\n\n", choice, name_style[choice - 1]);

    for (int i = 0; i < NUM_NICKNAMES; i++) {
      if (choice == 1) {
        new_nicknames[i] = nameMaker1(nickname, name_deco1);
      } else if (choice == 2) {
        new_nicknames[i] = nameMaker2(nickname, name_deco2, 18);
      } else if (choice == 3) {
        new_nicknames[i] = nameMaker3(nickname, name_deco3);
      }
    }

    for (int i = 0; i < NUM_NICKNAMES; i++) {
      if (new_nicknames[i] != NULL) {
        printf("새 닉네임 %d: %s\n", i + 1, new_nicknames[i]);
      }
    }
    for (int i = 0; i < NUM_NICKNAMES; i++) {  // 동적 할당 된 메모리 해제
      free(new_nicknames[i]);
    }

    int end;
    printf(
        "\n\n마음에 들지 않는 경우 1을 입력하여 닉네임을 처음부터 다시 만들 수 "
        "있습니다.\n"
        "새 닉네임이 마음에 든다면 0을 입력하여 프로그램을 "
        "종료하세요...\n\n");
    scanf_s("%d", &end);

    if (end == 1) {
      printf("\n\n");
      ch = getchar();
      continue;
    } else if (end == 0)
      break;
  }
  return 0;
}

char *nameMaker1(char *nickname, char *name_deco) {
  int name_len = strlen(nickname);
  int deco_len = strlen(name_deco);
  int position = rand() % name_len;
  int rand_deco = rand() % deco_len;
  int size = strlen(nickname) + 2;
  char *result = (char *)malloc(size);
  char new_nickname[MAX_NEW_NICKNAME_LENGTH];
  strcpy_s(new_nickname, MAX_NEW_NICKNAME_LENGTH, nickname);

  if (result == NULL) {
    return NULL;
  }

  // 문자열의 끝부터 시작하여 position까지 문자열 이동
  for (int i = name_len; i >= position; i--) {
    new_nickname[i + 1] = new_nickname[i];
  }
  new_nickname[position] = name_deco[rand_deco];
  strcpy_s(result, size, new_nickname);

  return result;
}

char *nameMaker2(char *nickname, char (*name_deco)[20], int rows) {
  int rand_deco = rand() % rows;
  int size = strlen(nickname) + strlen(name_deco[rand_deco]) + 1;
  char *result = (char *)malloc(size);

  if (result == NULL) {
    return NULL;
  }

  strcpy_s(result, size, name_deco[rand_deco]);
  strcat_s(result, size, nickname);

  return result;
}

char *nameMaker3(char *nickname, char *name_deco) {
  int name_len = strlen(nickname);
  int deco_len = strlen(name_deco);
  int position = rand() % name_len;
  int rand_deco = rand() % deco_len;
  int size = strlen(nickname) + 2;
  char *result = (char *)malloc(size);
  char new_nickname[30];
  strcpy_s(new_nickname, 30, nickname);

  if (result == NULL) {
    return NULL;
  }

  // 문자열의 끝부터 시작하여 position까지 문자열 이동
  for (int i = name_len; i >= position; i--) {
    new_nickname[i + 1] = new_nickname[i];
  }
  new_nickname[position] = name_deco[rand_deco];
  strcpy_s(result, size, new_nickname);

  return result;
}