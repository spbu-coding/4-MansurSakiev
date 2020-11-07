#include <stdio.h>

#ifndef HW_4_BMP_H
#define HW_4_BMP_H

typedef enum {
    BMPv3_OK = 0,
    BMPv3_ERROR,
    BMPv3_OUT_OF_MEM,
    BMPv3_IO_ERROR,
    BMPv3_F_NOT_FOUND,
    BMPv3_F_NOT_SUP,
    BMPv3_INVALID_F,
    BMPv3_INVALID_ARG,
    BMPv3_MISMATCH_TYPE,
    BMPv3_ERR_NUMBER
} BMPv3_STATUS;

typedef struct BMPv3_header {
    short magic;
    long int file_size;
    short reserved1;
    short reserved2;
    long int data_offset;
    long int header_size;
    long int width;
    long int height;
    short planes;
    short b_p_p;
    long int compression_type;
    long int image_data_size;
    long int h_pixels_per_meter;
    long int v_pixels_per_meter;
    long int colors_used;
    long int colors_required;
} BMPv3_Header;

typedef struct BMPv3 {
    BMPv3_Header header;
    unsigned char* palette;
    unsigned char* data;
} BMPv3;

BMPv3* read_BMPv3_file(char* filename);

void write_BMPv3_file(BMPv3* bmp, char* filename);

int write_header(BMPv3* bmp, FILE* f);

int	read_header(BMPv3* bmp, FILE* f);

BMPv3_STATUS BMP_get_error();

const char* BMP_get_error_description();

#define BMP_ERROR_CHECK(output_file, return_value) \
	if (BMP_get_error() != BMPv3_OK) \
	{\
		fprintf((output_file), "%s\n", BMP_get_error_description());\
		return(return_value);	\
	} \


#endif //HW_4_BMP_H
