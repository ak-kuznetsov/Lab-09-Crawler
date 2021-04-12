// Copyright 2021 ak-kuznetsov <a.kuznetsov2701@mail.ru>

#ifndef INCLUDE_PARSER_HPP
#define INCLUDE_PARSER_HPP
#include <iostream>

#include "Downloader.hpp"
#include "Queue.hpp"
#include <string>

struct URL {
  std::string url;
  size_t depth;
};
class Parser {
 public:
  Parser() = delete;
  static void parse();
  inline static Queue<URL> queue_url;
  inline static Queue<std::string> queue_writer;
};

#endif  // INCLUDE_PARSER_HPP

