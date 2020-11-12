#include"earth_utils.h"
#include<vector>

using namespace std;



int parseCSV(std::ifstream& inFile, std::string kmlFileName){
    bool skipFirstEntry = true;
    unsigned recordsNumb = 0;

    ofstream kmlOut;
    kmlOut.open(kmlFileName);

    string line;
    if(!skipFirstEntry || getline(inFile, line)){
        while(getline(inFile, line)){
            vector<string> entr;
            string curEntr = "";
            for(size_t i = 0; i < line.size(); i++){
                if(line[i] == ','){
                    entr.push_back(curEntr);
                }
                else{
                    curEntr += line[i];
                }
            }
            if(entr.size() > 0){
                recordsNumb++;
            }

            string kmlEntry = string("<Placemark>")
                +"<name>" + entr[0] + ", " + entr[1] + "</name>"
                +"<Point>"
                +"<coordinates>" + entr[2] + ", " + entr[3] + "</coordinates>"
                +"</Point>"
                +"</Placemark>"
                +"</kml>";
            kmlOut << kmlEntry << '\n';
        }
    }

    if(recordsNumb < INT32_MAX) {
        int ret = (int)recordsNumb;
        return ret;
    }
    else{
        return INT32_MAX;
    }
}