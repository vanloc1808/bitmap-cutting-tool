#include <algorithm>
#include "Bitmap.hpp"

void initRGBArray(RBG*** arr, int row, int col) {
    *arr = (RBG**)calloc(row, sizeof(RBG*));

    for (int i = 0; i < row; i++) {
        (*arr)[i] = (RBG*)calloc(col, sizeof(RBG));
    }
}

void cutBitmap(char* fileName, int col, int row) {
    FILE* file = fopen(fileName, "rb");

    Header header;
    fread(&header, sizeof(Header), 1, file);

    HeaderInfo info;
    fread(&info, sizeof(HeaderInfo), 1, file);

    fseek(file, header.dataOffset, SEEK_SET);

    int height = info.height;
    int width = info.width;

    RBG** array = nullptr;

    initRGBArray(&array, height, width);

    int offset = (3 * width) % 4;

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            fread(&array[i][j], sizeof(RBG), 1, file);
        }

        fseek(file, offset, SEEK_CUR);
    }

    int rowSize = height / row;
    int colSize = width / col;

    int c = 1;
    char name[12];

    for (int i = row - 1; i >= 0; i--) {
        for (int j = 0; j < col; j++) {
            sprintf(name, "%d.bmp", c++);
            FILE* fw = fopen(name, "wb");

            int newHeight = std::min((i + 1) * rowSize, height) - i * rowSize;
            int newWidth = std::min((j + 1) * colSize, width) - j * colSize;

            info.height = newHeight;
            info.width = newWidth;

            header.bitmapSize = 54 + 3 * newHeight * newWidth;

            fwrite(&header, sizeof(Header), 1, fw);
            fwrite(&info, sizeof(HeaderInfo), 1, fw);

            offset = (3 * newWidth) % 4;
            char n = 0;

            for (int k = i * rowSize; k < newHeight + i * rowSize; k++) {
                for (int l = j * colSize; l < newWidth + j * colSize; l++) {
                    fwrite(&array[k][l], sizeof(RBG), 1, fw);
                }

                for (int m = 0; m < offset; m++) {
                    fwrite(&n, sizeof(char), 1, fw);
                }
            }
            
            fclose(fw);
        }
    }

    fclose(file);
}