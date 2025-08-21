#include "../../include/utils/Misc.hpp"

using namespace std;
vector<vector<double>> utils::Misc::fetchData(string path) {
    vector<vector<double>> data;
    ifstream in(path);
    if (!in.is_open()) return data;

    string line;
    bool firstLine = true;
    while (std::getline(in, line)) {
        if (firstLine) {
            firstLine = false;
            bool hasNonDigit = false;
            for (char c : line) {
                if (!(std::isdigit(c) || c == ',' || c == ' ')) {
                    hasNonDigit = true;
                    break;
                }
            }
            if (hasNonDigit) continue;
        }
        // Parse numeric row
        stringstream ss(line);
        string token;
        vector<double> row;
        while (std::getline(ss, token, ',')) {
            row.push_back(std::stod(token));
        }
        data.push_back(row);
    }
    return data;
}
