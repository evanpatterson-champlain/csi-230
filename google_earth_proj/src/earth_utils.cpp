#include"earth_utils.h"
#include<vector>
#include<algorithm>

using namespace std;

// this function removes the extension from a filename
// which it finds by looking for the last period '.'
// date: 11/11/2020
// returns the string containing the modified filename
// param1: string containing the full filename
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


// this function extracts out csv entries from a line
// by seperating based on commas ','
// date: 11/11/2020
// returns a vector of strings containing the entries
// param1: the string containing the csv line
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


// this function converts entries extracted from the csv file
// and converts them into kml entries
// date: 11/11/2020
// returns the kml entry with the <Placemark> notation
// param1: string containing the full filename
string csvToKml(const vector<string>& csvLine){
    string kmlEntry = string("<Placemark>")
                +"\n<name>" + csvLine[1] + ", " + csvLine[0] + "</name>"
                +"\n<Point><coordinates>" + csvLine[3] + "," + csvLine[2] + "</coordinates></Point>"
                +"\n</Placemark>";
    return kmlEntry;
}



// brief: process a country csv file
// date: 11/11/2020
// return number of records
// param1: inFile ifstream to an opened and validated csv file
// param2: kmlFileName name of kml file

int parseCSV(std::ifstream& inFile, const std::string& kmlFileName){
    bool skipFirstEntry = true;
    unsigned recordsNumb = 0; // the number of records can't be negative

    ofstream kmlFileOutput;
    string newFile = removeExtension(kmlFileName);
    kmlFileOutput.open(newFile + ".kml");

    string beginFile = "<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n<kml xmlns=\"http://www.opengis.net/kml/2.2\">\n<Document>\n";
    kmlFileOutput << beginFile;

    string line;
    if(!skipFirstEntry || getline(inFile, line)){
        while(getline(inFile, line)){
            vector<string> csvEntry = interpretCsvLine(line);
            if(csvEntry.size() > 0){
                recordsNumb++;
            }
            string kmlEntry = csvToKml(csvEntry);
            kmlFileOutput << kmlEntry << '\n';
        }
    }

    string endFile = "\n</Document>\n</kml>";

    kmlFileOutput << endFile;

    int returnVal = (int)min(recordsNumb,(unsigned)INT32_MAX);
    return returnVal;
}