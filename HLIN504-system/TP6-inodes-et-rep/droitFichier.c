#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

int main(int argc, char const *argv[])
{
	struct stat etat;
	int i = stat(argv[1], &etat);
	if (i == 0) {
		printf("le fichier a pour inode : %ld ", etat.st_ino);
    if (S_ISDIR(etat.st_mode)) printf("r"); else printf("-");
		if (etat.st_mode & S_IRUSR) printf("r"); else printf("-");
		if (etat.st_mode & S_IWUSR) printf("w"); else printf("-");
    if (etat.st_mode & S_IXUSR) printf("x"); else printf("-");
    if (etat.st_mode & S_IRGRP) printf("r"); else printf("-");
    if (etat.st_mode & S_IWGRP) printf("w"); else printf("-");
    if (etat.st_mode & S_IXGRP) printf("x"); else printf("-");
    if (etat.st_mode & S_IROTH) printf("r"); else printf("-");
    if (etat.st_mode & S_IWOTH) printf("w"); else printf("-");
    if (etat.st_mode & S_IXOTH) printf("x"); else printf("-");

    printf("\nFile Permissions: \t");
    printf( (S_ISDIR(etat.st_mode)) ? "d" : "-");
    printf( (etat.st_mode & S_IRUSR) ? "r" : "-");
    printf( (etat.st_mode & S_IWUSR) ? "w" : "-");
    printf( (etat.st_mode & S_IXUSR) ? "x" : "-");
    printf( (etat.st_mode & S_IRGRP) ? "r" : "-");
    printf( (etat.st_mode & S_IWGRP) ? "w" : "-");
    printf( (etat.st_mode & S_IXGRP) ? "x" : "-");
    printf( (etat.st_mode & S_IROTH) ? "r" : "-");
    printf( (etat.st_mode & S_IWOTH) ? "w" : "-");
    printf( (etat.st_mode & S_IXOTH) ? "x" : "-");
    printf("\n");
	}

  return 0;
}