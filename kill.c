#include "types.h"
#include "stat.h"
#include "user.h"

int main(int argc, char **argv)
{


  if (argc < 3)
  {
    printf(2, "usage: kill pid...\n");
    exit();
  }

  // for (i = 1; i < argc; i++)
  // kill(atoi(argv[i]));
  kill(atoi(argv[1]), atoi(argv[2])); // kill (pid, flag)

  exit();
}
