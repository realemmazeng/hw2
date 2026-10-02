#ifndef MYDATASTORE_H
#define MYDATASTORE_H
#include <string>
#include <set>
#include <map>
#include <vector>
#include "datastore.h"

class MyDataStore : public DataStore{
public:
MyDataStore();
~MyDataStore();
void addProduct(Product* p);
void addUser(User* u);
std::vector<Product*> search(std::vector<std::string>& terms, int type);
void dump(std::ostream& ofile);

void addCart(std::string username, Product* p);
void viewCart(std::string username);
void buyCart(std::string username);

private:
std::set<Product*> products_;
std::map<std::string,std::set<Product*>> keywords_;
std::map<std::string,User*> users_;
std::map<std::string,std::vector<Product*>> carts_;
};

#endif