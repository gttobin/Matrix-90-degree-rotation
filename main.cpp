#include "EasyBMP.hpp"
#include "bitmap.h"
#include <string>



using namespace std;
using namespace EasyBMP;





int* rotate(int* in,int height,int width){

int n =height;
int m = width;
int** input=new int*[n];
for(int i=0;i<n;i++)
{
       input[i]=new int[m];
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
    for(int i = 0; i < n; i++)
    {
        delete input[i];//delete the A object allocations.
    }
    for(int i = 0; i < n; i++)
    {
        delete temp[i];//delete the A object allocations.
    }
    delete[] input;
    delete[] temp;

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
    for(int i = 0; i < n; i++)
    {
        delete input[i];//delete the A object allocations.
    }
    for(int i = 0; i < m; i++)
    {
        delete temp[i];//delete the A object allocations.
    }
    delete[] input;
    delete[] temp;

    return output;
}


if(m==n)
{
int* output = new int[n*m];

for(int i=0;i<m/2;i++)
{
    for(int j=i;j<n-i-1;j++)
    {
      int temp = input[i][j];

            // Move values from right to top
            input[i][j] = input[j][n - 1 - i];

            // Move values from bottom to right
            input[j][n - 1 - i]
                = input[n - 1 - i][n - 1 - j];

            // Move values from left to bottom
            input[n - 1 - i][n - 1 - j]
                = input[n - 1 - j][i];

            // Assign temp to left
            input[n - 1 - j][i] = temp;
    }
}
for(int i=0;i<n;i++)
{
    for(int j=0;j<n;j++)
    {
        output[i*n+j]=input[i][j];
    }
}
    for(int i = 0; i < n; i++)
    {
        delete input[i];//delete the A object allocations.
    }

    delete[] input;


    return output;
}

}






int main()
{

            //Create an bitmap image object
            Bitmap image;
            image.open("IMG_11.bmp");
            int height=image.getHeight();
            int width=image.getWidth();

            //These lines create a blank BMP file for writing to after rotation
            RGBColor bl(0, 0, 0);

            Image blank(height, width, "blank.bmp", bl);
            blank.Write();

            //Open the blank image
            Bitmap img;
            img.open("blank.bmp");


            //Extract the RGB array from the Bimamp object
            int* original=image.toIntMatrix();
            //Create an empty array to hold the rotated RGB array
            int* rotated=new int[height*width];

            //Rotate
            rotated=rotate(original,height,width);


             //Convert the RGB array to pixels and save
             img.intToPixels(rotated,width,height);
             img.save( "rotated.bmp");


}
