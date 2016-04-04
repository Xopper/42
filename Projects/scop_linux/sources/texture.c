#include "scop.h"

static int			load_bmp(t_texture *texture, const char *filename)
{
	unsigned char	header[54];
	unsigned int	imageSize;

	FILE *file = fopen(filename, "rb");
	if (!file || fread(header, 1, 54, file) != 54 || header[0] != 'B' || header[1] != 'M')
		return (0);
	imageSize = *(int*)&(header[0x22]);
	texture->width = *(int*)&(header[0x12]);
	texture->height = *(int*)&(header[0x16]);
	if (imageSize == 0)
		imageSize = texture->width * texture->height * 3;
	texture->data = (unsigned char*)malloc(sizeof(unsigned char) * (imageSize + 1));
	texture->data[imageSize] = '\0';
	fread(texture->data, 1, imageSize, file);
	fclose(file);
	return (1);
}

t_texture			*create_texture(char const *filename)
{
	t_texture		*texture;

	texture = (t_texture*)malloc(sizeof(t_texture));
	texture->data = NULL;
	if (!texture)
		return (NULL);
	if (!load_bmp(texture, filename))
	{
		destroy_texture(texture);
		return (NULL);
	}

	glGenTextures(1, &texture->texture);
	glBindTexture(GL_TEXTURE_2D, texture->texture);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);

	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, texture->width, texture->height, 0, GL_BGR, GL_UNSIGNED_BYTE, texture->data);
	return (texture);
}

void				destroy_texture(t_texture *texture)
{
	if (texture)
	{
		glDeleteTextures(1, &texture->texture);
		if (texture->data)
			free(texture->data);
		free(texture);
	}
}
