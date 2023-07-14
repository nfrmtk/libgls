#pragma once
#include <gls/models/paginated_calculation_list.hpp>
#include <gls/auth.hpp>
namespace gls {

class Calculation {
  Auth& credentials;
  Calculation() = delete;
  Calculation(Auth& credentials): credentials(credentials) {}

};
}