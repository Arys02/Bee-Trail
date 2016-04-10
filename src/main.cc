#include <iostream>
#include "option-parser.hh"

int main(int argc, char **argv)
{
  std::shared_ptr<OptionParser> parser =
    std::make_shared<OptionParser>(OptionParser(argc, argv));
  parser->parse_options();

  return 0;
}
