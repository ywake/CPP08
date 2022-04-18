#include "Span.hpp"

#include <iomanip>
#include <iostream>

void subject()
{
  std::cout << "--- subject ---" << std::endl;

  Span sp = Span(5);
  sp.addNumber(6);
  sp.addNumber(3);
  sp.addNumber(17);
  sp.addNumber(9);
  sp.addNumber(11);

  std::cout << sp.shortestSpan() << std::endl;
  std::cout << sp.longestSpan() << std::endl;
}

#define SPACE 15

template <typename T>
void log(std::string const &title, T const &val)
{
  std::cout << std::setw(SPACE) << std::left << title << "| " << val
            << std::endl;
}

template <>
void log(std::string const &title, std::exception const &e)
{
  std::cout << std::setw(SPACE) << std::left << title << "| " << e.what()
            << std::endl;
}

void myTest()
{
  std::cout << "--- my test ---" << std::endl;

  Span sp = Span(5);
  sp.addNumber(6);
  sp.addNumber(3);
  sp.addNumber(17);
  sp.addNumber(9);

  {
    log("sp", sp);
    Span copy(sp);
    log("copy", copy);
    std::cout << "\n";
    Span assign(2);
    assign.addNumber(100);
    log("assign init", assign);
    assign = sp;
    log("assign = sp", assign);
    std::cout << "\n";
    sp.addNumber(11);
    log("sp add", sp);
    log("assign (deep)", assign);
    std::cout << "\n";
  }

  std::cout << std::setw(SPACE) << std::left << "sp add"
            << "| ";
  try {
    sp.addNumber(12);
  } catch (const std::exception &e) {
    std::cout << e.what() << std::endl;
  }

  Span empty;
  log("empty", empty);
  std::cout << "\n";

  std::cout << "- shortestSpan / longestSpan -" << std::endl;
  Span few(5);
  int test[] = {42, 0, 1, 1, 0};

  for (size_t i = 0; i < 5; i++) {
    log("few", few);
    try {
      log("few.shortest", few.shortestSpan());
    } catch (const std::exception &e) {
      log("few.shortest", e);
    }
    try {
      log("few.longest", few.longestSpan());
    } catch (const std::exception &e) {
      log("few.longest", e);
    }
    few.addNumber(test[i]);
  }
  std::cout << std::endl;

  std::cout << "- range add -" << std::endl;
  Span range(10);
  log("range", range);
  std::vector<int> first(2);
  first[0] = 0;
  first[1] = 1;
  range.addNumber(first.begin(), first.end());
  log("range.add {0,1}", range);

  std::vector<int> second(2);
  second[0] = 2;
  second[1] = 3;
  range.addNumber(second.begin(), second.end());
  log("range.add {2,3}", range);

  // {4, 5, 6, 7, 8, 9, 10, 11, 12, 13}
  std::vector<int> third(10);
  for (size_t i = 0; i < 10; i++) {
    third[i] = i + 4;
  }
  try {
    range.addNumber(third.begin(), third.end());
    log("range.add {4...", range);
  } catch (const std::exception &e) {
    log("range.add {4...", e);
  }
  log("range after", range);
}

int main()
{
  subject();
  std::cout << std::endl;
  myTest();
  return 0;
}
