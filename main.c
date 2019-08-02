/*
 * main.c
 *
 *  Created on: 21 de jul de 2019
 *      Author: Rogers
 */

#include <unistd.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <dirent.h>
#include <limits.h>
#include <string.h>

int main(int argc, char *argv[])
{
	char c;
	char *folderPath = NULL;
	uint8_t version = 0;
	char cwd[PATH_MAX];

	struct dirent *dp;
	DIR *dfd;

	if (getcwd(cwd, sizeof(cwd)) != NULL) {
	   printf("Current working dir: %s\n", cwd);
   } else {
	   perror("getcwd() error");
	   return EXIT_FAILURE;
   }

	while ((c = getopt (argc, argv, "d:v:")) != -1){
		switch (c)
		      {
		      case 'd':
		    	  folderPath = optarg;
		        break;
		      case 'v':
		    	  version = strtol(optarg, NULL, 0);
				break;
		      case '?':
		          fprintf (stderr, "Unknown option `-%c'.\n", optopt);
		        return EXIT_FAILURE;
		      default:
		    	  return EXIT_FAILURE;
		      }
	}
	fprintf(stdout, "%s, %d\n", folderPath, version);

	if ((dfd = opendir(folderPath)) == NULL)
	{
		fprintf(stderr, "dirwalk: can't open %s\n", folderPath);
		return EXIT_FAILURE;
	}

	while ((dp = readdir(dfd)) != NULL)
	{
		if ((strcmp(dp->d_name, ".") == 0) || strcmp(dp->d_name, "..") == 0)
		{
			continue;
		}
		fprintf(stdout, "%s", dp->d_name);
	}
	closedir(dfd);

	return 0;
}
