#ifndef JSONPARSER_H
#define JSONPARSER_H
#include <string>
#include <tuple>
using namespace std;

class JsonParser{
    public:
    tuple<string,int, int> GetWord(string path);

};

#endif