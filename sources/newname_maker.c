#include <stdio.h>

int nameMaker(userName);

int main(void) {
  printf(
      "=========================================================\n\n"
      "닉네임 자동 추천 프로그램, '뉴네임메이커'가 실행되었습니다.\n"
      "사용하고자 하는 자신의 고유 닉네임을 입력해주세요.\n\n"
      "=========================================================\n\n");
  char nickname[20];
  char nameStyle[4][50] = {"본래 닉네임과 근접한 닉네임", "웃긴 닉네임",
                           "의미없는 닉네임", "특수문자로 꾸민 닉네임"};
  printf("자신의 닉네임: ");
  scanf_s("%s", nickname, sizeof(nickname));
  printf("\n입력된 닉네임: %s\n\n", nickname);
  printf(
      "당신은 어떤 스타일의 닉네임을 선호하시나요?\n"
      "다음의 종류 중 원하는 것을 선택하세요.\n\n"
      "1. %s  2. %s  3. %s  4. "
      "%s\n\n",
      nameStyle[0], nameStyle[1], nameStyle[2], nameStyle[3]);
  int choice;
  printf("종류 선택 (1-4): ");
  scanf_s("%d", &choice);
  printf("\n선택된 종류: %d. %s", choice, nameStyle[choice-1]);




}

int nameMaker(userName) { 
    // TO-DO: 구조체 배우고 나서 만들 것
}