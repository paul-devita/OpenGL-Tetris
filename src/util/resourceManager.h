#ifndef _RESOURCE_MANAGER_H_
#define _RESOURCE_MANAGER_H_

#include <stdio.h>
#include <stdlib.h>

#include <stb_image.h>

#define TEXT_BUFFER_SIZE 0x1<<12

#define RM_TRUE 1
#define RM_FALSE 0

typedef struct {
	unsigned char* data;
	int width;
	int height;
	int nrChannels;
	unsigned char alpha;
} Image;

char* rm_readTextFile(const char* path);

void rm_freeTextFile(char* file);

Image rm_readImageFile(const char* path, const unsigned char alpha);

void rm_freeImageData(Image* image);

#endif