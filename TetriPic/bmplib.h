
#define BMPLIB_H

#include "bmp_header.h"

#pragma pack(1)

typedef struct {	//canalele pentru fiecare pixel(Blue, Green, Red)
	uint8_t b;	//pe 1 octet
	uint8_t g;	//pe 1 octet
	uint8_t r;	//pe 1 octet
} pixel_t;	//structura se va numi "pixel_t"

typedef struct {
	int width, height;	//latimea si inaltimea imaginii
	pixel_t **pixels;	// matrice de pointeri pentru pixeli
} bitmap_t;	//structura se va numi "bitmap_t"

#pragma pack()

int initialize_bitmap(bitmap_t *p_bitmap, int w, int h);
int clear_bitmap(bitmap_t *p_bitmap);
int read_bmp(const char filename[], bmp_file_header_t *p_file_header,
			 bmp_info_header_t *p_info_header, bitmap_t *p_bitmap);
int write_bmp(const char filename[], const bmp_file_header_t *p_file_header,
			  const bmp_info_header_t *p_info_header, const bitmap_t *p_bitmap);

int rotate(bitmap_t *p_bitmap, int rotation, bitmap_t *p_temp);
