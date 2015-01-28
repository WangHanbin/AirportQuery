#include <iostream>
#include <fstream> // ifstream read the file
#include "map.h"
#include <string>
//#include "simpio.h"
//#include "strlib.h"
#include "console.h"
using namespace std;
const bool DEBUG = false;

Map <string, string> readAirportsInfoFromFile(char* filename);

int main() {
    //if(argc<2)
////    {
 //       cout<<"Please confirm which file you want to load."<<endl;
  //      return -1;
   // }
    Map <string, string> airportsInfo;
    char* filename ="AirportCodes.txt";
    airportsInfo = readAirportsInfoFromFile(filename);
    while(true){
        cout<<"Please input the airport code: ";
        string airportCode;
           cin>>airportCode;
           if(airportsInfo.containsKey(airportCode))
           {
               cout<<"This airport is in "<<airportsInfo.get(airportCode)<<endl;
               cout<<endl;
           }
           else
           {
               cout<<"Sorry, this airport code isn't in the database!"<<endl;
           cout<<endl;
           }
    }

    return 0;
}

Map <string, string> readAirportsInfoFromFile(char* filename)
{
    if(DEBUG)
    {
        Map <string, string> testMap;
        testMap.put("PVG","Shanghai, China");
        return testMap;

    }
    else
    {

        Map <string, string> airportMap ;
        ifstream readFile;
        readFile.open(filename);
        if(readFile.fail()) error("can't open the file!");
        string line;
        while(getline(readFile,line))
        {
           string code = toUpperCase(line.substr(0,3));
           airportMap.put(code,line.substr(4));
        }
        return airportMap;
    }
}
