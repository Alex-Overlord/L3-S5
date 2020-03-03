#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <dirent.h>
#include <assert.h>

int main(int argc, char const *argv[])
{
  char* name = malloc(sizeof(argv[1]));
  if (argc < 2) {
    printf("Enter a directory name: ");
    scanf("%s", name);
  }
  
  strcpy(name, argv[1]);
	struct stat etat;
  DIR* rep = opendir(name);
  if (rep == NULL) {
    puts("Error during opening directory.");
    exit(1);
  } else { 
    puts("Directory succefuly opened.");
  }
  struct dirent* file;

  while ((file = readdir(rep)) != NULL) {
	  int i = lstat(file->d_name, &etat);
    if (i == 0) {
      printf("%ld ", etat.st_ino);
      printf("%s ", file->d_name);
      if (S_ISREG(etat.st_mode)) printf("- ");
      if (S_ISDIR(etat.st_mode)) printf("d ");
      if (S_ISLNK(etat.st_mode)) printf("l ");

      printf( (S_ISDIR(etat.st_mode)) ? "d" : "-");
      printf( (etat.st_mode & S_IRUSR) ? "r" : "-");
      printf( (etat.st_mode & S_IWUSR) ? "w" : "-");
      printf( (etat.st_mode & S_IXUSR) ? "x" : "-");
      printf( (etat.st_mode & S_IRGRP) ? "r" : "-");
      printf( (etat.st_mode & S_IWGRP) ? "w" : "-");
      printf( (etat.st_mode & S_IXGRP) ? "x" : "-");
      printf( (etat.st_mode & S_IROTH) ? "r" : "-");
      printf( (etat.st_mode & S_IWOTH) ? "w" : "-");
      printf( (etat.st_mode & S_IXOTH) ? "x " : "- ");

      printf("%s\n", name);
    }
  }
    
  if (closedir(rep) == -1) {
    exit(-1);
  }
  puts("Le dossier a été fermé avec succès");

  free(name);
  return 0;
}

// DIR* rep = opendir(".");
// if (rep != NULL) {
//   struct dirent* ent;
//   while ((ent = readdir (rep)) != NULL) {
//     printf("%s\n", ent->d_name);
//   }
// }