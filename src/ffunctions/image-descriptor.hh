#pragma once

#include <string>

namespace beetrail
{

  class ImageDescriptor
  {
    public:
      ImageDescriptor(std::string p_file_path);

    private:
      std::string file_path;
  };
}
