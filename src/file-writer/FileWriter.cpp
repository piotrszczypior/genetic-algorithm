#include "FileWriter.h"

void FileWriter::write_to_file(std::string file_name, int cost, const std::vector<int>& path) {
    std::string dir = "results/";
    file_name += +".txt";
    dir += file_name;

    std::ofstream file;
    file.open(dir, std::ios::in | std::ios::app);
    file << cost << " -- ";
    for (auto city : path) {
        file << city << ' ';
    }
    file << '\n';
    file.close();
}
