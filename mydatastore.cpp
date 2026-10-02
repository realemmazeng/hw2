#include <iostream>
#include <sstream>
#include "mydatastore.h"
#include "util.h"
#include <string>
#include <set>
#include <map>
#include <vector>
using namespace std;

MyDataStore::MyDataStore(){};

MyDataStore::~MyDataStore()
{
  for (Product* p: products_){
    delete p;
  }
  for (auto pair : users_){
    delete pair.second;
  }
};

void MyDataStore::addProduct(Product* p){
  products_.insert(p);
  std::set<std::string> words = p->keywords();
  for(std::string word : words){
    keywords_[word].insert(p);
  }
}

void MyDataStore::addUser(User* u){
  std::string name= convToLower(u->getName());
  users_[name] = u;
}
std::vector<Product*> MyDataStore::search(std::vector<std::string>& terms, int type){
  std::set<Product*> result;
  if (terms.empty()){
    return std::vector<Product*>();
  }
  if (keywords_.find(terms[0]) != keywords_.end()){
    result = keywords_[terms[0]];
  }
  for (int i = 1; i < (int)terms.size(); i++){
    std::set<Product*> termSet;
    if(keywords_.find(terms[i]) != keywords_.end()){
      termSet = keywords_[terms[i]];
    }
    if (type == 0){
    result = setIntersection(result,termSet);
    } else {
      result = setUnion(result,termSet);
    }
  }
  std::vector<Product*> a(result.begin(),result.end());
  return a;
}
void MyDataStore::dump(std::ostream& ofile){
  ofile << "<products>" << endl;
  for(Product* p : products_){
    p->dump(ofile);
  }
  ofile << "</products>" << endl;
  ofile << "<users>" << endl;

  for (auto pair : users_){
    pair.second->dump(ofile);
  }
  ofile << "</users>" << endl;
}

void MyDataStore::addCart(std::string username, Product* p){
  username = convToLower(username);
  if (users_.find(username) != users_.end()){
    carts_[username].push_back(p);
  } else {
    cout << "Invalid request" << endl;
  }
}

void MyDataStore::viewCart(std::string username){
  username = convToLower(username);
  
  if (users_.find(username) != users_.end()){
    std::vector<Product*> p = carts_[username];
    for (int i = 0; i < (int)p.size(); i++){
      cout << "Item " << i + 1 << endl;
      cout <<  p[i]->displayString() << endl;
      cout << endl;
    }
  }else {
    cout << "Invalid username" << endl;
  }
}
void MyDataStore::buyCart(std::string username){
  username = convToLower(username);
  vector<Product*> unav;

  if (users_.find(username) != users_.end()){
    User* u = users_[username];
    vector<Product*> cart = carts_[username];
     
    for (auto item : cart){
      if (item->getQty() > 0 && u->getBalance() >= item->getPrice()){
        item->subtractQty(1);
        u->deductAmount(item->getPrice());
      } else {
        unav.push_back(item);
      }
    }
    carts_[username] = unav;
  } else {
    cout << "Invalid username" << endl;
  }
}

