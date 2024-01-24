#include <string.h>

bool isSubsequence(char *s, char *t) {
  if (!s[0]) {
    return true;
  }
  int sPtr = 0;
  int tPtr = 0;

  while (t[tPtr]) {
    if (t[tPtr] == s[sPtr]) {
      sPtr++;
      if (s[sPtr] == NULL) {
        return true;
      }
    }
    tPtr++;
  }
  return false;
}
