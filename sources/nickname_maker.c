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

// ���� ��ҷ� �� �г����� ����� �Լ�
char *NameMakerChar(char *nickname, char *name_deco) {
  int name_len = strlen(nickname);
  int deco_len = strlen(name_deco);
  int position = rand() % name_len;
  int rand_deco = rand() % deco_len;
  int size = strlen(nickname) + 2;
  char *result = (char *)malloc(size);  // ���� �Ҵ�
  char new_nickname[MAX_NEW_NICKNAME_LENGTH];
  strcpy_s(new_nickname, MAX_NEW_NICKNAME_LENGTH, nickname);

  if (result == NULL) {
    return NULL;
  }

  // ���ڿ��� ������ �����Ͽ� position���� ��ĭ�� ���ڿ� �̵�, �� ���ڰ� ��
  // �ڸ��� ����� ����
  for (int i = name_len; i >= position; i--) {
    new_nickname[i + 1] = new_nickname[i];
  }

  // ������ �ڸ��� ������ ���ڸ� �����ϰ� result�� ������
  new_nickname[position] = name_deco[rand_deco];
  strcpy_s(result, size, new_nickname);

  return result;
}

// ���ڿ� ��ҷ� �� �г����� ����� �Լ�
char *NameMakerStr(char *nickname, char (*name_deco)[MAX_NAME_DECO_LENGTH],
                   int rows) {
  int rand_deco = rand() % rows;
  int size = strlen(nickname) + strlen(name_deco[rand_deco]) + 1;
  char *result = (char *)malloc(size);  // ���� �Ҵ�

  if (result == NULL) {
    return NULL;
  }

  // ������ ���ڿ��� �����ϰ� ������� �г��Ӱ� ����
  strcpy_s(result, size, name_deco[rand_deco]);
  strcat_s(result, size, nickname);

  return result;
}

// �Ҵ�� �޸𸮸� �����ϴ� �Լ�
void FreeMemory(char **new_nicknames) {
  for (int i = 0; i < NUM_NICKNAMES; i++) {
    free(new_nicknames[i]);
    new_nicknames[i] = NULL;
  }
}