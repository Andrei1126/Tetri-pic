#include <stdio.h>
#include <stdlib.h>

#include "bmplib.h"

int initialize_bitmap(bitmap_t *p_bitmap, int w, int h) 
{
	p_bitmap->width = w;	//latimea piesei
	p_bitmap->height = h;	//inaltimea	piesei

	p_bitmap->pixels = malloc(h * sizeof(pixel_t *));	//aloc
	if (p_bitmap->pixels == NULL) {	//verific daca nu s-a reusit alocarea
		fprintf(stderr, "ERR\n");
		return 1;
	}
	for (int i = 0; i < h; ++i) {	//parcurg randurile matricii de pixeli
		p_bitmap->pixels[i] = malloc(w * sizeof(pixel_t));	//aloc
		if (p_bitmap->pixels[i] == NULL) {	//verific daca nu s-a reusit alocarea
			fprintf(stderr, "ERR\n");
			for (int j = 0; j < i; ++j) 
				free(p_bitmap->pixels[j]);	//eliberez memoria daca nu s-a reusit alocarea
			free(p_bitmap->pixels);
			return 1;
		}
	} 
	return 0;
}

int clear_bitmap(bitmap_t *p_bitmap)
{
	if (p_bitmap == NULL) 
	{
		return 0;	//daca nu s-a reusit alocarea intoarce 0
	}
	if (p_bitmap->pixels == NULL)
	{
		return 0;	//daca nu s-a reusit alocarea intoarce 0
	}
	for (int i = 0; i < p_bitmap->height; ++i)
	{
		free(p_bitmap->pixels[i]);	//eliberez memoria
	}
	free(p_bitmap->pixels);
	p_bitmap->pixels = NULL;	//transform pointer-ul intr-o zona 
	return 0;					//de memorie care nu e folosita
}

int read_bmp(const char filename[], bmp_file_header_t *p_file_header,
			 bmp_info_header_t *p_info_header, bitmap_t *p_bitmap) 
{
	FILE *p_file;
	int w, h, padding, e;

	p_file = fopen(filename, "rb");	//deschid fisierul pentru citire in modul binar
	if (p_file == NULL) {	//verific daca nu pot sa-l deschid
		fprintf(stderr, "Can't open file %s\n", filename);
		return 1;
	}

	//citesc o inregistrare din p_file
	e = fread(p_file_header, sizeof(bmp_file_header_t), 1, p_file);	
	if (e != 1) {	//verific daca nu s-a reusit citirea
		fprintf(stderr, "Error while reading the File Header\n");
		fclose(p_file);	//apoi inchid fisierul
		return 1;
	}
	if (p_file_header->signature != BMP_SIGNATURE) {	//daca nu au aceeasi adresa
		fprintf(stderr, "Invalid BMP signature: %X\n", p_file_header->signature);
		fclose(p_file);	//inchid fisierul
		return 1;
	}

	//citesc o inregistrare din p_file
	e = fread(p_info_header, sizeof(bmp_info_header_t), 1, p_file);	
	if (e != 1) {	//verific daca nu s-a reusit citirea
		fprintf(stderr, "Error while reading the Info Header\n");
		fclose(p_file);	//inchid fisierul
		return 1;
	}
	w = p_info_header->width;	//w reprezinta latimea matricii de pixeli
	h = p_info_header->height;	//h reprezinta inaltimea matricii de pixeli
	padding = (w * sizeof(pixel_t)) - (w * sizeof(pixel_t) / 4) * 4;	//realizez umplerea
	e = initialize_bitmap(p_bitmap, w, h);	//aloc spatiu
	if (e != 0) {	//verific daca nu s-a putut aloca
		fprintf(stderr, "Error while initializing the bitmap\n");
		fclose(p_file);	//inchid fisierul
		return 1;
	}
	e = fseek(p_file, p_file_header->offset, SEEK_SET);	//repozitionez p_file,
	if (e != 0) {						// SEEK_SET = cautarea se face de la inceputul fisierului	
		//verific daca nu s-a reusit sa repozitionez
		fprintf(stderr, "Error while movint cursor to %d\n", 
				p_file_header->offset);
		fclose(p_file);	//inchid fisierul
		return 1;
	}
	for (int i = h - 1; i >= 0; --i) {	//parcurg liniile
		//citesc w inregistrari din p_file
		e = fread(p_bitmap->pixels[i], sizeof(pixel_t), w, p_file);	
		if (e != w) {	//verific daca nu am reusit sa citesc w inregistrari
			fprintf(stderr, "Error while reading line %d\n", i);
			fclose(p_file);	//inchid fisierul
			return 1;
		}
		e = fseek(p_file, padding, SEEK_CUR);	//repozitionez pointerul 
		if (e != 0) {					//asociat lui p_file
			//verific daca nu s-a reusit repozitionarea
			fprintf(stderr, "Error while moving cursor with %d\n", padding);
			fclose(p_file);	//inchid fisierul
			return 1;
		}
	}
	fclose(p_file);	//inchid fisierul
	return 0;
}

int write_bmp(const char filename[], const bmp_file_header_t *p_file_header,
			  const bmp_info_header_t *p_info_header, const bitmap_t *p_bitmap)
{
	FILE *p_file;	//declar un pointer catre fisier
	int w, h, padding, e;

	//deschid fisierul pentru scriere in modul binar
	p_file = fopen(filename, "wb");	
	if (p_file == NULL) {	//verific daca nu s-a deschis
		fprintf(stderr, "Can't open file %s\n", filename);
		return 1;
	}

	//scrie o inregistrare in p_file
	e = fwrite(p_file_header, sizeof(bmp_file_header_t), 1, p_file);	
	if (e != 1) {	//verific daca nu s-a scris in fisier
		fprintf(stderr, "Error while writing the File Header\n");
		fclose(p_file);	//inchid fisierul
		return 1;
	}

	//scrie o inregistrare in p_info_header
	e = fwrite(p_info_header, sizeof(bmp_info_header_t), 1, p_file);	//
	if (e != 1) {	//verific daca nu s-a reusit scrierea
		fprintf(stderr, "Error while writing the Info Header\n");
		fclose(p_file);	//inchid fisierul
		return 1;
	}

	//cat timp pozitia curenta < offset-ul matricii de pixeli
	while (ftell(p_file) < (long)p_file_header->offset) {	
		e = fputc(0, p_file);	//pun caracterul '0' in fisierul p_file
		if (e != 0) {	//daca nu am reusit sa-l pun
			fprintf(stderr, "Error while writing to offset\n");
			fclose(p_file);	//inchide fisierul
			return 1;
		}
	}

	w = p_info_header->width;
	h = p_info_header->height;
	padding = (w * sizeof(pixel_t)) - (w * sizeof(pixel_t) / 4) * 4;	//realizez umplerea

	for (int i = h - 1; i >= 0; --i) {	//parcurg randurile
			//scrie in p_file "w" valori incepand de la p_bitmap->pixels[i]
		e = fwrite(p_bitmap->pixels[i], sizeof(pixel_t), w, p_file);	
		if (e != w) {	//daca nu am reusit sa scriu "w" valori
			fprintf(stderr, "Error while writing line %d\n", i);
			fclose(p_file);	//inchide fisierul
			return 1;
		}
		for (int j = 0; j < padding; ++j) {	//parcurg pana s-a umplut
			e = fputc(0, p_file);	//pun caracterul '0' in fisierul p_file
			if (e != 0) {	//daca nu am reusit sa-l pun in p_fille
				fprintf(stderr, "Error while writing padding\n");
				fclose(p_file);	//inchide fisierul
				return 1;
			}
		}
	}
	fclose(p_file);	//inchide fisierul
	return 0;
}

int rotate(bitmap_t *p_bitmap, int rotation, bitmap_t *p_temp)
{
	int e;
	int w = p_bitmap->width;
	int h = p_bitmap->height;

	if (rotation == 0) {	//daca nu avem rotatie
		e = initialize_bitmap(p_temp, w, h);	//alocam spatiu 
		if (e != 0) //daca nu am reusit sa alocam
		{
			goto exit_failure;	//nu s-a reusit executia programului
		}	
		for (int i = 0; i < p_temp->height; i++) {	//parcurg inaltimea imaginii
			for (int j = 0; j < p_temp->width; j++)	//parcurg latimea imaginii
				p_temp->pixels[i][j] = p_bitmap->pixels[i][j];	//copiez fiecare valoare(pixel)
		}
	} else if (rotation == 90) {	//daca avem rotatie de 90 de grade
		e = initialize_bitmap(p_temp, h, w); //aloca spatiu
		if (e != 0)	//verific daca nu am reusit sa aloc 
		{
			goto exit_failure;	//nu s-a reusit executia programului
		}
		for (int i = 0; i < p_temp->height; i++) {	//parcurg inaltimea imaginii
			for (int j = 0; j < p_temp->width; j++) {	//parcurg latimea imaginii
				p_temp->pixels[i][j] = p_bitmap->pixels[h - j - 1][i];	//copiez noua 
			}															//matrice de pixeli, realizez rotirea
		}
	} else 
		if (rotation == 180) {	//daca avem rotatie de 180 de grade
		e = initialize_bitmap(p_temp, w, h);	//alocam spatiu
		if (e != 0)	//verific daca am reusit sa aloc 
		{
			goto exit_failure;	//nu s-a reusit executia programului
		}
		for (int i = 0; i < h; i++) {	//parcurg liniile matricii de pixeli
			for (int j = 0; j < w; j++) {	//parcurg coloanele	matricii de pixeli
				//realizez rotirea
				p_temp->pixels[i][j] = p_bitmap->pixels[h - i - 1][w - j - 1];	
			}
		}
	} else if (rotation == 270) {	//daca rotatia este de 270 de grade
		e = initialize_bitmap(p_temp, h, w);	//aloc spatiu
		if (e != 0) 
		{
			goto exit_failure;	//nu s-a reusit executia programului	
		}
		for (int i = 0; i < p_temp->height; i++) {	//parcurg inaltimea imaginii
			for (int j = 0; j < p_temp->width; j++) {	//parcurg latimea imaginii
				p_temp->pixels[i][j] = p_bitmap->pixels[j][w - i - 1];	//realizez rotirea
			}
		}
	}
	return 0;

exit_failure:
	fprintf(stderr, "Error while initializing bitmap\n");
	return 1;
}