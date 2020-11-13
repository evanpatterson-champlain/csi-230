#include"earth_utils.h"
#include<vector>
#include<algorithm>
#include<iostream>

using namespace std;


string removeExtension(const string& str){
    int64_t top = min(str.size()-1, (size_t)INT64_MAX);
    for(int64_t i = top; i > 0; i--){
        if(str[i] == '.'){
            string newName = str.substr(0, i);
            return newName;
        }
    }
    return str;
}


vector<string> interpretCsvLine(const string& line){
    vector<string> entr;
    string curEntr = "";
    for(size_t i = 0; i < line.size(); i++){
        if(line[i] == ','){
            entr.push_back(curEntr);
            curEntr = "";
        }
        else{
            curEntr += line[i];
        }
    }
    return entr;
}

string csvToKml(const vector<string>& csvLine){
    string kmlEntry = string("<Placemark>")
                +"\n<name>" + csvLine[1] + ", " + csvLine[0] + "</name>"
                +"\n<Point><coordinates>" + csvLine[3] + "," + csvLine[2] + "</coordinates></Point>"
                +"\n</Placemark>";
    return kmlEntry;
}

int parseCSV(std::ifstream& inFile, const std::string& kmlFileName){
    bool skipFirstEntry = true;
    unsigned recordsNumb = 0; // the number of records can't be negative

    ofstream kmlOut;
    string newFile = removeExtension(kmlFileName);
    kmlOut.open(newFile + ".kml");

    string beginFile = "<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n<kml xmlns=\"http://www.opengis.net/kml/2.2\">\n<Document>\n";
    kmlOut << beginFile;

    string line;
    if(!skipFirstEntry || getline(inFile, line)){
        while(getline(inFile, line)){
            vector<string> csvEntry = interpretCsvLine(line);
            if(csvEntry.size() > 0){
                recordsNumb++;
            }
            string kmlEntry = csvToKml(csvEntry);
            cout << kmlEntry << endl;
            kmlOut << kmlEntry << '\n';
        }
    }

    string endFile = "\n</Document>\n</kml>";

    kmlOut << endFile;

    int returnVal = (int)min(recordsNumb,(unsigned)INT32_MAX);
    return returnVal;
}