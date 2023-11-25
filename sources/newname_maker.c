#include <stdio.h>
#include <string.h>

void nameMaker(userName);

int main(void) {
  printf(
      "=========================================================\n\n"
      "닉네임 자동 추천 프로그램, '뉴네임메이커'가 실행되었습니다.\n"
      "사용하고자 하는 자신의 고유 닉네임을 입력해주세요.\n\n"
      "=========================================================\n\n");
  char nickname[20];
  char nameStyle[4][50] = {"본래 닉네임과 근접한 닉네임", "웃긴 닉네임",
                           "의미없는 닉네임", "특수문자로 꾸민 닉네임"};
  char nameDeco[10] = {'a', 'b', 'c', 'd', 'e',
                       'f', 'g', 'h', 'i', 'j'}; // 임시로 가정

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
  printf("\n선택된 종류: %d. %s\n\n", choice, nameStyle[choice-1]);

  int position = 5;
  nameMaker(nickname, nameDeco[0], position);

  printf("%s\n", nickname);
}

void nameMaker(char *nickname, char nameDeco, int position) { // 한글로 하면 작동이 잘 안됨. 고민을 더 해봐야겠다.
  // TO-DO: 숫자, 문자, 문자열이 들은 배열이 필요. 구조체 지식 필요할 듯.

  int nameLen = strlen(nickname);

  // 문자열의 끝부터 시작하여 position까지 문자열 이동
  for (int i = nameLen; i >= position; i--) {
    nickname[i + 1] = nickname[i];
  }
  nickname[position] = nameDeco;
}