// C program to read a BMP Image and
// write the same into a PGM Image file
#include <stdio.h>
#include<stdlib.h>
#include<stdio.h>
#include"image.h"


void createImage(t_image * im)
{
    int i;
    im->pixel = (int **) malloc(sizeof(int*) * im->height);//creates an array of arrays
    if (im->pixel == NULL)
    {
      fprintf(stderr,"Out of memory");
          exit(0);
    }
    // dynamcally allocate memory of size im.width for each row
    for(i = 0; i<im->height; ++i)
    {
        im->pixel[i] = (int *) malloc(sizeof(int) * im->width);//creates an array for each row
        if (im->pixel[i] == NULL)
        {
          fprintf(stderr,"Out of memory");
          exit(0);
        }
    }
}


// C program to read a BMP Image and
//void loadImage(const char * nom_fichier, t_image im){
void loadImage(const char * nom_fichier, t_image * im)
{
		FILE *fp;
		char c;
		int i, j;

        fp = fopen(nom_fichier, "r");
        if(fp == NULL)
        {
              printf("Opening input file Error");
              exit(0);
        }
        fscanf(fp, "%c", &c);
        fscanf(fp, "%c", &c);
        fscanf(fp, "%d", &(im->width));
        fscanf(fp, "%d", &(im->height));
        fscanf(fp, "%d", &(im->greyLevel));

        createImage(im);

        for (i = 0; i < im->height; i++)
        {
			 for (j = 0; j < im->width; j++)
             {
               fscanf(fp, "%d", &(im->pixel[i][j]));
			 }
        }
        fclose(fp);
}

// write the same into a PGM Image file
void saveImage(const char * nom_fichier, t_image * im){

    int i, j = 0;

    FILE* pgmimg;
    pgmimg = fopen(nom_fichier, "w");
    if(pgmimg == NULL)
    {
        printf("Opening output file Error");
        exit(0);
    }

    // Writing Magic Number to the File
    fprintf(pgmimg, "P2\n");

    // Writing Height and Width
    fprintf(pgmimg, "%d %d\n", im->width,im->height);

    // Writing the maximum gray value
    fprintf(pgmimg, "255\n");


    for (i = 0; i < im->height; i++) {
        for (j = 0; j < im->width; j++)
        {
            fprintf(pgmimg, "%d ", im->pixel[i][j]);
        }
    }
    fclose(pgmimg);
}



