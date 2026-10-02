#ifndef CLOTHING_H
#define CLOTHING_H
#include <iostream>
#include <string>
#include "product.h"

class Clothing : public Product {
  public:
    Clothing(std::string prodName, double price, int qty, 
    std::string size, std::string brand);
    ~Clothing();
    virtual std::set<std::string> keywords() const;
    virtual std::string displayString() const;
    virtual void dump(std::ostream& os) const;

  private:
    std::string brand_;
    std::string size_;
};

#endif