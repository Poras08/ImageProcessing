#include <stdio.h>
#include <stdlib.h>

#include"traitement.h"
int menu1();
int menu2();
int main()
{
   t_image initImage;
   t_image treatedImage;



   int choix1, choix2;
     choix1= menu1();
    switch(choix1)
    {
         case 1: loadImage("initFileImage.pgm", &initImage);
                  break;

         default : exit(0);

    }
     choix2= menu2();

        switch(choix2) {
            case 1:
                binarizeImage(&initImage, &treatedImage);
                break;
            case 2:
                negatifImage(&initImage, &treatedImage);
                break;
            case 3:
                convolution(&initImage, &treatedImage);
                break;
            case 4:
                Laplacien(&initImage, &treatedImage);
                break;
            case 5 :      Thresholding(&initImage, &treatedImage);
                          break;
            case 6 : Luminosity(&initImage, &treatedImage);
                     break;
            case 7 : Transformation(&initImage, &treatedImage);
                     break;
           case 8 : Symmtery(&initImage, &treatedImage);
                     break;
             case 9: edgedetection(&initImage, &treatedImage);
                       break;
              case 10: Sharpen(&initImage,&treatedImage);
                        break;
            case 11:   gaussian(&initImage,&treatedImage);
                        break;
            case 12:   BoxBlur(&initImage,&treatedImage);
                        break;
            case 13 : normalImage(&initImage,&treatedImage);
                        break;
            default : exit(0);
        }
        saveImage("treatedFileImage.pgm", &treatedImage);
        system("COLOR 2");
        printf("Operation reussie !\n");

   return 0;
}

int menu1()
{
    int a;
system("COLOR 4");
    printf("1) Entrer dans le programme \n2) EXIT \n Enter your choice:-");
    scanf("%d",&a);
    return a;
}
int menu2()
{
    int b;
    system("COLOR 4");
    printf(" 1) Binariser\n 2) Negatif\n 3) Convolution\n 4) Laplacien\n 5)Thresholding\n 6)Luminosity\n 7)Transformation\n 8)Symmetry\n 9)EdgeDetection\n 10) Sharpening\n 11)Gaussian Filter\n 12)BoxBlur\n 13)Normalization \nEnter your choise:- ");
    scanf("%d",&b);
        return b;
}

