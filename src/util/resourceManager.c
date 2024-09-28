#include "resourceManager.h"

char* rm_readTextFile(const char* path) {
	FILE* file_ptr;
	char buffer[TEXT_BUFFER_SIZE];
	char* dest = NULL;

	file_ptr = fopen(path, "r");

	if (!file_ptr) {
		printf("ERROR: failed to read file \"%s\"\n", path);
		return NULL;
	}

	if (fgets(buffer, TEXT_BUFFER_SIZE, file_ptr) != NULL) {
		int len = 0;

		for (int i = 0; buffer[i] != '\0'; i++)
			len++;

		dest = (char *)malloc(len * sizeof(char));

		if (dest == NULL) {
			printf("ERROR: unable to allocate memory\n");
			return NULL;
		}

		for (int i = 0; i < len; i++)
			dest[i] = buffer[i];

		while (fgets(buffer, TEXT_BUFFER_SIZE, file_ptr) != NULL) {
			int prev_len = len;
			int curlen = 0;

			for (int i = 0; buffer[i] != '\0'; i++)
				curlen++;

			len += curlen;

			char* old_block = dest;
			dest = (char*)realloc(dest, len * sizeof(char));

			if (!dest) {
				printf("ERROR: unable to allocate memory\n");
				free(old_block);
				return NULL;
			}

			for (int i = 0; i < curlen; i++)
				dest[i + prev_len] = buffer[i];
		}

		char* old_block = dest;
		dest = (char*)realloc(dest, (len + 1) * sizeof(char));

		if (!dest) {
			printf("ERROR: unable to allocate memory\n");
			free(old_block);
			return NULL;
		}

		dest[len] = '\0';
	}

	fclose(file_ptr);
	return dest;
}

void rm_freeTextFile(char* file) {
	free(file);
}

Image rm_readImageFile(const char* path, const unsigned char alpha) {
	Image result;

	int* width = &result.width;
	int* height = &result.height;
	int* nrChannels = &result.nrChannels;

	unsigned char* data = stbi_load(path, width, height, nrChannels, 0);

	if (!data) {
		fprintf(stderr, "ERROR: unable to read image data\n");
		return result;
	}

	result.data = data;
	result.alpha = alpha;

	return result;
}

void rm_freeImageData(Image* image) {
	unsigned char* data = image->data;

	stbi_image_free(data);
}