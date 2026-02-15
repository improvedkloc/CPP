#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

static std::string replaceAll(const std::string &content, const std::string &s1,
                              const std::string &s2) {
    std::string result;
    std::size_t pos = 0;
    std::size_t found;

    if (s1.empty())
        return content;
    while ((found = content.find(s1, pos)) != std::string::npos) {
        result.append(content, pos, found - pos);
        result += s2;
        pos = found + s1.length();
    }
    result.append(content, pos, std::string::npos);
    return result;
}

int main(int argc, char **argv) {
    if (argc != 4) {
        std::cerr << "Usage: " << argv[0] << " <filename> <s1> <s2>" << std::endl;
        return 1;
    }

    const std::string filename = argv[1];
    const std::string s1 = argv[2];
    const std::string s2 = argv[3];

    if (s1.empty()) {
        std::cerr << "Error: s1 must not be empty" << std::endl;
        return 1;
    }

    std::ifstream input(filename.c_str());
    if (!input) {
        std::cerr << "Error: could not open input file" << std::endl;
        return 1;
    }

    std::ostringstream buffer;
    buffer << input.rdbuf();
    if (input.bad()) {
        std::cerr << "Error: failed while reading input file" << std::endl;
        return 1;
    }

    const std::string outputName = filename + ".replace";
    std::ofstream output(outputName.c_str());
    if (!output) {
        std::cerr << "Error: could not open output file" << std::endl;
        return 1;
    }

    output << replaceAll(buffer.str(), s1, s2);
    if (!output) {
        std::cerr << "Error: failed while writing output file" << std::endl;
        return 1;
    }

    return 0;
}
