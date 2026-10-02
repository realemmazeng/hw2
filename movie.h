#ifndef MOVIE_H
#define MOVIE_H
#include <iostream>
#include <string>
#include "product.h"

class Movie : public Product {
  public:
  Movie(std::string prodName, double price, int qty, std::string genre, std::string rating);
  ~Movie();
  virtual std::set<std::string> keywords() const;
  virtual std::string displayString() const;
  virtual void dump(std::ostream& os) const;
  private:
  std::string genre_;
  std::string rating_;
};
#endif