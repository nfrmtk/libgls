#include <cpr/cpr.h>

#include <iostream>
#include <nlohmann/json.hpp>
int main() {
  cpr::Response r = cpr::Get(
      cpr::Url{"https://api.github.com/repos/whoshuu/cpr/contributors"},
      cpr::Authentication{"user", "pass", cpr::AuthMode::BASIC},
      cpr::Parameters{{"anon", "true"}, {"key", "value"}});
  r.status_code;             // 200
  r.header["content-type"];  // application/json; charset=utf-8
  std::cout << nlohmann::json::parse(r.text);  // JSON text string
  std::cout << "Hello, World!" << std::endl;
  return 0;
}
