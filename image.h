#ifndef IMAGE_H_INCLUDED
#define IMAGE_H_INCLUDED

typedef struct image {

    int width;
    int height;
    int greyLevel;

    // Suppose the 2D Array to be converted to Image is as given below
    int **pixel;
}t_image;


void saveImage(const char * fileName, t_image *im);
void loadImage (const char * fileName, t_image *im);
void createImage(t_image *im);

#endif // IMAGE_H_INCLUDED

