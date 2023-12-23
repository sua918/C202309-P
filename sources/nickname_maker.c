#include <stdio.h>
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