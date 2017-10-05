#include <iostream>
#include <vector>
#include <string>
#include "bitmap.h"
#include <cmath>
using namespace std;

int main()
{
Bitmap image;
vector <vector <Pixel> > bmp;
Pixel rgb;
string fileName;

      //read a file example.bmp and convert it to a pixel matrix
cout << "Please enter the file name. \n";
cin >> fileName;

image.open(fileName);
bmp = image.toPixelMatrix();

cout << fileName << " has been loaded." << " It is " << bmp.size() <<" pixels high ";
cout << "and " << bmp[0].size() << " pixels wide. "<< endl;

 int r;
 int g;
 int b;
 int grey;


  for(int i = 0; i < bmp.size(); i++)
  {

    for(int j = 0; j < bmp[i].size(); j++)
    {
      r = bmp[i][j].red;
      g = bmp[i][j].green;
      b = bmp[i][j].blue;

      rgb = bmp[i][j];

      grey = (r+g+b)/3;

      rgb.red = grey;
      rgb.green = grey;
      rgb.blue = grey;

       //machupicchu.bmp
      bmp[i][j] = rgb;

    }
  }
  //update the bitmap and save it

image.fromPixelMatrix(bmp);

image.save("oldTimey.bmp");
cout << "end";

return 0;
}
