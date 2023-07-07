#pragma once
#include <cstdint>
#include <nlohmann/json.hpp>

namespace gls {
enum class FormType {
  kInvalid = -1,
  kRequest,
  kQuestion,
  kPartner,
  kPromoCode,
  kWithdrawalRequest
};
NLOHMANN_JSON_SERIALIZE_ENUM(FormType, {{FormType::kInvalid, nullptr},
                                        {FormType::kRequest, "request"},
                                        {FormType::kQuestion, "question"},
                                        {FormType::kPromoCode, "promo_code"},
                                        {FormType::kPartner, "partner"},
                                        {FormType::kWithdrawalRequest,
                                         "withdrawal_request  "}})
}  // namespace gls
