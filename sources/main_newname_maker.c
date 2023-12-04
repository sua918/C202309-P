#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void nameMaker1(char *nickname, char *name_deco, int position);
void nameMaker2(char *nickname, char *name_deco, int position);
void nameMaker3(char *nickname, char *name_deco, int position);
void nameMaker4(char *nickname, char *name_deco, int position);

int nameLen;

char nickname[20];
char name_style[4][50] = {"본래 닉네임과 비슷한 닉네임", "웃긴 닉네임",
                          "의미없는 닉네임", "특수문자로 꾸민 닉네임"};
char name_deco1[4] = {'.', ',', '_', '`'};
char name_deco2[18][20] = {
    "Hilarious", "Comical",   "Amusing",    "Witty",     "Laughable",
    "Silly",     "Goofy",     "Zany",       "Slapstick", "Sidesplitting",
    "Dumb",      "Foolish",   "Dopey",      "Dimwitted", "Brainless",
    "Dense",     "Pigheaded", "Blockheaded"};
char name_deco3[100] = {""};
char name_deco4[100] = {""};

int main(void) {
  printf(
      "=========================================================\n\n"
      "닉네임 자동 추천 프로그램, '뉴네임메이커'가 실행되었습니다.\n"
      "사용하고자 하는 자신의 고유 닉네임을 입력해주세요.\n\n"
      "=========================================================\n\n");

  printf("자신의 닉네임: ");
  scanf_s("%s", nickname, (int)sizeof(nickname));
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

  int name_len = strlen(nickname);

  srand(time(NULL));                // 난수 생성이 가능하게 함
  int position = rand() % name_len;  // 닉네임 글자 수에서 랜덤하게 정해짐
  int rand_deco = rand() % 4;  // 닉네임 꾸밈 요소의 개수에서 랜덤하게 정해짐

  if (choice == 1) {
    nameMaker1(nickname, name_deco1[rand_deco], position);
  } else if (choice == 2) {
    nameMaker2(nickname, name_deco2[rand_deco], position);
  } else if (choice == 3) {
    nameMaker3(nickname, name_deco3[rand_deco], position);
  } else if (choice == 4) {
    nameMaker4(nickname, name_deco4[rand_deco], position);
  }

  printf("%s\n", nickname);

  return 0;
}

// 한글로 하면 작동이 잘 안됨. 영어 닉네임으로 바꾸든가 고민을 더 해봐야겠다.
void nameMaker1(char *nickname, char *name_deco, int position) {
  int name_len = strlen(nickname);

  // 문자열의 끝부터 시작하여 position까지 문자열 이동
  for (int i = name_len; i >= position; i--) {
    nickname[i + 1] = nickname[i];
  }
  nickname[position] = name_deco;
}

void nameMaker2(char *nickname, char *name_deco, int position) {}

void nameMaker3(char *nickname, char *name_deco, int position) {
  int name_len = strlen(nickname);

  // 문자열의 끝부터 시작하여 position까지 문자열 이동
  for (int i = name_len; i >= position; i--) {
    nickname[i + 1] = nickname[i];
  }
  nickname[position] = name_deco;
}

void nameMaker4(char *nickname, char *name_deco, int position) {}