#ifndef CSVREADER_H
#define CSVREADER_H
#include <fstream>
#include <string>
#include <boost/algorithm/string.hpp>
#include <vector>
#include <iostream>

class CSVReader
{
    public:
        CSVReader(const std::string & filename, std::string delimiter); ///initialization
        ~CSVReader(); ///End
        void reader(); ///Upload the file
        std::vector<std::vector<std::string >> getData(); ///Extraction of the data
        void visualize(int header) ; /// Not necessary, but usefull
        std::vector<int>  VecOfStringIntoVecOfInt(int header) ; ///Not necessary, but usefull


    protected:
    private:
     std::string _filename ; ///The file to upload
     std::string _delimiter; ///self explanatory
     std::vector<std::string> _field ; ///each line of the file to read
     std::vector<std::vector<std::string >> _dataList; /// self explanatory
     std::ifstream _inputFile ; ///to upload the file
     std::vector<int> _numberPixel; /// Not necessary, but usefull
    int _sizeOfEachLine ;/// Not necessary, but usefull
    std::vector<int> _intNumbers;/// Not necessary, but usefull

};

#endif // CSVREADER_H
