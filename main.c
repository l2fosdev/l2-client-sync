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

int main(int argc, char *argv[])
{
	char c;
	char *folderPath = NULL;
	uint8_t version = 0;

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
	fprintf(stdout, "%s, %d", folderPath, version);
	return 0;
}
