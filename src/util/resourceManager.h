#ifndef _RESOURCE_MANAGER_H_
#define _RESOURCE_MANAGER_H_

#include <stdio.h>
#include <stdlib.h>

#define TEXT_BUFFER_SIZE 0x1<<12

char* readTextFile(const char* path);

#endif