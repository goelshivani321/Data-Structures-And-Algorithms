#include "Coordinate.h"
#include <string>

using namespace std;
/**
 * Maximum latitude and minimum longitude for this app's input data.
 */
const double Coordinate::MAX_LATITUDE  =   49.373112;
const double Coordinate::MIN_LONGITUDE = -124.769867;

/***** Complete this class. *****/

double Coordinate::get_latitude() const
{
    return latitude;
}

double Coordinate::get_longitude() const
{
    return longitude;
}

void Coordinate::set_latitude(double lat)
{
    latitude=lat;
}

void Coordinate::set_longitude(double lon)
{
    longitude=lon;
}

istream& operator >> (istream& ins, Coordinate& coordinate)
{
    string lat,lon;

    getline(ins,lat,',');
    getline(ins,lon);

    coordinate.latitude=stod(lat);
    coordinate.longitude=stod(lon);
    return ins;
}

Coordinate::~Coordinate() {

}

Coordinate::Coordinate() :latitude(0),longitude(0){}
