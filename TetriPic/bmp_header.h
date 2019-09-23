#define BMPHEADERS_H

#include <stdint.h>

#define BMP_SIGNATURE 0x4d42
#define BMP_INFO_HEADER_SIZE 40
#define BMP_BIT_COUNT 24
#define MAX_PIXEL_VALUE 255
#define OFFSET 54

#pragma pack(1)

typedef struct {
	uint16_t signature;	//declar "signature" pe 2 octeti, literele 'B' si 'M' in ASCII
	uint32_t file_size;	//declar "file_size" pe 4 octeti, dimensiunea intregului fisier
	uint32_t reserved;	//declar "reserved" pe 4 octeti
	uint32_t offset;	//declar "offset" pe 4 octeti,offsetul matricii de pixeli
} bmp_file_header_t;	//structura se va numi "bmp_file_header_t"


typedef struct {
	uint32_t header_size;	//declar "header_size" pe 4 octeti, dimensiunea Info Header-ului 40
	uint32_t width;		//declar "width" pe 4 octeti,  latimea matricii de pixeli(nr coloane)
	uint32_t height;	//declar "height" pe 4 octeti, inaltimea matricii de pixeli(nr de randuri)
	uint16_t planes;	//declar "planes" pe 2 octeti, setat la valorea fixa 1
	uint16_t bit_count;	//declar "bit_count" pe 2 octeti, nr de biti per pixel(24)
	uint32_t compression;	//declar "compression" pe 4 octeti, tipul de compresie
	uint32_t image_size;	//declar "image_size" pe 4 octeti, dimensiunea matricii de pixeli
	uint32_t x_pixels_per_meter;	//declar "x_pixels_per_meter" pe 4 octeti, rezolutia de miscare
	uint32_t y_pixels_per_meter;	//declar "y_pixels_per_meter" pe 4 octeti, rezolutia de miscare
	uint32_t colors_used;	//declar "colors_used", pe 4 octeti, nr de culori din paleta dde culori
	uint32_t colors_important;	//declar "colors_important", pe 4 octeti, nr de culori importante 
} bmp_info_header_t;	//structura se va numi "bmp_info_header_t"

#pragma pack()
