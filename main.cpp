#include <iostream>
#include "Color.h"

int main() {
    const int max_width = 256;
    const int max_height = 256;

    std::cout << "P3\n" << max_width << " " << max_height << "\n255\n";
    for(int j = max_height - 1; j > 0; --j) {
        std::cerr << "\nProgress: " << (max_height - j - 1) * 100/ max_height << '%' << std::flush;
        for(int i = 0; i < max_width; ++i) {
            Color color(double(i) / (max_height - 1), double(j) / (max_width - 1), 0.25);
            write_color(std::cout, color);
        }
    }
    std::cerr << "\nDone.\n";
}
