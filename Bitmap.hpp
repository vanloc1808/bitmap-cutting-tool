#include <iostream>
#include <cstdint>
#include <cstdlib>
#include <string.h>

#pragma pack(1)

struct Header {
    uint16_t bitmapType = 19778; // const

    uint32_t bitmapSize = 54 + 800 * 600 * 3; 

    uint16_t bitmapRes1 = 0; // const

    uint16_t bitmapRes2 = 0; // const

    uint32_t dataOffset = 54;
};

struct HeaderInfo {
    uint32_t size = 40; // size of BITMAPINFOHEADER structure

    uint32_t width = 800; // width of image in pixels

    uint32_t height = 600; // height of image in pixels

    uint16_t planes = 1; // number of color planes 

    uint16_t bitCount = 24; // number of bits per pixel

    uint32_t compression = 0; // compression method being used

    uint32_t sizeImage = 0; // image size in bytes

    uint32_t xPixelsPerMeter = 0; // horizontal resolution of image

    uint32_t yPixelsPerMeter = 0; // vertical resolution of image

    uint32_t colorsUsed = 0; // number of colors in image

    uint32_t colorsImportant = 0; // number of important colors
};

struct RBG {
    uint8_t blue;
    uint8_t green;
    uint8_t red;
};

void initRGBArray(RBG*** arr, int row, int col);

void cutBitmap(char* fileName, int col, int row);