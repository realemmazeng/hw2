#include <iostream>
#include <sstream>
#include <iomanip>
#include "book.h"
#include "util.h"
using namespace std;

std::set<std::string> Book::keywords() const{
  std::set<std::string> parsedName = parseStringToWords(name_);
  std::set<std::string> parsedAuthor = parseStringToWords(author_);
  std::set<std::string> res = setUnion(parsedName,parsedAuthor);
  res.insert(isbn_);
  return res;
}

// Constructor 
Book::Book(std::string prodName,
        double price,int qty,
        std::string isbn,std::string author)
    : Product("book",prodName, price, qty),
    isbn_(isbn),
    author_(author)
{
}
// Destructor 
Book::~Book(){
}

std::string Book:: displayString() const{
  std::stringstream ss;
  ss << name_ << endl;
  ss << "Author: " + author_ + " ISBN: " + isbn_ << std::endl;
  ss << fixed << setprecision(2) << price_  << "\t" << qty_ << " left.";
  return ss.str();
}

void Book::dump(std::ostream& os) const{
  os << category_ << endl;
  os << name_ << endl;
  os << price_ << endl;
  os << qty_ << endl;
  os << isbn_ << endl;
  os << author_ << endl;
}