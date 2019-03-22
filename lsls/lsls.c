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
  // init struct type stat, call to statbuf
  struct stat statbuf;
  // if num of args is greater than two, err out
  if (argc > 2)
  {
    printf("Too many argument supplied.\n");
    exit(1);
  }
  // if num of args is less than two, ie 1 arg
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

  // assign pointer for DIR type opendir function opens directory stream to dirname
  DIR *dir = opendir(dirname);
  // if opendir returns null, could not open directory
  if (dir == NULL)
  {
    printf("Could not open current directory");
    exit(1);
  }
  //

  // Repeatly read and print entries

  // loop until the de pointer or struct directory entry is pointing to the readdir function passed in  dir stream to dirname is not NULL
  while ((de = readdir(dir)) != NULL)
  {
    // printf("%s\n", de->d_name);
    // syntax for function call pass in file name, and the stat struct
    stat(de->d_name, &statbuf);
    // print
    printf("%ld\t%s\n", statbuf.st_size, de->d_name);
  }
  // Close directory
  closedir(dir);
  return 0;
}