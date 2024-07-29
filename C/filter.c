#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    float newValue;

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            newValue = (image[i][j].rgbtBlue + image[i][j].rgbtGreen + image[i][j].rgbtRed) / 3.0;
            image[i][j].rgbtBlue = roundf(newValue);
            image[i][j].rgbtGreen = roundf(newValue);
            image[i][j].rgbtRed = roundf(newValue);
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE temp;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width / 2; j++)
        {
            temp = image[i][j];
            image[i][j] = image[i][width - j - 1];
            image[i][width - j - 1] = temp;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE imageR[height][width];
    float pcount;
    float newValueB;
    float newValueG;
    float newValueR;

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            pcount = 0;
            newValueB = 0;
            newValueG = 0;
            newValueR = 0;

            for (int k = i - 1; k < i + 2; k++)
            {
                for (int l = j - 1; l < j + 2; l++)
                {
                    if (k >= 0 && l >= 0 && k < height && l < width)
                    {
                        newValueB += image[k][l].rgbtBlue;
                        newValueG += image[k][l].rgbtGreen;
                        newValueR += image[k][l].rgbtRed;
                        pcount++;
                    }
                }
            }

            newValueB = newValueB / pcount;
            newValueG = newValueG / pcount;
            newValueR = newValueR / pcount;

            imageR[i][j].rgbtBlue = roundf(newValueB);
            imageR[i][j].rgbtGreen = roundf(newValueG);
            imageR[i][j].rgbtRed = roundf(newValueR);
        }
    }

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j].rgbtBlue = imageR[i][j].rgbtBlue;
            image[i][j].rgbtGreen = imageR[i][j].rgbtGreen;
            image[i][j].rgbtRed = imageR[i][j].rgbtRed;
        }
    }
    return;
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    int Gx[3][3] = {{-1, 0, 1}, {-2, 0, 2}, {-1, 0, 1}};

    int Gy[3][3] = {{-1, -2, -1}, {0, 0, 0}, {1, 2, 1}};

    int x, y;

    RGBTRIPLE imageR[height][width];
    // float pcount;
    float GxValueB;
    float GxValueG;
    float GxValueR;
    float GyValueB;
    float GyValueG;
    float GyValueR;

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // pcount = 0;
            GxValueB = 0;
            GxValueG = 0;
            GxValueR = 0;
            GyValueB = 0;
            GyValueG = 0;
            GyValueR = 0;

            x = 0;
            for (int k = i - 1; k < i + 2; k++)
            {
                y = 0;
                for (int l = j - 1; l < j + 2; l++)
                {
                    if (k >= 0 && l >= 0 && k < height && l < width)
                    {
                        GxValueB += image[k][l].rgbtBlue * Gx[x][y];
                        GyValueB += image[k][l].rgbtBlue * Gy[x][y];

                        GxValueG += image[k][l].rgbtGreen * Gx[x][y];
                        GyValueG += image[k][l].rgbtGreen * Gy[x][y];

                        GxValueR += image[k][l].rgbtRed * Gx[x][y];
                        GyValueR += image[k][l].rgbtRed * Gy[x][y];

                        // pcount++;
                    }
                    y++;
                }
                x++;
            }

            imageR[i][j].rgbtBlue = (round(sqrt(GxValueB * GxValueB + GyValueB * GyValueB)) > 255)
                                        ? 255
                                        : round(sqrt(GxValueB * GxValueB + GyValueB * GyValueB));
            imageR[i][j].rgbtGreen = (round(sqrt(GxValueG * GxValueG + GyValueG * GyValueG)) > 255)
                                         ? 255
                                         : round(sqrt(GxValueG * GxValueG + GyValueG * GyValueG));
            imageR[i][j].rgbtRed = (round(sqrt(GxValueR * GxValueR + GyValueR * GyValueR)) > 255)
                                       ? 255
                                       : round(sqrt(GxValueR * GxValueR + GyValueR * GyValueR));
        }
    }

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j].rgbtBlue = imageR[i][j].rgbtBlue;
            image[i][j].rgbtGreen = imageR[i][j].rgbtGreen;
            image[i][j].rgbtRed = imageR[i][j].rgbtRed;
        }
    }
    return;
}