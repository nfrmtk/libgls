#include <cstdint>
#include <nlohmann/json.hpp>
#include <string>

namespace gls::models {
struct TTokens {
  std::string access_token;
  std::string refresh_token;
  std::string token_type;
  std::int64_t access_token_expires;
  std::int64_t refresh_token_expires;
};
NLOHMANN_DEFINE_TYPE_NON_INTRUSIVE(TTokens, access_token, refresh_token,
                                   token_type, access_token_expires,
                                   refresh_token_expires)
}  // namespace gls::models