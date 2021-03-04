#include <string>
#include <vector>
#include "xkcd.h"
#include <iostream>

using namespace std;

void help_instructions() {
  cout << "Command arguments: " << endl;
  cout << "--help: provides this screen to assist in finding valid commands."
       << endl;
  cout << "--img: returns only search results with a valid image, and returns "
          "the image link." << endl;
  cout << "--random: returns the link to a random comic from XKCD." << endl
       << endl;
  cout << "In order for this program to run successfully you must pipe the "
          "xkcd.json file into the ./lab6" << endl;
  cout << "This must be accompanied with the field you wish to search and the "
          "keyword you wish to seach with." << endl;
  cout << "These must be given in this order, but if you only include a "
          "KEYWORD, the program will seach the TRANSCRIPT by default." << endl;
}

int main(int argc, char *argv[]) {
  // string searchQ1 = argv[1];
  // string searchQ2 = argv[2];
  srand(time(0));
  vector<xkcd> struct_vector;
  bool img = false;
  bool random = false;
  bool help = false;

  for (std::string line; std::getline(std::cin, line);) {
    xkcd comic_struct = parse_json(line);
    // pretty_Print(comic_struct);
    struct_vector.push_back(comic_struct);

    // std::cout << comic_struct.title << endl;
  }

  // for(uint i=0;i<struct_vector.size();i++){

  //     // pretty_Print(struct_vector[i]);
  // }

  searchQ test_search;
  int test1;
  int test2;
  int test3;
  vector<string> search_vector;

  for (int i = 1; i < argc; i++) {

    // cout << i << endl;

    test1 = strcmp(argv[i], "--img");
    test2 = strcmp(argv[i], "--random");
    test3 = strcmp(argv[i], "--help");

    if (test1 == 0) {
      // cout << "img is true";
      img = true;
    } else if (test2 == 0) {
      // cout << "random is true";
      random = true;
    } else if (test3 == 0) {
      // cout << "help is true";
      help = true;
    } else {
      search_vector.push_back(argv[i]);
    }
    // for (uint i = 0; i<search_vector.size(); i++) {
    //     // cout << search_vector[i] << endl;
    // }
  }

  if (help) {
    help_instructions();
    return (0);
  } else if (search_vector.size() == 2) {
    test_search.field = search_vector[0];
    test_search.keyword = search_vector[1];
  } else if (search_vector.size() == 1) {
    test_search.field = "transcript";
    test_search.keyword = search_vector[0];
  }

  vector<xkcd> valid_vector = search_query(struct_vector, test_search, random);
  cout << "Search criteria: " << test_search.field << " / "
       << test_search.keyword << " results found: " << valid_vector.size()
       << endl;

  for (uint i = 0; i < valid_vector.size(); i++) {
    pretty_Print(valid_vector[i], img);
  }
  return 0;
}
