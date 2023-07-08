#include <cpr/cpr.h>

#include <gls/auth.hpp>
#include <iostream>
#include <nlohmann/json.hpp>
int main() {
  gls::TAuthToken email_password = {std::getenv("EMAIL"),
                                    std::getenv("PASSWORD")};
  auto body = to_string(nlohmann::json(std::move(email_password)));
  std::cout << body << " is the bosy of today show\n";
  auto credentials = cpr::Post(
      cpr::Url{"https://back.glsystem.net/api/v1/auth/login/"}, cpr::Body{body},
      cpr::Header{
          {"Content-Type", "application/json"},
          //                  {"X-CSRFTOKEN",
          //                   "x4kqoi5Zw8vKofN2CdcsztHBlKJxEMaps60yZsfXnh9mnLEO96srRNS3kDV"
          //                   "JVDfZ"}
      });
  std::cout << credentials.status_code
            << '\n';  // application/json; charset=utf-8
  std::cout << nlohmann::json::parse(credentials.text);  // JSON text string
  //  auto email = std::getenv("EMAIL");
  //  std::cout << (email ? email: "sad");
  return 0;
}
