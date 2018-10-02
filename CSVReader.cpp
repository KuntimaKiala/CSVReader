#include "CSVReader.h"

CSVReader::CSVReader(const std::string & filename, std::string delimiter)

{

    _filename = filename ; ///The file to read
    _delimiter =delimiter; /// the delimiter given by the user
    _field ={""}; /// field, for more explanation go to http://www.cplusplus.com
    reader() ;///Calling the function to open the file
}

CSVReader::~CSVReader()
{
    _inputFile.close() ;
}


void CSVReader::reader(){


    _inputFile.open(_filename); ///Open the file

    if(_inputFile.fail()) { ///in case it fails opening

        std::cerr<<"Oops, something went wrong" << std::endl ;
        return;

    } else {
        std::cerr<<"Ready to get the file" << std::endl ;
        getData() ; ///The function that will extract the data into vector that contain vector of strings
    }


}


std::vector<std::vector<std::string >> CSVReader:: getData(){

    std::cout<<"Uploading the file" << std::endl ; /// comment
    std::string EachLineInTheCSVFILE =""; /// the variable that will store each line of the file
    while(getline(_inputFile, EachLineInTheCSVFILE)){ ///loop untill the last line


    boost::split(_field, EachLineInTheCSVFILE, boost::is_any_of(_delimiter)) ; /// to split the data according the delimiter
    _dataList.emplace_back(_field); ///appending all the vector of strings in the vector of vector of strings



    }
     std::cout<<"File Uploaded" << std::endl ;/// comment

    _sizeOfEachLine = _field.size() ; /// Not necessary, but usefull

    std::cout<< "size "<< _sizeOfEachLine <<std::endl; /// Not necessary, but usefull
    return _dataList ; ///the data itself

}


void  CSVReader::visualize(int header) {
    /// Not necessary, but usefull
    int i = 0 ;
    for (std::vector<std::string> eachVectorOfString : _dataList ){

        for(std::string eachString : eachVectorOfString){

        if (i > header){
        std::cout <<eachString<< ",";

        }
        else {

            i++;
        }

        }
        std::cout<<std::endl;

    }



}


std::vector<int> CSVReader::VecOfStringIntoVecOfInt(int header){
    /// Not necessary, but usefull
    int i = 0 ;
    for (std::vector<std::string> EachVecOfString : _dataList){

       for (std::string EachString : EachVecOfString){
       if (i > header){
         int num = atoi(EachString.c_str());
            _intNumbers.push_back(num);
       } else{

            i++;
       }

       }

    }

return _intNumbers ;
}
