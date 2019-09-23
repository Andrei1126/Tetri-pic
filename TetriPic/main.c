#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "bmplib.h"

#define MAX_FILEAME 1024

#define INPUT_FILENAME "input.in"

int piesa_O(bitmap_t *p_bitmap)
{
	int e;
	e = initialize_bitmap(p_bitmap, 40, 40);    //aloc spatiu pentru matricea de pixeli
	if (e != 0) 
	{
		return 1;   //in cazul in care nu s-a putut aloca spatiu, intorc 1
	}
	int w = p_bitmap->width;    //w reprezinta latimea imaginii
	int h = p_bitmap->height;   //h reprezinta inaltimea imaginii

	for (int i = 0; i < h; i++) {   //parcurg randurile matricii de pixeli
		for (int j = 0; j < w; j++) {   //parcurg coloanele	matricii de pixeli
			if (i < (h-10) && i >= 10 && j >= 10 && j < (w - 10)) { //verific daca se afla in cadrul tabelei
				p_bitmap->pixels[i][j].b = 0;
				p_bitmap->pixels[i][j].g = 255;    //in caz afirmativ ii atribui culoarea galben
				p_bitmap->pixels[i][j].r = 255;
			} else {
				p_bitmap->pixels[i][j].b = 255;
				p_bitmap->pixels[i][j].g = 255;    //in caz contrar devine alb
				p_bitmap->pixels[i][j].r = 255;
			}
		}
	}
	return 0;   
}

int piesa_I(bitmap_t *p_bitmap)
{
	int e;
	e = initialize_bitmap(p_bitmap, 30, 60);    //aloc spatiu pentru matricea de pixeli
	if (e != 0)
	{ 
		return 1;	//in cazul in care nu s-a putut aloca spatiu, intorc 1
	}
	int w = p_bitmap->width;	//reprezinta latimea imaginii
	int h = p_bitmap->height;	//reprezinta inaltimea imaginii

	for (int i = 0; i < h; i++) {	//parcurg randurile matricii de pixeli
		for (int j = 0; j < w; j++) {	//parcurg coloanele	matricii de pixeli
			if (i < (h-10) && i >= 10 && j >= 10 && j < (w - 10)) {	//verific daca se afla in cadrul tabelei
				p_bitmap->pixels[i][j].b = 255;
				p_bitmap->pixels[i][j].g = 0;		//in caz afirmativ ii atribui culoarea albastru
				p_bitmap->pixels[i][j].r = 0;
			} else {
				p_bitmap->pixels[i][j].b = 255;
				p_bitmap->pixels[i][j].g = 255;		//in caz contrar devine alb
				p_bitmap->pixels[i][j].r = 255;
			}
		}
	}
	return 0;	
}

int piesa_S(bitmap_t *p_bitmap)
{
	int e;
	e = initialize_bitmap(p_bitmap, 50, 40);	//aloc spatiu pentru matricea de pixeli
	if (e != 0) 
	{
		return 1;	//in cazul in care nu s-a putut aloca, intorc 1
	}
	int w = p_bitmap->width;	//reprezinta latimea imaginii
	int h = p_bitmap->height;	//reprezinta inaltimea imaginii

	for (int i = 0; i < h; i++) {	//parcurg randurile matrcii de pixeli
		for (int j = 0; j < w; j++) {	//parcurg coloanele matricii de pixeli
			if (i >= 10 && i < 20 && j >= 20 && j < (w - 10)) {	//verific daca dse afla in cadrul tabelei
				p_bitmap->pixels[i][j].b = 0;
				p_bitmap->pixels[i][j].g = 0;		//in caz afirmativ ii atribui culoarea rosie
				p_bitmap->pixels[i][j].r = 255;
			} else if (i >= 20 && i < 30 && j < (w - 20) && j >= 10) {	//verific daca se afla in cadrul tabelei
				p_bitmap->pixels[i][j].b = 0;
				p_bitmap->pixels[i][j].g = 0;		//in caz afirmativ ii atribui culoarea rosie
				p_bitmap->pixels[i][j].r = 255;
			} else {
				p_bitmap->pixels[i][j].b = 255;
				p_bitmap->pixels[i][j].g = 255;		//in caz contrar devine alb
				p_bitmap->pixels[i][j].r = 255;
			}
		}
	}
	return 0;	
}


int piesa_Z(bitmap_t *p_bitmap)
{
	int e;
	e = initialize_bitmap(p_bitmap, 50, 40);	//aloc spatiu pentru matricea de pixeli
	if (e != 0) 
	{
		return 1;	//in cazul in care nu s-a putut aloca intorc 1
	}
	int w = p_bitmap->width;	//reprezinta latimea imaginii
	int h = p_bitmap->height;	//reprezinta inaltimea imaginii

	for (int i = 0; i < h; i++) {	//parcurg randurile matricii de pixeli
		for (int j = 0; j < w; j++) {	//parcurg coloanele matricii de pixeli

			if (i >= 10 && i < 20 && j >= 10 && j < 30) {	//verific daca se afla in cadrul tabelei
				p_bitmap->pixels[i][j].b = 0;
				p_bitmap->pixels[i][j].g = 255;		//in caz afirmativ ii atribui culoarea verde
				p_bitmap->pixels[i][j].r = 0;
			} else if (i >= 20 && i < 30 && j >= 20 && j < (w - 10)) {	//verific daca se afla in cadrul tabelei
				p_bitmap->pixels[i][j].b = 0;
				p_bitmap->pixels[i][j].g = 255;		//in caz afirmativ ii atribui culoarea verde
				p_bitmap->pixels[i][j].r = 0;
			} else {
				p_bitmap->pixels[i][j].b = 255;
				p_bitmap->pixels[i][j].g = 255;		//in caz contrar devine alb
				p_bitmap->pixels[i][j].r = 255;	
			}
		}
	}
	return 0;	
}

int piesa_L(bitmap_t *p_bitmap)
{
	int e;
	e = initialize_bitmap(p_bitmap, 40, 50);	//aloc spatiu pentru matricea de pixeli
	if (e != 0) 
	{
		return 1;	//in cazul in care nu s-a putut aloca intorc 1
	}
	int w = p_bitmap->width;	//reprezinta latimea imaginii
	int h = p_bitmap->height;	//reprezinta inaltimea imaginii

	for (int i = 0; i < h; i++) {	//parcurg randurile matricii de pixeli
		for (int j = 0; j < w; j++) {	//parcurg coloanele matricii de pixeli
			if (i >= 10 && i < 40 && j >= 10 && j < 20) {	//verific daca se afla in cadrul tabelei
				p_bitmap->pixels[i][j].b = 0;
				p_bitmap->pixels[i][j].g = 140;		//in caz afirmativ ii atribui culoarea portocaliu
				p_bitmap->pixels[i][j].r = 255;
			} else if (i >= 30 && i < 40 && j >= 20 && j < 30) {	//verific daca se afla in cadrul tabelei
				p_bitmap->pixels[i][j].b = 0;
				p_bitmap->pixels[i][j].g = 140;		//in caz afirmativ ii atribui culoarea portocaliu
				p_bitmap->pixels[i][j].r = 255;
			} else {
				p_bitmap->pixels[i][j].b = 255;
				p_bitmap->pixels[i][j].g = 255;		//in caz contrar devine alb
				p_bitmap->pixels[i][j].r = 255;
			}
		}
	}
	return 0;
}

int piesa_J(bitmap_t *p_bitmap)
{
	int e;
	e = initialize_bitmap(p_bitmap, 40, 50);	//aloc spatiu pentru matricea de pixeli
	if (e != 0) 	
	{
		return 1;	//in cazul in care nu s-a putut aloca intorc 1
	}
	int w = p_bitmap->width;	//reprezinta latimea piesei
	int h = p_bitmap->height;	//reprezinta inaltimea piesei

	for (int i = 0; i < h; i++) {	//parcurg randurile matricii de pixeli
		for (int j = 0; j < w; j++) {	//parcurg coloanele matricii de pixeli
			if (i >= 10 && i < 40 && j >= 20 && j < 30) {	//verific daca se afla in cadrul tabelei
				p_bitmap->pixels[i][j].b = 255;
				p_bitmap->pixels[i][j].g = 0;		//in caz afirmativ ii atribui culoarea roz
				p_bitmap->pixels[i][j].r = 255;
			} else if (i >= 30 && i < 40 && j >= 10 && j < 20) {	//verific daca se afla in cadrul tabelei
				p_bitmap->pixels[i][j].b = 255;
				p_bitmap->pixels[i][j].g = 0;		//in caz afirmativ ii atribui culoarea roz
				p_bitmap->pixels[i][j].r = 255;
			} else { 
				p_bitmap->pixels[i][j].b = 255;
				p_bitmap->pixels[i][j].g = 255;		//in caz contrar devine alb
				p_bitmap->pixels[i][j].r = 255;
			}
		}
	}
	return 0;	
}


int piesa_T(bitmap_t *p_bitmap)
{
	int e;
	e = initialize_bitmap(p_bitmap, 50, 40);	//aloc spatiu pentru matricea de pixeli
	if (e != 0)
	{
		 return 1;	//in cazul in care nu s-a putut aloca intorc 1
	}
	int w = p_bitmap->width;	//reprezinta latimea piesei
	int h = p_bitmap->height;	//reprezinta inaltimea piesei

	for (int i = 0; i < h; i++) {	//parcurg randurile matricii de pixeli
		for (int j = 0; j < w; j++) {	//parcurg coloanele matricii de pixeli
			if (i >= 10 && i < 20 && j >= 10 && j < (w - 10)) {	//verific daca se afla in cadrul tabelei
				p_bitmap->pixels[i][j].b = 255;
				p_bitmap->pixels[i][j].g = 0;		//in caz afirmativ ii atribui culoarea mov
				p_bitmap->pixels[i][j].r = 130;
			} else if (i >= 20 && i < 30 && j >= 20 && j < 30) {	//verific daca se afla in cadrul tabelei
				p_bitmap->pixels[i][j].b = 255;
				p_bitmap->pixels[i][j].g = 0;		//in caz afirmativ ii atribui culoarea mov
				p_bitmap->pixels[i][j].r = 130;
			} else {
				p_bitmap->pixels[i][j].b = 255;
				p_bitmap->pixels[i][j].g = 255;		//in caz contrar devine alb
				p_bitmap->pixels[i][j].r = 255;
			}
		}
	}
	return 0;	
}

void setStructures(bitmap_t *p_bitmap, bmp_info_header_t *p_info,
					 bmp_file_header_t *p_file)

// functie care seteaza file header si info header

{
	p_file->signature = BMP_SIGNATURE;	//0x4d42
	p_file->offset = OFFSET;	//54

	p_info->header_size = BMP_INFO_HEADER_SIZE;	//40
	p_info->width = p_bitmap->width;	//latimea matricii de pixeli
	p_info->height = p_bitmap->height;	//inaltimea matricii de pixeli
	p_info->planes = 1;		
	p_info->bit_count = BMP_BIT_COUNT;	//nr de biti per pixel
	p_info->compression = 0;
	p_info->x_pixels_per_meter = 0;
	p_info->y_pixels_per_meter = 0;
	p_info->colors_used = 0;
	p_info->colors_important = 0;

	int w = p_info->width;	
	int h = p_info->height;

	//umplerea unei linii
	int padding = (w * sizeof(pixel_t)) - (w * sizeof(pixel_t) / 4) * 4;
	padding *= h; //umplerea tuturor liniilo

	p_info->image_size = w * h * sizeof(pixel_t) + padding;	//dimensiunea imaginii
	p_file->file_size = p_info->image_size + sizeof(bmp_file_header_t) + sizeof(bmp_info_header_t);	//calculez dimensiunea totala a fisierului
}


int remove_border(bitmap_t *p_bitmap, bitmap_t *temp_bitmap)

// functie care elimina bordura alba din jurul piesei

{
	int w = p_bitmap->width;
	int h = p_bitmap->height;

	int e = initialize_bitmap(temp_bitmap, w - 20, h - 20);	//aloc spatiu pentru matricea de pixeli
	if (e != 0) 
	{
		return 1;
	}
	for (int i = 0; i < temp_bitmap->height; i++) {	//parcurg randurile
		for (int j = 0; j < temp_bitmap->width; j++) {	//parcurg coloanele
			temp_bitmap->pixels[i][j] = p_bitmap->pixels[i + 10][j + 10];	///coltul din stanga sus al piesei va fi amplasat
		}																	//la coordonata 10:10
	}

	return 0;
}


int add_piece(bitmap_t *p_bitmap, bitmap_t *temp_bitmap, int coloana)
// functie care adauga piesa in bitmap
{
	int h = p_bitmap->height;	//inaltimea imaginii
	int h_piesa = temp_bitmap->height;	//inaltimea piesei
	int w_piesa = temp_bitmap->width;	//latimea piesei
	for (int i = 0; i < h_piesa; i++) {	//parcurg liniile piesei
		for (int j = 0; j < w_piesa; j++) {	//parcurg coloanele piesei
			if (temp_bitmap->pixels[i][j].r == 255 &&
				    temp_bitmap->pixels[i][j].g == 255 &&	//daca este culoarea alb, trece peste
				    temp_bitmap->pixels[i][j].b == 255) {
				continue;
			} else {
				p_bitmap->pixels[h - h_piesa + i][j + 10*coloana] =
					temp_bitmap->pixels[i][j];	//adaugam piesa in bitmap
			}
		}
	}
	return 0;
}

int task3(bitmap_t *p_bitmap, bitmap_t *temp_bitmap)
{
	//deschid fisierul "cerinta3.in" pentru citire
	FILE *in = fopen("cerinta3.in", "r");	
	if (in == NULL) {	//verific daca nu s-a reusit deschiderea
		fprintf(stderr, "Can't open the file\n");
		return 1;
	}

	int n;
	int e;

	e = fscanf(in, "%d %*d %*d\n", &n);	//citesc n din in

	int rotatie, coloana;
	char *numePiesa = malloc(sizeof(char) * 5);	//aloc spatiu pentru numele piesei
	bitmap_t aux_bitmap; //o sa stocheze piesa rotita

	for (int i = 0; i < n; i++) {
		//citesc cele 3 variabile din in
		e = fscanf(in, "%s %d %d\n", numePiesa, &rotatie, &coloana); 

		if (strcmp(numePiesa, "O") == 0)  {	//daca numele piesei este "O"
			e = piesa_O(temp_bitmap);	//apelez functia
			if (e != 0) 	//verific daca nu s-a putut crea piesa
			{
				return 1;
			}
			//apelez functia de rotire a piesei si o stochez apoi in "aux_bitmap"
			rotate(temp_bitmap, rotatie, &aux_bitmap);
			//elimin bordura din jurul lui temp_bitmap	
			e = remove_border(&aux_bitmap, temp_bitmap);
			//in "temp_bitmap" va fi piesa rotita si fara chenar alb	
			e = add_piece(p_bitmap, temp_bitmap, coloana);

		} else if (strcmp(numePiesa, "I") == 0) {	//daca numele piesei este "I"
			e = piesa_I(temp_bitmap); //piesa nerotita, apelez functia pentru piesa "I"
			//rotesc piesa si o stochez in aux_bitmap
			rotate(temp_bitmap, rotatie, &aux_bitmap);
			//elimin chenarul alb din jurul piesei	
			e = remove_border(&aux_bitmap, temp_bitmap);	
			// in "temp_bitmap" va fi piesa rotita si fara chenar alb
			e = add_piece(p_bitmap, temp_bitmap, coloana);


		} else if (strcmp(numePiesa, "S") == 0) {	//daca numele piesei este "S"
			e = piesa_S(temp_bitmap);	//piesa nerotita, apelez functia pentru piesa "S"
			//rotesc piesa si o stochez in "aux_bitmap"
			rotate(temp_bitmap, rotatie, &aux_bitmap);	
			//elimin chenarul alb din jurul piesei
			e = remove_border(&aux_bitmap, temp_bitmap);
			//in "temp_bitmap" va fi piesa rotita si fara chenar alb
			e = add_piece(p_bitmap, temp_bitmap, coloana);

		} else if (strcmp(numePiesa, "Z") == 0) {	//daca numele piesei este "Z"
			e = piesa_Z(temp_bitmap);	//piesa nerotita, apelez functia pentru piesa "Z"
			//rotesc piesa si o stochez in "aux_bitmap"
			rotate(temp_bitmap, rotatie, &aux_bitmap);
			//elimin chenarul alb din jurul piesei
			e = remove_border(&aux_bitmap, temp_bitmap);
			//in "temp_bitmap" va fi piesa rotita si fara chenar alb
			e = add_piece(p_bitmap, temp_bitmap, coloana);

		} else if (strcmp(numePiesa, "L") == 0) {	//daca numele piesei este "L
			e = piesa_L(temp_bitmap);	//piesa nerotita, apelez functia pentru piesa "L"
			//rotesc piesa si o stochez in "aux_bitmap"
			rotate(temp_bitmap, rotatie, &aux_bitmap);
			//elimin chenarul alb din jurul piesei
			e = remove_border(&aux_bitmap, temp_bitmap);
			//in "temp_bitmap" va fi piesa rotita si fara chenar alb
			e = add_piece(p_bitmap, temp_bitmap, coloana);

		} else if (strcmp(numePiesa, "J") == 0) {	//daca numele piesei este "J"
			e = piesa_J(temp_bitmap);	//piesa nerotita, apelez functia pentru piesa "J"
			//rotesc piesa si o stochez in "aux_bitmap"
			rotate(temp_bitmap, rotatie, &aux_bitmap);
			//elimin chenarul alb din jurul piesei
			e = remove_border(&aux_bitmap, temp_bitmap);
			//in "temp_bitmap" va fi piesa rotita si fara chenar
			e = add_piece(p_bitmap, temp_bitmap, coloana);

		} else if (strcmp(numePiesa, "T") == 0) {	//daca numele piesei este "T"
			e = piesa_T(temp_bitmap);	//piesa nerotita, apelez functia pentru piesa "T"

			//rotesc piesa si o stochez in "aux_bitmap"
			rotate(temp_bitmap, rotatie, &aux_bitmap);
			//elimin chenarul allb din jurul piesei
			e = remove_border(&aux_bitmap, temp_bitmap);
			//in "temp_bitmap" va fi piesa rotita si fara chenar
			e = add_piece(p_bitmap, temp_bitmap, coloana);

		} else {	//altfel nu exista piesa cu numele specificat
			fprintf(stderr, "INVALID NAME\n");
			return 1;
		}
	}

	fclose(in);	//inchid fisierul "in"
	return 0;	
}

int main(int argc, char *argv[])
{

	bmp_file_header_t file_header;	//declar un element de tipul "bmp_file_header_t"
	bmp_info_header_t info_header;	//declar un element de tipul "bmp_info_header_t"
	bitmap_t bitmap, tmp_bitmap;	//declar 2 elemente de tipul "bitmap_t"
	bitmap.pixels = NULL;	
	tmp_bitmap.pixels = NULL;

	int e;

	if (argc != 2) //daca nr argumentelor introduse in linia de comanda nu este 2
	{
		goto exit_failure;	//nu s-a reusit executia programului
	}

	//daca al doilea argument este "1", atunci ne vom referi la TASK 1
	if (strcmp(argv[1], "1") == 0) { 

		//piesa "I"
		e = piesa_I(&bitmap);
		//apelez functia ce seteaza file header si info header
		setStructures(&bitmap, &info_header, &file_header);	
		fprintf(stderr, "%d\n", file_header.file_size);	//opresc executia programului	
		//creez imaginea pentru piesa "I"
		e = write_bmp("piesa_I.bmp", &file_header, &info_header, &bitmap);	
		//citesc piesa "I"
		e = read_bmp("piesa_I_aux.bmp", &file_header, &info_header, &bitmap);
		fprintf(stderr, "%d\n", file_header.file_size);	//opresc executia programului

		//piesa "O"
		e = piesa_O(&bitmap);
		//apelez functia ce seteaza file header si info header
		setStructures(&bitmap, &info_header, &file_header);
		//creez imaginea pentru piesa "O"
		e = write_bmp("piesa_O.bmp", &file_header, &info_header, &bitmap);

		//piesa "S"
		e = piesa_S(&bitmap);
		//apelez functia ce seteaza file header si info header
		setStructures(&bitmap, &info_header, &file_header);
		//creez imaginea pentru piesa "S"
		e = write_bmp("piesa_S.bmp", &file_header, &info_header, &bitmap);

		//piesa "Z"
		e = piesa_Z(&bitmap);
		//apelez functia ce seteaza file header si info header
		setStructures(&bitmap, &info_header, &file_header);
		//creez imaginea pentru piesa "S"
		e = write_bmp("piesa_Z.bmp", &file_header, &info_header, &bitmap);

		//piesa "L"
		e = piesa_L(&bitmap);
		//apelez functia ce seteaza file header si info header
		setStructures(&bitmap, &info_header, &file_header);
		//creez imagina pentru piesa "L"
		e = write_bmp("piesa_L.bmp", &file_header, &info_header, &bitmap);

		//piesa "J"
		e = piesa_J(&bitmap);
		//apelez functia ce seteaza file header si info header
		setStructures(&bitmap, &info_header, &file_header);
		//creez imaginea pentru piesa "J"
		e = write_bmp("piesa_J.bmp", &file_header, &info_header, &bitmap);

		//piesa "T"
		e = piesa_T(&bitmap);
		//apelez functia ce seteaza file header si info header
		setStructures(&bitmap, &info_header, &file_header);
		//creez imaginea pentru piesa "T"
		e = write_bmp("piesa_T.bmp", &file_header, &info_header, &bitmap);

		//daca al doilea argument este 2, atunci ne vom referi la TASK 2
	} else if (strcmp(argv[1], "2") == 0){ 

/* --------- 90 ------------ */
		
		//piesa "O"
		e = piesa_O(&bitmap);
		//rotesc piesa "O" cu 90 de grade si o retin in "tmp_bitmap"
		rotate(&bitmap, 90, &tmp_bitmap);
		//apelez functia ce seteaza file header si info header
		setStructures(&tmp_bitmap, &info_header, &file_header);
		//creez imaginea pentru piesa "O" rotita cu 90 de grade
		e = write_bmp("piesa_O_90.bmp", &file_header, &info_header, &tmp_bitmap);
		clear_bitmap(&bitmap);	//eliberez zona de memorie alocata pentru "bitmap"
		clear_bitmap(&tmp_bitmap);	//eliberez zona de memorie pentru "tmp_bitmap"

		//piesa "I"
		e = piesa_I(&bitmap);
		//rotesc piesa cu "I" cu 90 de grade si o retin in "tmp_bitmap"
		rotate(&bitmap, 90, &tmp_bitmap);
		//apelez functia ce seteaza file header si info header
		setStructures(&tmp_bitmap, &info_header, &file_header);
		//creez imaginea pentru piesa "I" rotita cu 90 de grade
		e = write_bmp("piesa_I_90.bmp", &file_header, &info_header, &tmp_bitmap);
		clear_bitmap(&bitmap);	//eliberez zona de memorie pentru "bitmap"
		clear_bitmap(&tmp_bitmap);	//eliberez zona de memorie pentru "tmp_bitmap"

		//piesa "S"
		e = piesa_S(&bitmap);
		//rotesc piesa "S" cu 90 de grade si o retin in "tmp_bitmap"
		rotate(&bitmap, 90, &tmp_bitmap);
		//apelez functia ce seteaza file header si info header
		setStructures(&tmp_bitmap, &info_header, &file_header);
		//creez imaginea pentru piesa "S" rotita cu 90 de grade
		e = write_bmp("piesa_S_90.bmp", &file_header, &info_header, &tmp_bitmap);
		clear_bitmap(&bitmap);	//eliberez zona de memorie pentru "bitmap"
		clear_bitmap(&tmp_bitmap);	//eliberez zona de memorie pentru "tmp_bitmap"

		//piesa "Z"
		e = piesa_Z(&bitmap);
		//rotesc piesa "S" cu 90 de grade si o retin in "tmp_bitmap"
		rotate(&bitmap, 90, &tmp_bitmap);
		//apelez functia ce seteaza file header si info header
		setStructures(&tmp_bitmap, &info_header, &file_header);
		//creez imaginea pentru piesa "S" rotita cu 90 de grade
		e = write_bmp("piesa_Z_90.bmp", &file_header, &info_header, &tmp_bitmap);
		clear_bitmap(&bitmap);	//eliberez zona de memorie pentru "bitmap"
		clear_bitmap(&tmp_bitmap);	//eliberez zona de memorie pentru "tmp_bitmap"

		//piesa "L"
		e = piesa_L(&bitmap);
		//rotesc piesa "L" cu 90 de grade si o retin in "tmp_bitmap"
		rotate(&bitmap, 90, &tmp_bitmap);
		//apelez functia ce seteaza file header si info header
		setStructures(&tmp_bitmap, &info_header, &file_header);
		//creez imaginea pentru piesa "L rotita cu 90 de grade"
		e = write_bmp("piesa_L_90.bmp", &file_header, &info_header, &tmp_bitmap);
		clear_bitmap(&bitmap);	//eliberez zona de memorie pentru "bitmap"
		clear_bitmap(&tmp_bitmap);	//eliberez zona de memorie pentru "tmp_bitmap"

		//piesa "J"
		e = piesa_J(&bitmap);
		rotate(&bitmap, 90, &tmp_bitmap);
		//rotesc piesa "J" cu 90 de grade si o retin in "tmp_bitmap"
		setStructures(&tmp_bitmap, &info_header, &file_header);
		//creez imaginea pentru piesa "J" rotita cu 90 de grade
		e = write_bmp("piesa_J_90.bmp", &file_header, &info_header, &tmp_bitmap);
		clear_bitmap(&bitmap);	//eliberez memoria pentru "bitmap"
		clear_bitmap(&tmp_bitmap);	//eliberez memoria pentru "tmp_bitmap"

		//piesa "T"
		e = piesa_T(&bitmap);
		//rotesc piesa "T" cu 90 de grade si o retin in "tmp_bitmap"
		rotate(&bitmap, 90, &tmp_bitmap);
		//apelez functia ce seteaza file header si info header
		setStructures(&tmp_bitmap, &info_header, &file_header);
		//creez imaginea pentru piesa "T" rotita cu 90 de grade
		e = write_bmp("piesa_T_90.bmp", &file_header, &info_header, &tmp_bitmap);
		clear_bitmap(&bitmap);	//eliberez zona de memorie pentru "bitmap"
		clear_bitmap(&tmp_bitmap);	//eliberez zona de memorie pentru "tmp_bitmap"

// --------- 180 ----------- //

		//piesa "O"
		e = piesa_O(&bitmap);
		//rotesc piesa "O" cu 180 de grade si o retin in "tmp_bitmap"
		rotate(&bitmap, 180, &tmp_bitmap);
		//apelez functia ce seteaza file header si info header
		setStructures(&tmp_bitmap, &info_header, &file_header);
		//creez imaginea pentru piesa "T" rotita cu 180 de grade
		e = write_bmp("piesa_O_180.bmp", &file_header, &info_header, &tmp_bitmap);
		clear_bitmap(&bitmap);	//eliberez zona de memorie pentru "bitmap"
		clear_bitmap(&tmp_bitmap);	//eliberez zona de memorie pentru "tmp_bitmap"

		//piesa "I"
		e = piesa_I(&bitmap);
		//rotesc piesa "I" cu 180 de grade si o retin in "tmp_bitmap"
		rotate(&bitmap, 180, &tmp_bitmap);
		//apelez functia ce seteaza file header si info header
		setStructures(&tmp_bitmap, &info_header, &file_header);
		//creez imaginea pentru piesa "I" rotita cu 180 de grade
		e = write_bmp("piesa_I_180.bmp", &file_header, &info_header, &tmp_bitmap);
		clear_bitmap(&bitmap);	//eliberez zona de memorie pentru "bitmap"
		clear_bitmap(&tmp_bitmap);	//eliberez zona de memorie pentru "tmp_bitmap"

		//piesa "S"
		e = piesa_S(&bitmap);
		//rotesc piesa "S" cu 180 de grade si o retin in "tmp_bitmap"
		rotate(&bitmap, 180, &tmp_bitmap);
		//apelez functia ce seteaza file header si info header
		setStructures(&tmp_bitmap, &info_header, &file_header);
		//creez imaginea pentru piesa "S" rotita cu 180 de grade
		e = write_bmp("piesa_S_180.bmp", &file_header, &info_header, &tmp_bitmap);
		clear_bitmap(&bitmap);	//eliberez zona de memorie pentru "bitmap"
		clear_bitmap(&tmp_bitmap);	//eliberez zona de memorie pentru "tmp_bitmap"

		//piesa "Z"
		e = piesa_Z(&bitmap);
		//rotesc piesa "Z" cu 180 de grade si o retin in "tmp_bitmap"
		rotate(&bitmap, 180, &tmp_bitmap);
		//apelez functia ce seteaza file header si info header
		setStructures(&tmp_bitmap, &info_header, &file_header);
		//creez imaginea pentru piesa "Z" rotita cu 180 de grade
		e = write_bmp("piesa_Z_180.bmp", &file_header, &info_header, &tmp_bitmap);
		clear_bitmap(&bitmap);	//eliberez zona de memorie pentru "bitmap"
		clear_bitmap(&tmp_bitmap);	//eliberez zona de memorie pentru "tmp_bitmap"

		//piesa "L"
		e = piesa_L(&bitmap);
		//rotesc piesa "L" cu 180 de grade si o retin
		rotate(&bitmap, 180, &tmp_bitmap);
		//apelez functia ce seteaza file header si info header
		setStructures(&tmp_bitmap, &info_header, &file_header);
		//creez imaginea pentru piesa "L" rotita cu 180 de grade
		e = write_bmp("piesa_L_180.bmp", &file_header, &info_header, &tmp_bitmap);
		clear_bitmap(&bitmap);	//eliberez zona de memorie pentru "bitmap"
		clear_bitmap(&tmp_bitmap);	//eliberez zona de memorie pentru "tmp_bitmap"

		//piesa "J"
		e = piesa_J(&bitmap);
		//rotesc piesa "J" cu 180 de grade si o retin
		rotate(&bitmap, 180, &tmp_bitmap);
		//apelez functia ce seteaza file header si info header
		setStructures(&tmp_bitmap, &info_header, &file_header);
		//creez imaginea pentru piesa "J" rotita cu 180 de grade
		e = write_bmp("piesa_J_180.bmp", &file_header, &info_header, &tmp_bitmap);
		clear_bitmap(&bitmap);	//eliberez zona de memorie pentru "bitmap"
		clear_bitmap(&tmp_bitmap);	//eliberez zona de memorie pentru "tmp_bitmap"

		//piesa "T"
		e = piesa_T(&bitmap);
		//rotesc piesa "T" cu 180 de grade si o retin
		rotate(&bitmap, 180, &tmp_bitmap);
		//apelez functia ce seteaza file header si info header
		setStructures(&tmp_bitmap, &info_header, &file_header);
		//creez imaginea pentru piesa "T" rotita cu 180 de grade
		e = write_bmp("piesa_T_180.bmp", &file_header, &info_header, &tmp_bitmap);
		clear_bitmap(&bitmap);	//eliberez zona de memorie pentru "bitmap"
		clear_bitmap(&tmp_bitmap);	//eliberez zona de memorie pentru "tmp_bitmap"

// --------- 270 ----------- //

		//piesa "O"
		e = piesa_O(&bitmap);
		//rotesc piesa "O" cu 270 de grade si o retin
 		rotate(&bitmap, 270, &tmp_bitmap);
 		//apelez functia ce seteaza file header si info header
		setStructures(&tmp_bitmap, &info_header, &file_header);
		//creez imaginea pentru piesa "O" rotita cu 270 de grade
		e = write_bmp("piesa_O_270.bmp", &file_header, &info_header, &tmp_bitmap);
		clear_bitmap(&bitmap);	//eliberez zona de memorie pentru "bitmap"
		clear_bitmap(&tmp_bitmap);	//eliberez zona de memorie pentru "tmp_bitmap"

		//piesa "I"
		e = piesa_I(&bitmap);
		//rotesc piesa "I" cu 270 de grade si o retin
		rotate(&bitmap, 270, &tmp_bitmap);
		//apelez functia ce setaza file header si info header
		setStructures(&tmp_bitmap, &info_header, &file_header);
		//creez imaginea pentru piesa "I" rotita cu 270 de grade
		e = write_bmp("piesa_I_270.bmp", &file_header, &info_header, &tmp_bitmap);
		clear_bitmap(&bitmap);	//eliberez zona de memorie pentru "bitmap"
		clear_bitmap(&tmp_bitmap);	//eliberez zona de memorie pentru "tmp_bitmap"

		//piesa "S"
		e = piesa_S(&bitmap);
		//rotesc piesa "S" cu 270 de grade si o retin
		rotate(&bitmap, 270, &tmp_bitmap);
		//apelez functia ce seteaza file header si info header
		setStructures(&tmp_bitmap, &info_header, &file_header);
		//creez imaginea pentru piesa "S" rotita cu 270 de grade
		e = write_bmp("piesa_S_270.bmp", &file_header, &info_header, &tmp_bitmap);
		clear_bitmap(&bitmap);	//eliberez zona de memorie pentru "bitmap"
		clear_bitmap(&tmp_bitmap);	//eliberez zona de memorie pentru "tmp_bitmap"

		//piesa "Z"
		e = piesa_Z(&bitmap);
		//rotesc piesa "Z" cu 270 de grade si o retin
		rotate(&bitmap, 270, &tmp_bitmap);
		//apelez functia ce seteaza file header si info header
		setStructures(&tmp_bitmap, &info_header, &file_header);
		//creez imaginea pentru piesa "Z" rotita cu 270 de grade
		e = write_bmp("piesa_Z_270.bmp", &file_header, &info_header, &tmp_bitmap);
		clear_bitmap(&bitmap);	//eliberez zona de memorie pentru "bitmap"
		clear_bitmap(&tmp_bitmap);	//eliberez zona de memorie pentru "tmp_bitmap"

		//piesa "L"
		e = piesa_L(&bitmap);
		//rotesc piesa "L" cu 270 de grade si o retin
		rotate(&bitmap, 270, &tmp_bitmap);
		//apelez functia ce seteaza file header si info header
		setStructures(&tmp_bitmap, &info_header, &file_header);
		//creez imaginea pentru piesa "L" rotita cu 270 de grade
		e = write_bmp("piesa_L_270.bmp", &file_header, &info_header, &tmp_bitmap);
		clear_bitmap(&bitmap);	//eliberez zona de memorie pentru "bitmap"
		clear_bitmap(&tmp_bitmap);	//eliberez zona de memorie pentru "tmp_bitmap"

		//piesa "J"
		e = piesa_J(&bitmap);
		//rotesc piesa "J" cu 270 de grade si o retin
		rotate(&bitmap, 270, &tmp_bitmap);
		//apelez functia ce seteaza file header si info header
		setStructures(&tmp_bitmap, &info_header, &file_header);
		//creez imaginea pentru piesa "J" rotita cu 270 de grade
		e = write_bmp("piesa_J_270.bmp", &file_header, &info_header, &tmp_bitmap);
		clear_bitmap(&bitmap);	//eliberez zona de memorie pentru "bitmap"
		clear_bitmap(&tmp_bitmap);	//eliberez ozna de memorie pentru "tmp_bitmap"

		//piesa "T"
		e = piesa_T(&bitmap);
		//rotesc piesa "T" cu 270 de grade si o retin 
		rotate(&bitmap, 270, &tmp_bitmap);
		//apelez functia ce seteaza file header si infor header
		setStructures(&tmp_bitmap, &info_header, &file_header);
		//creez imaginea pentru piesa "T" rotita cu 270 de grade
		e = write_bmp("piesa_T_270.bmp", &file_header, &info_header, &tmp_bitmap);
		clear_bitmap(&bitmap);	//eliberez zona de memorie pentru "bitmap"
		clear_bitmap(&tmp_bitmap);	//eliberez zona de memorie pentru "tmp_bitmap"

		// daca al doilea argument este 3, atunci ne vom referi la TASK 3
	} else if (strcmp(argv[1], "3") == 0) { 
		FILE *in = fopen("cerinta3.in", "r");	//deschid fisierul "cerinta3.in" pentru citire
		if (in == NULL) {	//daca nu am reusit sa deschid fisierul
			fprintf(stderr, "Can't open the file cerinta3.in\n");
			goto exit_failure;	//nu s-a reusit executia programului
		}
		int n = 0;

		// in bitmap vom pune piesa nerotita si cu chenar alb

		e = fscanf(in, "%d %d %d", &n, &bitmap.height, &bitmap.width);
		bitmap.height *= 10;
		bitmap.width *= 10;	
		bitmap.height += 40; 
	    // aloc spatiu pentru partea alba a bitmapului
		e = initialize_bitmap(&bitmap, bitmap.width, bitmap.height);
		if (e != 0) {	//verific daca nu am reusit sa aloc spatiu
			printf("Error while initialize the bitmap!\n");
		}

		// desenez un bitmap gol(fara piese) ca in cerinta
		for (int i = 0; i < bitmap.height; i++) {
			for (int j = 0; j < bitmap.width; j++) {
				if (i < 40) {
					bitmap.pixels[i][j].r = 255;
					bitmap.pixels[i][j].g = 255;
					bitmap.pixels[i][j].b = 255;
				} else {
					bitmap.pixels[i][j].r = 0;
					bitmap.pixels[i][j].g = 0;
					bitmap.pixels[i][j].b = 0;
				}
			}
		}
		// in tmp_bitmap vor avea piesa rotita si fara chenar alb
		e = task3(&bitmap, &tmp_bitmap);
		if (e != 0) {
			printf("Error task3\n");
		}
		setStructures(&bitmap, &info_header, &file_header);
		e = write_bmp("task3.bmp", &file_header, &info_header, &bitmap);
		if (e != 0) {
			printf("Error writing task3.bmp\n");
		}

		fclose(in);	//inchid fisierul

	} 
	//eliberez zona de memorie
	clear_bitmap(&bitmap);
	clear_bitmap(&tmp_bitmap);
	return 0;

exit_failure:
	//eliberez zona de memorie
	clear_bitmap(&bitmap);
	clear_bitmap(&tmp_bitmap);
	return 1;
}
