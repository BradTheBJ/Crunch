#include "../../include/core/window.hpp"
#include <string>

int main(int argc, char **argv) {
  std::string title = "Crunch";
  Window window(title, true);
  window.display();
}
