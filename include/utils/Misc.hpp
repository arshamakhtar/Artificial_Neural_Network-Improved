#ifndef _MISC_HPP_
#define _MISC_HPP_

#include <string>
#include <vector>
#include <fstream>      // for std::ifstream
#include <sstream>      // for std::stringstream
#include <string>       // for std::string
#include <cctype>       // for std::isdigit


using std::ifstream;
using std::stringstream;
using std::string;
using std::vector;

namespace utils {
    class Misc {
    public:
        static std::vector<std::vector<double>> fetchData(std::string path);
    };
}

#endif
