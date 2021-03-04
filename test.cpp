#include "json.hpp"
#include <iostream>

// for convenience
using json = nlohmann::json;

struct xkcd {
  std::string month;
  std::string num;
  std::string link;
  std::string year;
  std::string news;
  std::string safe_title;
  std::string transcript;
  std::string alt;
  std::string img;
  std::string title;
  std::string day;
};

void from_json(json& j, xkcd& comic_struct) {

  j.at("month").get_to(comic_struct.month);
  j.at("num").get_to(comic_struct.num);
  j.at("link").get_to(comic_struct.link);
  j.at("year").get_to(comic_struct.year);
  j.at("news").get_to(comic_struct.news);
  j.at("safe_title").get_to(comic_struct.safe_title);
  j.at("transcript").get_to(comic_struct.transcript);
  j.at("alt").get_to(comic_struct.alt);
  j.at("img").get_to(comic_struct.img);
  j.at("title").get_to(comic_struct.title);
  j.at("day").get_to(comic_struct.day);

}

int main() {
  for (std::string line; std::getline(std::cin, line);) {
    xkcd comic_struct;
    json j = json::parse(line);
    from_json(j, comic_struct);
    std::cout << comic_struct.year;
   }

  // json j = "{ \"name\": \"testname\", \"value\": \"testvalue\", \"url\": \"testurl\" }"_json;
  // from_json(j, c);
  // std::cout << "Hello" << c.name;
}