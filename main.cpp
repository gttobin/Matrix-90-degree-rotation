#include "EasyBMP.hpp"
#include "bitmap.h"
#include <string>



using namespace std;
using namespace EasyBMP;





int* rotate(int* in,int height,int width){

int n =height;
int m = width;
int** input=new int*[height];
for(int i=0;i<height;i++)
{
       input[i]=new int[width];
}


for(int i=0;i<height;i++)
{
   for(int j=0;j<width;j++)
   {
   input[i][j]=in[i*width+j];
   }
}


if(n>m)
{
int* output = new int[m*n];


int** temp = new int*[n];
for(int i=0;i<n;i++)
{
     temp[i]=new int[n];
}

for (int i=0; i<n; i++)
{
	for (int j=0;j<m; j++)
    {
		temp[j][n-1-i] = input[i][j];
    }
}

for(int i=(n-m)/2;i<n-((n-m)/2);i++)
{
    for(int j=0;j<n;j++)
    {
        output[(i-((n-m)/2))*n+j]=temp[i-((n-m)/2)][j];
    }
}
    return output;
}

if(m>n)
{
int* output = new int[n*m];


int** temp = new int*[m];
for(int i=0;i<m;i++)
{
     temp[i]=new int[m];
}

for (int i=0; i<n; i++)
{
	for (int j=0;j<m; j++)
    {
		temp[j][n-1-i] = input[i][j];

    }
}

for(int i=0;i<m;i++)
{
    for(int j=0;j<n;j++)
    {
      //  output[(i-((m-n)/m))*n+j]=temp[i][j];
        output[(i-((m-n)/m))*n+j]=temp[i][j];
    }
}

    return output;
}


}






int main()
{


		  Bitmap image;
		  image.open("IMG_7.bmp");
		  int height=image.getHeight();
		  int width=image.getWidth();







            RGBColor bl(0, 0, 0);

            Image blank(height, width, "blank.bmp", bl);

            blank.Write();

            Bitmap img;
            img.open("blank.bmp");


            int* original=image.toIntMatrix();

            int* rotated=new int[height*width];


            rotated=rotate(original,height,width);



             img.intToPixels(rotated,width,height);
             img.save( "rotated.bmp");








}
