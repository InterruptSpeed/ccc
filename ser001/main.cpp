#include <fstream>

#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>

/*
 example from boost serialization documents w/ comments
*/

class gps_position
{
private:
  // lets boost use the private serialize method
  friend class boost::serialization::access;

  // templated private method used for reading and writing
  template<class Archive>
  void serialize(Archive & ar, const unsigned int version)
  {
    // using & instead of >> and <<
    ar & degrees;
    ar & minutes;
    ar & seconds;
  }
  int degrees;
  int minutes;
  float seconds;
public:
  gps_position() {};
  gps_position(int d, int m, float s) :
    degrees(d), minutes(m), seconds(s)
  {}
};

int main() {
  // new output file stream
  std::ofstream ofs("filename");

  // new instance
  const gps_position g(35, 59, 24.567f);
  
  // guarantee deconstructor and closing of resources
  {
    boost::archive::text_oarchive oa(ofs);
    // serialize
    oa << g;
  }

  gps_position newg;
  {
    std::ifstream ifs("filename");
    boost::archive::text_iarchive ia(ifs);
    // deserialize
    ia >> newg;
  }
  return 0;
}
