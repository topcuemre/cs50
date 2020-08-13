#include "helpers.h"
#include <math.h>
#include <stdbool.h>
// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    int avg;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            
            avg = round(( image[i][j].rgbtBlue +  image[i][j].rgbtRed +  image[i][j].rgbtGreen) / 3.0);
            image[i][j].rgbtBlue = avg;
            image[i][j].rgbtRed = avg;
            image[i][j].rgbtGreen = avg;
            
        }
    }
    return;
}

int det(int val)
{
    return val > 255 ? 255 : val;
}
// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    int r,g,b;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            RGBTRIPLE a = image[i][j];
            int originalRed = a.rgbtRed;
            int originalGreen = a.rgbtGreen;
            int originalBlue = a.rgbtBlue;
            image[i][j].rgbtRed = det(round(0.393 * originalRed + 0.769 * originalGreen + 0.189 * originalBlue));
            image[i][j].rgbtGreen = det(round(0.349 * originalRed + 0.686 * originalGreen + 0.168 * originalBlue));
            image[i][j].rgbtBlue = det(round(0.272 * originalRed + 0.534 * originalGreen + 0.131 * originalBlue));
            
            
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    int a, b, c;
    for (int i = 0; i < height; i++)
    { 
        for (int j = 0; j < width / 2; j++)
        {
            a = image[i][j].rgbtRed;
            b = image[i][j].rgbtBlue; 
            c = image[i][j].rgbtGreen;
            image[i][j].rgbtRed = image[i][width - 1 - j].rgbtRed;
            image[i][width - 1 - j].rgbtRed = a;
            
            image[i][j].rgbtBlue = image[i][width - 1 - j].rgbtBlue;
            image[i][width - 1 - j].rgbtBlue = b;
            
            image[i][j].rgbtGreen = image[i][width - 1 - j].rgbtGreen;
            image[i][width - 1 - j].rgbtGreen = c;
            
            
        }
    }
    return;
}
//this example is definitely helped me to learn more about pointers!!! :) 8/13/2020 5.41PM. I would be happy to see this message after a long time İf it can return back to me somehow in the future 
 
bool adj(int i,int j ,int height,int width)
{
    return i >= 0 && i < height && j >=0 && j < width;
}

RGBTRIPLE blurr(int i,int j,int height,int width,RGBTRIPLE image[height][width])
{
    int redval,blueval,greenval;
    redval = blueval = greenval = 0;
    int adjcells = 0;
    for (int ii = -1;ii <= 1; ii++)
    {
        for (int jj = -1;jj <= 1; jj++)
        {
            int k = i + ii;
            int l = j + jj;
            if(adj(k , l , height , width))
            {
                adjcells++;
                redval += image[ii][jj].rgbtRed;
                blueval += image[ii][jj].rgbtBlue;
                greenval += image[ii][jj].rgbtGreen;
            }
        } 
    }
    RGBTRIPLE blurred;
    blurred.rgbtRed = round((float)redval / adjcells);
    blurred.rgbtGreen = round((float)greenval / adjcells);
    blurred.rgbtBlue = round((float)blueval / adjcells);
    return blurred;
}
// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE cell[height][width];
    for (int i = 0; i < height; i++)
    { 
        for (int j = 0; j < width; j++)
        {
            cell[i][j] = blurr(i, j, height, width, image);
        }
    }
    
    for (int i = 0; i < height; i++)
        for ( int j = 0; j < width; j++)
            image[i][j] = cell[i][j];
}
