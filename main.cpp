#include <iostream>
#include <vector>
#include <string>
#include "bitmap.h"
#include <cmath>
#include <ctime>
using namespace std;

 //machupicchu.bmp
int main()
{
Bitmap image;
vector <vector <Pixel> > bmp;
Pixel rgb;
string fileName;
char grain;
bool validBmp;
srand ( time(NULL) );
int greyOffset=25;

//  cout <<'\v'<<"This file can not be read."<<endl;
//  cout << "The file must be an accesible 24 bit depth Windows BMP file." << endl;

//read a file example.bmp and convert it to a pixel matrix
do
{
  cout << "Please enter the file name. \n";
  cin >> fileName;
  image.open(fileName);
  validBmp = image.isImage();
  if (validBmp == false)//tells you if you funked up
  {
    cout <<'\v'<<"This file can not be read."<<endl;
    cout << "The file must be an accesible 24 bit depth Windows BMP file." << endl;
  }
}
while(validBmp == false );


if( validBmp == true )
 {
   bmp = image.toPixelMatrix();


//random num film grain works
cout <<"Would you like to add film grain? (Y)es, (N)o " <<endl;
cin >> grain;
int randomNum;

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

      if (grain=='y' || grain=='Y')//adds film grain
      {
        randomNum = rand() % 60;
        grey = grey-randomNum;
        grey=grey+greyOffset;// greyOffset
      }
      if(grey<0)
      {
        grey=0;
      }
      if(grey>255)
      {
        grey=255;
      }

      rgb.red = grey;
      rgb.green = grey;
      rgb.blue = grey;


      bmp[i][j] = rgb;


    }
  }
  //update the bitmap and save it

  cout << "It is " << bmp.size() <<" pixels high ";
  cout << "and " << bmp[0].size() << " pixels wide. "<< endl;

image.fromPixelMatrix(bmp);

image.save("oldTimey.bmp");
cout << "end";
}

return 0;
}
