#include <iostream>
#include <sstream>
#include "util.h"
#include "clothing.h"
using namespace std;

// Constructor 
Clothing::Clothing(std::string prodName,
        double price,int qty,
        string size,string brand) 
: Product("clothing",prodName,price,qty),
brand_(brand),
size_(size)
{}

// Destructor 
Clothing::~Clothing(){}

std::set<std::string> Clothing::keywords() const{
  set<string> res = parseStringToWords(name_);
  set<string> res2 = parseStringToWords(brand_);
  set<string> combined = setUnion(res, res2);
  return combined;
}

std::string Clothing:: displayString() const{
  std::stringstream ss;
  ss << name_ << endl;
  ss << "Size: " << size_ << " Brand: " << brand_ << endl;
  ss << price_ << "\t"<< qty_ << " left.";
  return ss.str();
}
void Clothing::dump(std::ostream& os) const{
  os << category_ << endl;
  os << name_ << endl;
  os << price_ << endl;
  os << qty_ << endl;
  os << size_ << endl;
  os << brand_ << endl;
}