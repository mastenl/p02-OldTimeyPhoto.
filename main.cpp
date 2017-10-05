#include <iostream>
#include <vector>
#include <string>
#include "bitmap.h"

using namespace std;

int main()
{
Bitmap image;
vector <vector <Pixel> > pic;
Pixel rgb;
string fileName;

      //read a file example.bmp and convert it to a pixel matrix
cout << "Please enter the file name. \n";
cin >> fileName;

image.open(fileName);
pic = image.toPixelMatrix();

cout << fileName << " has been loaded." << " It is " << pic.size() <<" pixels high ";
cout << "and " << pic[0].size() << " pixels wide. "<< endl;

//take all the redness out of the top-left pixel
//rgb = pic[0][0];
//rgb.red = 0;

  //update the bitmap and save it
//pic[0][0] = rgb;
//image.fromPixelMatrix(pic);
//image.save("fileName");

return 0;
}
