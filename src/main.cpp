#include "../include/window.hpp"
#include "../include/definitions/gridvars.hpp"
#include <string>

int main() {
  GridVars gridVars;
  Window window(gridVars.title, true);
  window.display();
}
