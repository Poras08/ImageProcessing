#include <stdio.h>
#include<string.h>
#include<math.h>
#include "traitement.h"
#include"image.h"


void binarizeImage(t_image *initImage, t_image *treatedImage){
  treatedImage->height = initImage->height;
  treatedImage->width = initImage->width;
  treatedImage->greyLevel = initImage->greyLevel;

  createImage(treatedImage);

  int i, j;
  for (i = 0; i < initImage->height; i++) {
        for (j = 0; j < initImage->width; j++) {
            if(initImage->pixel[i][j]< 127)
				treatedImage->pixel[i][j]=0;
			else treatedImage->pixel[i][j]=255;
        }
  }
}

void negatifImage(t_image *initImage, t_image *treatedImage){
  treatedImage->height = initImage->height;
  treatedImage->width = initImage->width;
  treatedImage->greyLevel = initImage->greyLevel;

  createImage(treatedImage);

  int i, j;
  for (i = 0; i < initImage->height; i++) {
        for (j = 0; j < initImage->width; j++) {
            treatedImage->pixel[i][j]= 255 - initImage->pixel[i][j];
        }
  }
}


void convolution(t_image *initImage, t_image *treatedImage) {
    treatedImage->height = initImage->height;
    treatedImage->width = initImage->width;
    treatedImage->greyLevel = initImage->greyLevel;

    createImage(treatedImage);

    int i, j, k, l, m, n, newPixelValue;
    int convolution[3][3] = {{1, 1, 1}, {1, 1, 1}, {1, 1, 1}};

    for (i = 0; i < initImage->height; i++) {
        for (j = 0; j < initImage->width; j++) {
            newPixelValue = 0;
            m = 0;
            for (k = i - 1; k <= i + 1; k++) {
                n = 0;
                for (l = j - 1; l <= j + 1; l++) {
                    if ((k >= 0 && k < initImage->height) && (l >= 0 && l < initImage->width)) {
                        newPixelValue += initImage->pixel[k][l] * convolution[m][n];
                    }
                    n++;
                }
                m++;
            }
            treatedImage->pixel[i][j] = (int)(newPixelValue / 9);
        }
    }
}
void Laplacien(t_image *initImage, t_image *treatedImage) {
    treatedImage->height = initImage->height;
    treatedImage->width = initImage->width;
    treatedImage->greyLevel = initImage->greyLevel;

    createImage(treatedImage);

    int i, j, k, l, m, n, newPixelValue;
     int Laplacien[3][3] = {{0, 1, 0}, {1, -4, 1}, {0, 1, 0}};
    for (i = 0; i < initImage->height; i++) {
        for (j = 0; j < initImage->width; j++) {
            newPixelValue = 0;
            m = 0;
            for (k = i - 1; k <= i + 1; k++) {
                n = 0;
                for (l = j - 1; l <= j + 1; l++) {
                    if ((k >= 0 && k < initImage->height) && (l >= 0 && l < initImage->width)) {
                        newPixelValue += initImage->pixel[k][l] * Laplacien[m][n];
                    }
                    n++;
                }
                m++;
            }
            treatedImage->pixel[i][j] = (int)(newPixelValue / 9);
        }
    }
}
void Thresholding(t_image *initImage, t_image *treatedImage){
  treatedImage->height = initImage->height;
  treatedImage->width = initImage->width;
  treatedImage->greyLevel = initImage->greyLevel;

  createImage(treatedImage);

  int i, j,n;
  printf("Enter the no of Threshold");
  scanf("%d",&n);
  int b=n;
  for(;n>1;n--){
  for (i = 0; i < initImage->height; i++) {
        for (j = 0; j < initImage->width; j++) {

            if(initImage->pixel[i][j]>(n-1)*255/b)
				treatedImage->pixel[i][j]=(n-1)*255/b;
			else treatedImage->pixel[i][j]=0;
        }
      }
    }
}

void Luminosity(t_image *initImage, t_image *treatedImage){

    treatedImage->height = initImage->height;
  treatedImage->width = initImage->width;
  treatedImage->greyLevel = initImage->greyLevel;

  createImage(treatedImage);
  int i,j;
char lum[10];
    double perc;
    printf("Do you want to lighten or darken the image? (Lighten, Darken) \n");
    scanf("%s", lum);
    //lowerletter(lum);

    printf("Enter a percentage between 0 and 100 (without the %%) of how much you want\nthe luminosity to change by. \n");
    scanf("%lf", &perc);
    perc = 0.01* perc;


    if(strcmp(lum, "lighten") == 0){
        perc = 1.0 + perc;
        for (i = 0; i < initImage->height; i++) {
        for (j = 0; j < initImage->width; j++) {
                if(perc*initImage->pixel[i][j]<= 255){
                    treatedImage->pixel[i][j] = perc*initImage->pixel[i][j];
                }
                else{
                    treatedImage->pixel[i][j] = 255;
                }

        }
    }
  }

if(strcmp(lum, "darken") == 0){
        perc = 1.0 - perc;
        for (i = 0; i < initImage->height; i++) {
        for (j = 0; j < initImage->width; j++) {

                    treatedImage->pixel[i][j] = perc*initImage->pixel[i][j];
        }
    }
}
}

void Symmtery(t_image *initImage, t_image *treatedImage){
    treatedImage->height = initImage->height;
  treatedImage->width = initImage->width;
  treatedImage->greyLevel = initImage->greyLevel;

  createImage(treatedImage);
  int i,j;
  char direction[15];
  printf("what you want Horizontal or Vertical\n");
        scanf("%s", direction);

 if(strcmp(direction, "horizontal") == 0){

             for (i = 0; i < initImage->height; i++) {
        for (j = 0; j < initImage->width; j++) {
                treatedImage->pixel[i][j]=initImage->pixel[i][initImage->width-j];
                }
                }
 }

       if(strcmp(direction,"vertical") == 0){
                                for( i = 0; i < initImage->height; i++){
                                    for(j = 0; j < initImage->width; j++){
                    treatedImage->pixel[i][j] = initImage->pixel[initImage->height-i][j];
                }
            }

        }
    }

void Transformation(t_image *initImage, t_image *treatedImage){


  int i, j;
  //printf("how");
  //scanf("%d",&r);
 /* if(r==90){
         treatedImage->height = initImage->width;
  treatedImage->width = initImage->height;
  treatedImage->greyLevel = initImage->greyLevel;


  createImage(treatedImage);
  for (i = 0; i < initImage->height; i++) {
        for (j = 0; j < initImage->width; j++) {
           treatedImage->pixel[j][i] = initImage->pixel[i][j];

        }
  }
}*/

treatedImage->height = initImage->height;
  treatedImage->width = initImage->width;
  treatedImage->greyLevel = initImage->greyLevel;

  createImage(treatedImage);
for (i = 0; i< initImage->height ; i++) {
        for (j = 0; j < initImage->width; j++) {
                treatedImage->pixel[i][j]=initImage->pixel[i][j];
}
}
   }

void Sharpen(t_image *initImage , t_image *treatedImage){
    treatedImage->height = initImage->height;
    treatedImage->width = initImage->width;
    treatedImage->greyLevel = initImage->greyLevel;

    createImage(treatedImage);

    int i, j, k, l, m, n, newPixelValue;
    int sharpen[3][3] = {
        {0, -1,  0},
        {-1, 5, -1},
        {0, -1,  0}
    };
     //int Laplacien[3][3] = {{0, 1, 0}, {1, -4, 1}, {0, 1, 0}};
    for (i = 0; i < initImage->height; i++) {
        for (j = 0; j < initImage->width; j++) {
            newPixelValue = 0;
            m = 0;
            for (k = i - 1; k <= i + 1; k++) {
                n = 0;
                for (l = j - 1; l <= j + 1; l++) {
                    if ((k >= 0 && k < initImage->height) && (l >= 0 && l < initImage->width)) {
                        newPixelValue += initImage->pixel[k][l] * sharpen[m][n];
                    }
                    n++;
                }
                m++;
            }
            treatedImage->pixel[i][j] = (int)(newPixelValue / 9);
        }
    }
}
void edgedetection(t_image *initImage , t_image *treatedImage){
    treatedImage->height = initImage->height;
    treatedImage->width = initImage->width;
    treatedImage->greyLevel = initImage->greyLevel;

    createImage(treatedImage);

    int i, j, k, l, m, n, newPixelValue;

     int edgeDetect[3][3] = {
        {-1, -1, -1},
        {-1,  5, -1},
        {-1, -1, -1}
    };
    for (i = 0; i < initImage->height; i++) {
        for (j = 0; j < initImage->width; j++) {
            newPixelValue = 0;
            m = 0;
            for (k = i - 1; k <= i + 1; k++) {
                n = 0;
                for (l = j - 1; l <= j + 1; l++) {
                    if ((k >= 0 && k < initImage->height) && (l >= 0 && l < initImage->width)) {
                        newPixelValue += initImage->pixel[k][l] * edgeDetect[m][n];
                    }
                    n++;
                }
                m++;
            }
            treatedImage->pixel[i][j] = (int)(newPixelValue / 9);
        }
    }
}
void gaussian(t_image *initImage , t_image *treatedImage){
    treatedImage->height = initImage->height;
    treatedImage->width = initImage->width;
    treatedImage->greyLevel = initImage->greyLevel;

    createImage(treatedImage);

    int i, j, k, l, m, n, newPixelValue;

     int gaussian[3][3] = {
        {1, 2, 1},
        {2, 4, 2},
        {1, 2, 1}
    };
    for (i = 0; i < initImage->height; i++) {
        for (j = 0; j < initImage->width; j++) {
            newPixelValue = 0;
            m = 0;
            for (k = i - 1; k <= i + 1; k++) {
                n = 0;
                for (l = j - 1; l <= j + 1; l++) {
                    if ((k >= 0 && k < initImage->height) && (l >= 0 && l < initImage->width)) {
                        newPixelValue += initImage->pixel[k][l] * gaussian[m][n];
                    }
                    n++;
                }
                m++;
            }
            treatedImage->pixel[i][j] = (int)(newPixelValue / 9);
        }
    }
}
void BoxBlur(t_image *initImage , t_image *treatedImage){
    treatedImage->height = initImage->height;
    treatedImage->width = initImage->width;
    treatedImage->greyLevel = initImage->greyLevel;

    createImage(treatedImage);

    int i, j, k, l, m, n, newPixelValue;

      int boxBlur[3][3] = {
        { 1, 1, 1 },
        { 1,  1, 1 },
        { 1, 1, 1 }
    };
    for (i = 0; i < initImage->height; i++) {
        for (j = 0; j < initImage->width; j++) {
            newPixelValue = 0;
            m = 0;
            for (k = i - 1; k <= i + 1; k++) {
                n = 0;
                for (l = j - 1; l <= j + 1; l++) {
                    if ((k >= 0 && k < initImage->height) && (l >= 0 && l < initImage->width)) {
                        newPixelValue += initImage->pixel[k][l] * boxBlur[m][n];
                    }
                    n++;
                }
                m++;
            }
            treatedImage->pixel[i][j] = (int)(newPixelValue / 9);
        }
    }
}
void normalImage(t_image *initImage, t_image *treatedImage){
  treatedImage->height = initImage->height;
  treatedImage->width = initImage->width;
  treatedImage->greyLevel = initImage->greyLevel;

  createImage(treatedImage);

  int i, j;
  double max = -1;
  double min = 500;
  for (i = 0; i < initImage->height; i++) {
        for (j = 0; j < initImage->width; j++) {
            if(initImage->pixel[i][j]< min)
				min = initImage->pixel[i][j];
            if(initImage->pixel[i][j]> max)
                max = initImage->pixel[i][j];
        }
  }

  for (i = 0; i < initImage->height; i++) {
        for (j = 0; j < initImage->width; j++) {
            treatedImage->pixel[i][j] = (((double)initImage->pixel[i][j]-min)/(max-min))*initImage->greyLevel;
        }
  }
}

