#include <bits/stdc++.h>
using namespace std; //! STL

int main() {
  // creation
  unordered_map<string, int> mapping;
  // insertion 3 types
  pair<string, int> p = make_pair("love", 25);

  pair<string, int> q("sujal", 24);

  pair<string, int> r;
  q.first = "kumar";
  q.second = 23;
  // insertion
  mapping.insert(p);
  mapping.insert(q);
  mapping.insert(r);
  // insert
  mapping["babbar"] = 51; //! for full insertion and making pair simultaneously

  cout << "Size of map: " << mapping.size() << endl;
  // ACCESS
  cout << mapping.at("love") << endl; //* for value printing
  cout << mapping["love"] << endl;
  // searching
  cout << mapping.count("love")
       << endl; //! present ho to 1 print hoga otherwise 0

  if (mapping.find("babbar") != mapping.end()) {
    cout << "Found" << endl;
  } else {
    cout << "Not Found" << endl;
  }

  cout << "Size of map: " << mapping.size() << endl;
  cout << mapping["batman"] << endl;
  cout << "Size of map: " << mapping.size() << endl;

  return 0;
}