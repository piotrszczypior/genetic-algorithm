#ifndef LIST_FILEWRITER_H
#define LIST_FILEWRITER_H

#include <string>
#include <fstream>
#include <iostream>
#include <vector>

class FileWriter {

public:
    static void write_to_file(std::string file_name, int cost, const std::vector<int>& path);
};


#endif //LIST_FILEWRITER_H
