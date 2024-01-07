#include "FileWriter.h"

void FileWriter::write_to_file(std::string file_name, const std::vector<int>& path) {
    file_name += +".txt";

    std::cout << "Writing to: " << file_name << std::endl;

    std::ofstream file;
    file.open(file_name, std::ios::in | std::ios::app);

    for (auto city : path) {
        file << city << ' ';
    }
    file.close();
}
