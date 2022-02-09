#include "Bitmap.hpp"

int main(int argc, char** argv) {
    if (argc != 4 && argc != 6) {
        std::cout << "Wrong argument!\n";

        return 1;
    }

    int w = 1, h = 1;

    if (argc == 6) {
        if (strcmp(argv[2], "-h") == 0 && strcmp(argv[4], "-w") == 0) {
            h = atoi(argv[3]);
            w = atoi(argv[5]);
        } else if (strcmp(argv[2], "-w") == 0 && strcmp(argv[4], "-h") == 0) {
            w = atoi(argv[3]);
            h = atoi(argv[5]);
        } else {
            std::cout << "Wrong argument!\n";

            return 1;
        }
    } else {
        if (strcmp(argv[2], "-h") == 0) {
            h = atoi(argv[3]);
        } else if (strcmp(argv[2], "-w") == 0) {
            w = atoi(argv[3]);
        } else {
            std::cout << "Wrong argument!\n";

            return 1;
        }
    }

    cutBitmap(argv[1], w, h);

    return 0;
}