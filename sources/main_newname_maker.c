#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "nickname_maker.h"

int main(void) {
  srand(time(NULL));  // 난수 생성이 가능하게 함

  while (1) {
    printf(
        "=========================================================\n\n"
        "영문 닉네임 자동 추천 프로그램, '뉴네임메이커'가 실행되었습니다.\n"
        "사용하고자 하는 자신의 고유 영문 닉네임을 입력해주세요. (최대 "
        "%d자)\n\n"
        "=========================================================\n\n",
        MAX_NICKNAME_LENGTH);

    // 구조체 포인터룰 사용
    NICKNAME *nickname_maker = (NICKNAME *)malloc(sizeof(NICKNAME));

    if (nickname_maker == NULL) {
      return 1;
    }

    // 사용자에게 닉네임을 입력받음
    printf("자신의 닉네임: ");
    char temp[MAX_NICKNAME_LENGTH + 1];
    scanf_s("%20s", temp, (int)sizeof(temp));
    char ch = getchar();

    nickname_maker->user_nickname =
        (char *)malloc((strlen(temp) + 1) * sizeof(char));
    strcpy_s(nickname_maker->user_nickname, strlen(temp) + 1, temp);

    printf("\n입력된 닉네임: %s\n\n", nickname_maker->user_nickname);
    printf(
        "당신은 어떤 스타일의 닉네임을 선호하시나요?\n"
        "다음의 종류 중 원하는 것을 선택하세요.\n\n"
        "1. %s  2. %s  3. %s\n\n",
        name_style[0], name_style[1], name_style[2]);

    int choice;
    while (1) {
      printf("종류 선택 (1-3): ");

      // 사용자가 선호하는 스타일을 선택, 사용자가 1, 2, 3이 아닌 다른 것을
      // 입력할 시 예외 처리
      if (scanf_s("%d", &choice) != 1 || choice < 1 || choice > 3) {
        printf("\n잘못된 선택입니다. 1부터 3까지의 숫자를 선택해주세요.\n\n");
        while (getchar() != '\n')
          ;
      } else
        break;
    }

    printf("\n선택된 종류: %d. %s\n\n", choice, name_style[choice - 1]);

    // 사용자의 선택에 따라 각 함수를 실행
    for (int i = 0; i < NUM_NICKNAMES; i++) {
      if (choice == 1) {
        nickname_maker->new_nicknames[i] =
            NameMakerChar(nickname_maker->user_nickname, name_deco1);
      } else if (choice == 2) {
        nickname_maker->new_nicknames[i] = NameMakerStr(
            nickname_maker->user_nickname, name_deco2, NUM_NAME_DECO2);
      } else if (choice == 3) {
        nickname_maker->new_nicknames[i] =
            NameMakerChar(nickname_maker->user_nickname, name_deco3);
      }
    }

    // 새로 만들어진 닉네임 3개를 순서대로 출력
    for (int i = 0; i < NUM_NICKNAMES; i++) {
      if (nickname_maker->new_nicknames[i] != NULL) {
        printf("새 닉네임 %d: %s\n", i + 1, nickname_maker->new_nicknames[i]);
      }
    }

    // 할당된 메모리 해제
    FreeMemory(nickname_maker->new_nicknames);

    free(nickname_maker->user_nickname);
    nickname_maker->user_nickname = NULL;

    free(nickname_maker);
    nickname_maker = NULL;

    int end;  // 프로그램 종료를 위한 변수

    while (1) {
      printf(
          "\n새 닉네임이 마음에 들지 않는 경우 0을 입력하여 닉네임을 처음부터 "
          "다시 만들 수 "
          "있습니다.\n"
          "새 닉네임이 마음에 든다면 1을 입력하여 프로그램을 "
          "종료하세요.\n\n");
      printf("0 또는 1을 선택하세요: ");

      // 사용자가 프로그램을 종료할지 선택함, 사용자가 0, 1이 아닌 다른 것을
      // 입력할 시 예외 처리
      if (scanf_s("%d", &end) != 1 || (end != 0 && end != 1)) {
        printf("\n잘못된 선택입니다. 0 또는 1을 선택해주세요.\n");
        while (getchar() != '\n')
          ;
      } else
        break;
    }

    // 사용자가 0을 입력했다면 다시 전체 반복, 1을 입력했다면 프로그램 종료
    if (end == 0) {
      printf("\n");
      getchar();
      continue;
    } else if (end == 1)
      break;
  }

  return 0;
}