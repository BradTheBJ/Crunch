#pragma once
#include <print>
#include <array>

class Logs {
    public:
      Logs(unsigned int size) : m_size(size) {};
      void log(std::array<std::string, m_size> messages);
    private:
      unsigned int m_size;
}