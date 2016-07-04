#include "utilities.hh"

namespace beetrail
{

  cv::Mat Utilities::get_subimage(
      cv::Mat base_image, Vector2 pos, int square_width, int square_height)
  {
    int width = base_image.size().width;
    int height = base_image.size().height;

    int origin_x = pos.x - square_width / 2;
    int origin_y = pos.y - square_height / 2;

    int end_x = pos.x + square_width / 2;
    int end_y = pos.y + square_height / 2;

    /* Check bounds and move origin to make it fit */
    if (origin_x < 0)
    {
      end_x -= origin_x;
      origin_x = 0;
    }

    if (origin_y < 0)
    {
      end_y -= origin_y;
      origin_y = 0;
    }

    if (end_x > width - 1)
    {
      origin_x -= (end_x - width - 1);
      end_x = width - 1;
    }

    if (end_y > height - 1)
    {
      origin_y -= (end_y - height - 1);
      end_y = height - 1;
    }

    cv::Rect region(origin_x, origin_y, end_x - origin_x, end_y - origin_y);

    return base_image(region);
  }
}
