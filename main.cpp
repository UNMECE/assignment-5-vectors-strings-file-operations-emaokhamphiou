#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>

struct Pixel {
    float r, g, b;
    int x, y;
};

std::vector<Pixel> pixel_list;

void average_colors(std::vector<Pixel>& pixels) {
    float sum_r = 0, sum_g = 0, sum_b = 0;
    for (const auto& p : pixels) {
        sum_r += p.r;
        sum_g += p.g;
        sum_b += p.b;
    }
    int count = pixels.size();
    std::cout << "Average R: " << sum_r / count << std::endl;
    std::cout << "Average G: " << sum_g / count << std::endl;
    std::cout << "Average B: " << sum_b / count << std::endl;
}

void flip_vertically(std::vector<Pixel>& pixels) {
    for (auto& p : pixels) {
        p.y = 255 - p.y;
    }
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cout << "Usage: " << argv[0] << " <input_file>" << std::endl;
        return 1;
    }

    std::ifstream infile(argv[1]);
    std::string line;
    while (std::getline(infile, line)) {
        std::istringstream iss(line);
        Pixel p;
        char comma;
        iss >> p.x >> comma >> p.y >> comma >> p.r >> comma >> p.g >> comma >> p.b;
        pixel_list.push_back(p);
    }

    average_colors(pixel_list);
    flip_vertically(pixel_list);

    std::ofstream outfile("flipped.dat");
    for (const auto& p : pixel_list) {
        outfile << p.x << "," << p.y << "," << p.r << "," << p.g << "," << p.b << std::endl;
    }

    return 0;
}
