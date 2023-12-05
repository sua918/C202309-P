#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

char* nameMaker1(char *nickname, char *name_deco);
char *nameMaker2(char *nickname, char (*name_deco)[20], int rows);
void nameMaker3(char *nickname, char *name_deco, int position);
void nameMaker4(char *nickname, char *name_deco, int position);

int nameLen;

char nickname[21];
char name_style[4][50] = {"본래 닉네임과 비슷한 닉네임", "웃긴 닉네임",
                          "의미없는 닉네임", "특수문자로 꾸민 닉네임"};
char name_deco1[4] = {'.', ',', '_', '`'};
char name_deco2[18][20] = {"Hilarious", "Comical",       "Amusing",   "Witty",
                           "Laughable", "Silly",         "Goofy",     "Zany",
                           "Slapstick", "Sidesplitting", "Dumb",      "Foolish",
                           "Dopey",     "Dimwitted",     "Brainless", "Dense",
                           "Pigheaded", "Blockheaded"};
char name_deco3[100] = {""};
char name_deco4[100] = {""};

int main(void) {
  printf(
      "=========================================================\n\n"
      "닉네임 자동 추천 프로그램, '뉴네임메이커'가 실행되었습니다.\n"
      "사용하고자 하는 자신의 고유 닉네임을 입력해주세요.\n\n"
      "=========================================================\n\n");

  printf("자신의 닉네임: ");
  scanf_s("%20s", nickname, (int)sizeof(nickname));
  printf("\n입력된 닉네임: %s\n\n", nickname);
  printf(
      "당신은 어떤 스타일의 닉네임을 선호하시나요?\n"
      "다음의 종류 중 원하는 것을 선택하세요.\n\n"
      "1. %s  2. %s  3. %s  4. "
      "%s\n\n",
      name_style[0], name_style[1], name_style[2], name_style[3]);

  int choice;

  printf("종류 선택 (1-4): ");
  scanf_s("%d", &choice);
  printf("\n선택된 종류: %d. %s\n\n", choice, name_style[choice - 1]);

  srand(time(NULL));                 // 난수 생성이 가능하게 함

  if (choice == 1) {
    char *new_nickname = nameMaker1(nickname, name_deco1);
    printf("%s\n", new_nickname);
  } else if (choice == 2) {
    char *new_nickname = nameMaker2(nickname, name_deco2, 18);
    if (new_nickname != NULL) {
      printf("%s\n", new_nickname);
      free(new_nickname);
    }
  } else if (choice == 3) {
    //nameMaker3(nickname, name_deco3[rand_deco], position);
  } else if (choice == 4) {
    //nameMaker4(nickname, name_deco4[rand_deco], position);
  }

  return 0;
}

// 한글로 하면 작동이 잘 안됨. 영어 닉네임으로 바꾸든가 고민을 더 해봐야겠다.
char* nameMaker1(char *nickname, char *name_deco) {
  int name_len = strlen(nickname);
  int deco_len = strlen(name_deco);
  int position = rand() % name_len;
  int rand_deco = rand() % deco_len;

  // 문자열의 끝부터 시작하여 position까지 문자열 이동
  for (int i = name_len; i >= position; i--) {
    nickname[i + 1] = nickname[i];
  }
  nickname[position] = name_deco[rand_deco];

  return nickname;
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

void nameMaker3(char *nickname, char *name_deco, int position) {
  int name_len = strlen(nickname);

  // 문자열의 끝부터 시작하여 position까지 문자열 이동
  for (int i = name_len; i >= position; i--) {
    nickname[i + 1] = nickname[i];
  }
  nickname[position] = name_deco;
}

void nameMaker4(char *nickname, char *name_deco, int position) {}