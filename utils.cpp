#include <fstream>
#include <sstream>
#include "utils.h"
#include <netinet/in.h>
#include <cstring>
#include <regex>

using namespace std;
namespace utils {
    string readFile(const string &path) {
        ifstream fin(path);
        if (!fin.is_open()) throw runtime_error("file not  open");
       stringstream out;
        out << fin.rdbuf();
        return out.str();
    }

    // Read a csv file and return a matrix of its lines
   vector<vector<string>> readCSV(const std::string &path) {
        string csv = readFile(path);
        vector<vector<string>> data;

        for (const auto &line: split(csv, '\n')) {
            stringstream ss(line);

            vector<string> row = split(line, ',');
            if (!row.empty())
                data.push_back(row);
        }

        return data;
    }

    // Write to a csv file
    void writeFile(const string &path, const string &content) {
        ofstream fout(path);
        fout << content;
    }

   vector<string> split(const string &s, const char c) {
       stringstream ss(s);
        string cell;

        vector<string> v;
        while (getline(ss, cell, c)) {
            v.push_back(cell);
        }
        return v;
    }

    //Receive from the socket
   string recv(int sock) {
        string msg;
         string ending = "<end>";
        //Read until ending is detected
        char buffer[1];
        while (!std::equal(ending.rbegin(), ending.rend(), msg.rbegin())) {
            buffer[0] = 0;
            ssize_t read_bytes = ::recv(sock, buffer, 1, 0);
            if (read_bytes < 0) {
                perror("error writing to sock");
            }
            msg.append(buffer);
        }
        return msg.substr(0, msg.length() - 5);
    }

    void send(int sock, const std::string &string) {
        std::string msg = string + "<end>";

        size_t sent_bytes = ::send(sock, msg.c_str(), strlen(msg.c_str()), 0);
        if (sent_bytes < 0) {
            perror("error sending to client");
        }
    }
}