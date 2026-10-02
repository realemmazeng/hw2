#include <iostream>
#include <sstream>
#include "util.h"
#include "movie.h"
using namespace std;


Movie::Movie(std::string prodName, double price, int qty, 
std::string genre, std::string rating)
: Product("movie", prodName, price, qty),
  genre_(genre),
  rating_(rating)
{
}

Movie::~Movie()
{
}

std::set<std::string> Movie::keywords() const{
  std::set<std::string> res = parseStringToWords(name_);
  res.insert(convToLower(genre_));
  return res;
}

std::string Movie::displayString() const{
  std::stringstream ss;
  ss << name_ << endl;
  ss << "Genre: " << genre_ << " Rating: " << rating_<< endl;
  ss << price_ << "\t"<< qty_ << " left.";
  return ss.str();
}

void Movie::dump(std::ostream& os) const{
  os << category_ << endl;
  os << name_ << endl;
  os << price_ << endl;
  os << qty_ << endl;
  os << genre_ << endl;
  os << rating_ << endl;
}