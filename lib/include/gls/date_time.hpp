#pragma once
#include "../../../third_party/date/date.h"
namespace gls {
class DateTime {
  std::chrono::milliseconds from_epoch;

 public:
  explicit DateTime(std::chrono::milliseconds ms) : from_epoch(ms){};
  std::string AsString() { return date::format("%FT%TZ", from_epoch); }
  explicit operator std::string() { return AsString(); }
};
}  // namespace gls
