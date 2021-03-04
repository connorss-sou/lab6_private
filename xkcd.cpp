#include "xkcd.h"
#include "json.hpp"
#include "string"
#include <iostream>

using namespace std;
using json = nlohmann::json;

void from_json(json& j, xkcd& comic_struct) {


  j.at("month").get_to(comic_struct.month);
  j.at("num").get_to(comic_struct.num);
  j.at("link").get_to(comic_struct.link);
  j.at("year").get_to(comic_struct.year);
  j.at("news").get_to(comic_struct.news);
  j.at("safe_title").get_to(comic_struct.safe_title);
  j.at("transcript").get_to(comic_struct.transcript);
  j.at("transcript").get_to(comic_struct.transcript_lower);
  transform(comic_struct.transcript_lower.begin(), comic_struct.transcript_lower.end(), comic_struct.transcript_lower.begin(), ::tolower); 
  j.at("alt").get_to(comic_struct.alt);
  j.at("alt").get_to(comic_struct.alt_lower); 
  transform(comic_struct.alt_lower.begin(), comic_struct.alt_lower.end(), comic_struct.alt_lower.begin(), ::tolower); 
  j.at("img").get_to(comic_struct.img);
  j.at("title").get_to(comic_struct.title);
  j.at("title").get_to(comic_struct.title_lower);
  transform(comic_struct.title_lower.begin(), comic_struct.title_lower.end(), comic_struct.title_lower.begin(), ::tolower); 
  j.at("day").get_to(comic_struct.day);

}

xkcd parse_json(string line) {
  xkcd comic;
  json j = json::parse(line);
  from_json(j, comic);
  return(comic);
}



std::vector<xkcd> search_query(std::vector<xkcd> full_vector, searchQ search_criteria, bool random) {

  vector<xkcd> valid_vector;
  vector<xkcd> alt_vector;
  string final_random_search;
  // vector<xkcd> final_valid_vector;
  

  if (search_criteria.field == "" && search_criteria.keyword == "" && random) {
    int random_selection = rand() % full_vector.size();
    cout << "This is a random string from the whole document.";
    valid_vector.push_back(full_vector[random_selection]);
  }

  else {
    for (uint i = 0; i < full_vector.size(); i++) {
      if (search_criteria.field == "title") {
        if (string::npos != full_vector[i].title_lower.find(search_criteria.keyword)) {
            valid_vector.push_back(full_vector[i]);
        }
      }
      else if (search_criteria.field == "transcript") {
        if (string::npos != full_vector[i].transcript_lower.find(search_criteria.keyword)) {
            valid_vector.push_back(full_vector[i]);
        }
      }
      else if (search_criteria.field == "alt") {
        if (string::npos != full_vector[i].alt_lower.find(search_criteria.keyword)) {
            valid_vector.push_back(full_vector[i]);
        }
      }
    }
  }

  if (random && (search_criteria.field == "title" || search_criteria.field == "transcript" || search_criteria.field == "alt")) {
    int random_selection = rand() % valid_vector.size();
    xkcd final_random_search = valid_vector[random_selection];
    alt_vector.push_back(final_random_search);
    return(alt_vector);
  }

  else {
    return(valid_vector);
  }
}

void pretty_Print(xkcd comic, bool img) {
    if (!img) {
      cout << comic.title << ": " << "https://xkcd.com/" << comic.num << endl;
      //cout << comic.title << ": " << comic.title_lower << endl;
    }
    else {
      cout << comic.title << ": " << comic.img << endl;
    }
}