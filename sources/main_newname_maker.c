#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// 원활한 유지보수를 위해 상수 정의
#define NUM_NICKNAMES 3
#define MAX_NICKNAME_LENGTH 20
#define MAX_NAME_STYLE_LENGTH 50
#define MAX_NAME_DECO_LENGTH 20
#define MAX_NEW_NICKNAME_LENGTH 30
#define NUM_NAME_STYLE 3
#define NUM_NAME_DECO2 18

// 함수 원형 선언
char *NameMakerChar(char *nickname, char *name_deco);
char *NameMakerStr(char *nickname, char *name_deco, int rows);
void FreeMemory(char **new_nicknames);

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
        "%d자)\n\n"
        "=========================================================\n\n",
        MAX_NICKNAME_LENGTH);

    printf("자신의 닉네임: ");

    // 사용자에게 닉네임을 입력받음
    scanf_s("%20s", nickname, (int)sizeof(nickname));

    printf("\n입력된 닉네임: %s\n\n", nickname);
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
        new_nicknames[i] = NameMakerChar(nickname, name_deco1);
      } else if (choice == 2) {
        new_nicknames[i] = NameMakerStr(nickname, name_deco2, NUM_NAME_DECO2);
      } else if (choice == 3) {
        new_nicknames[i] = NameMakerChar(nickname, name_deco3);
      }
    }

    // 새로 만들어진 닉네임 3개를 순서대로 출력
    for (int i = 0; i < NUM_NICKNAMES; i++) {
      if (new_nicknames[i] != NULL) {
        printf("새 닉네임 %d: %s\n", i + 1, new_nicknames[i]);
      }
    }

    FreeMemory(new_nicknames);  // 할당된 메모리 해제

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

// 문자 요소로 새 닉네임을 만드는 함수
char *NameMakerChar(char *nickname, char *name_deco) {
  int name_len = strlen(nickname);
  int deco_len = strlen(name_deco);
  int position = rand() % name_len;
  int rand_deco = rand() % deco_len;
  int size = strlen(nickname) + 2;
  char *result = (char *)malloc(size);  // 동적 할당
  char new_nickname[MAX_NEW_NICKNAME_LENGTH];
  strcpy_s(new_nickname, MAX_NEW_NICKNAME_LENGTH, nickname);

  if (result == NULL) {
    return NULL;
  }

  // 문자열의 끝부터 시작하여 position까지 한칸씩 문자열 이동, 새 문자가 들어갈
  // 자리를 만들기 위함
  for (int i = name_len; i >= position; i--) {
    new_nickname[i + 1] = new_nickname[i];
  }

  // 랜덤한 자리에 랜덤한 문자를 삽입하고 result에 복사함
  new_nickname[position] = name_deco[rand_deco];
  strcpy_s(result, size, new_nickname);

  return result;
}

// 문자열 요소로 새 닉네임을 만드는 함수
char *NameMakerStr(char *nickname, char (*name_deco)[MAX_NAME_DECO_LENGTH],
                   int rows) {
  int rand_deco = rand() % rows;
  int size = strlen(nickname) + strlen(name_deco[rand_deco]) + 1;
  char *result = (char *)malloc(size);  // 동적 할당

  if (result == NULL) {
    return NULL;
  }

  // 랜덤한 문자열을 복사하고 사용자의 닉네임과 붙임
  strcpy_s(result, size, name_deco[rand_deco]);
  strcat_s(result, size, nickname);

  return result;
}

// 할당된 메모리를 해제하는 함수
void FreeMemory(char **new_nicknames) {
  for (int i = 0; i < NUM_NICKNAMES; i++) {
    free(new_nicknames[i]);
    new_nicknames[i] = NULL;
  }
}