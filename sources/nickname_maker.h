#define NUM_NICKNAMES 3
#define MAX_NICKNAME_LENGTH 20
#define MAX_NAME_STYLE_LENGTH 50
#define MAX_NAME_DECO_LENGTH 20
#define MAX_NEW_NICKNAME_LENGTH 30
#define NUM_NAME_STYLE 3
#define NUM_NAME_DECO2 18

typedef struct NicknameMaker {
  char *user_nickname;
  char *new_nicknames[NUM_NICKNAMES];
} NICKNAME;

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

char *NameMakerChar(char *nickname, char *name_deco);

char *NameMakerStr(char *nickname, char (*name_deco)[MAX_NAME_DECO_LENGTH],
                   int rows);

void FreeMemory(char **new_nicknames);