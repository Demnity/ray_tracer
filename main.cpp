#include <iostream>

int main() {
    const int max_width = 256;
    const int max_height = 256;

    std::cout << "P3\n" << max_width << " " << max_height << "\n255\n";
    for(int j = max_height - 1; j > 0; --j) {
        std::cerr << "\nProgress: " << (max_height - j - 1) * 100/ max_height << '%' << std::flush;
        for(int i = 0; i < max_width; ++i) {
            double r = double(i) / (max_height - 1);
            double g = double(j) / (max_width - 1);
            double b = 0.25;

            int ir = static_cast<int>(255.999 * r);
            int ig = static_cast<int>(255.999 * g);
            int ib = static_cast<int>(255.999 * b);

            std::cout << ir << " " << ig << " " << ib << '\n';
        }
    }
    std::cerr << "\nDone.\n";
}
