#ifndef TRAITEMENT_H_INCLUDED
#define TRAITEMENT_H_INCLUDED

#include"image.h"


void binarizeImage(t_image * initImage, t_image * treatedImage);
void negatifImage(t_image * initImage, t_image * treatedImage);

void convolution(t_image * initImage, t_image * treatedImage);

void Laplacien(t_image *initImage, t_image *treatedImage);
void Thresholding(t_image *initImage, t_image *treatedImage);
void Luminosity(t_image *initImage, t_image *treatedImage);
void Transformation(t_image *initImage, t_image *treatedImage);
void Symmtery(t_image *initImage, t_image *treatedImage);
void edgedetection(t_image *initImage, t_image *treatedImage);
void Sharpen(t_image *initImage, t_image *treatedImage);
void gaussian(t_image *initImage, t_image *treatedImage);
void BoxBlur(t_image *initImage, t_image *treatedImage);
void normalImage(t_image *initImage, t_image *treatedImage);
#endif // TRAITEMENT_H_INCLUDED

