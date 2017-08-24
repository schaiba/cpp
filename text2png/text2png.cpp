#include <stdlib.h>
#include <pngwriter.h>
#include <iostream>
#include <fstream>
#include <string>
int main(int argc, char * argv[])
{
    if (argc < 6)
    {
        std::cout << "Please provide the text and the output file, as well as the desired size of the resulting PNG file and the text size!" << std::endl;
        exit(1);
    }
    char* message = argv[1];

   double gradstart=0.0;
   double gradend=0.0;
   
   //Creating the PNGwriter instance
   pngwriter image(std::stoi(argv[3]),std::stoi(argv[4]),1.0,argv[2]);

   //Creating the background gradient
   for(int h=1;h<=1000;h++)
     {
	image.line(h,1,h,1000,1.0 -(gradend - gradstart)*h/1000, 1.0 -(gradend - gradstart)*h/1000, 1.0);
     }
	  
   image.plot_text("/usr/share/texlive/texmf-dist/fonts/truetype/public/gentium-tug/GentiumPlus-I.ttf",std::stoi(argv[5]),20,20,0.0, message,1.0,0.12,0.0);

   image.close();
   return 0;
}

