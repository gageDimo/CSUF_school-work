#pragma once

#include <fstream>
#include <sstream>
#include <string>

using std::getline;
using std::ifstream;
using std::stringstream;
using std::string;

struct Location {

public:

  string name;
  string address;
  string city;
  long postalCode;
  string province;
  double latitude;
  double longitude;
  int priceRangeMin;
  int priceRangeMax;


};

class PizzaZine {
private:
    Location* pizzaLocations;
    size_t size;

public:
    PizzaZine(const size_t& = 50);
    ~PizzaZine();

    Location& operator[](size_t);

    // This function is implemented for you
    void readInFile(const string&);
};

//constructor
PizzaZine::PizzaZine(const size_t&) {

  const size_t& size = 50;
  pizzaLocations = NULL;

}

//destructor
PizzaZine::~PizzaZine() {

  delete[] pizzaLocations;
  size = 0;

}

Location& PizzaZine::operator[](size_t) {

  return size[pizzaLocations];

}

void PizzaZine::readInFile(const string& filename) {
    ifstream inFile(filename);
    Location newLoc;

    string line;
    string cell;

    // Read each line
    for (int i = 0; i < size; ++i) {
        // Break each line up into 'cells'
        getline(inFile, line);
        stringstream lineStream(line);
        while(getline(lineStream, newLoc.name, ',')) {
            getline(lineStream, newLoc.address, ',');
            getline(lineStream, newLoc.city, ',');
            getline(lineStream, cell, ',');
            if (!cell.empty()) {
                newLoc.postalCode = stoul(cell);
            }

            getline(lineStream, newLoc.province, ',');
            getline(lineStream, cell, ',');
            newLoc.latitude = stod(cell);
            getline(lineStream, cell, ',');
            newLoc.longitude = stod(cell);

            newLoc.priceRangeMin = -1;
            getline(lineStream, cell, ',');
            if (!cell.empty()) {
                newLoc.priceRangeMin = stoul(cell);
            }

            newLoc.priceRangeMax = -1;
            getline(lineStream, cell, ',');
            if (!cell.empty() && cell != "\r") {
                newLoc.priceRangeMax = stoul(cell);
            }
            pizzaLocations[i] = newLoc;
        }
    }
}
