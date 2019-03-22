// std i o lib
#include <stdio.h>
// format dir entries, defines type DIR , represeting directory stream
#include <dirent.h>
// to get size of entries
#include <sys/stat.h>
// include stdlib for exit
#include <stdlib.h>

/**
 * Main
 */
// arg count, arg vector, pointer array which points to each arg passed to program, argv[0] name of program
int main(int argc, char **argv)
{
  // Parse command line

  // init pointer for struct type dir entry, holds name
  struct dirent *de;
  // init pointer for dir name
  char *dirname;

  // if num of args is greater than two, err out
  if (argc > 2)
  {
    printf("Too many argument supplied.\n");
    exit(1);
  }
  // if num of args is less than two,
  else if (argc < 2)
  {
    //assign dir name pointer to "."
    dirname = ".";
  }
  //if num of args is two,
  else if (argc == 2)
  {
    //assign dir pointer to arg vector at index 1
    dirname = argv[1];
    printf("The argument supplied is %s\n", dirname);
  }
  // Open directory
  DIR *dir = opendir(dirname);
  // if opendir returns null, could not open directory
  if (dir == NULL)
  {
    printf("Could not open current directory");
    exit(1);
  }

  // Repeatly read and print entries

  while ((de = readdir(dir)) != NULL)
  {
    printf("%s\n", de->d_name);
  }

  // Close directory
  closedir(dir);

  return 0;
}