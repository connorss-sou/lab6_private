#include <string>
#include "json.hpp"

#ifndef XKCD
#define XKCD

struct xkcd {
  std::string month;
  int num;
  std::string link;
  std::string year;
  std::string news;
  std::string safe_title;
  std::string transcript;
  std::string transcript_lower;
  std::string alt;
  std::string alt_lower;
  std::string img;
  std::string title;
  std::string title_lower;
  std::string day;
};
struct searchQ {
  std::string field = "";
  std::string keyword = "";
};
void from_json(nlohmann::json& j, xkcd& x);
xkcd parse_json(std::string);
void pretty_Print(xkcd, bool);
std::vector<xkcd> search_query(std::vector<xkcd>, searchQ, bool);

#endif


