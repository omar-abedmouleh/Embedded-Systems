#include <stdio.h>

unsigned char required_password[6] = {'o', 'm', 'a', 'r', '2', '7'};
unsigned char given_password[7];

int main(void) {
  unsigned char tries_counter = 0;

  while (tries_counter < 3) {
    printf("please enter password\n");
    scanf("%6s", given_password);

    unsigned char password_pass = 1;

    for (int i = 0; i < 6; i++) {
      if (required_password[i] != given_password[i]) {
        password_pass = 0;
        break;
      }
    }

    if (password_pass == 1) {
      printf("given password is right\n");
      break;
    } else {
      tries_counter++;
      printf("given password was wrong\n");
      printf("tries remain: %i\n", 3 - tries_counter);
    }
  }

  return 0;
}