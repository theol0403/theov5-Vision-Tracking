
#include "main.hpp"
#include "DriverVisionTracking.hpp"
//#include "DriverScreenDrawing.hpp"

int   screen_origin_x = 150;
int   screen_origin_y = 20;
int   screen_width    = 316;
int   screen_height   = 212;

// function to draw a single object
void drawObject()
{
  c::vision_object_s_t obj = calculateVision();

  int labelOffset = 0;

  display::set_color_bg(COLOR_YELLOW);
  display::draw_rect((screen_origin_x + obj.left_coord), (screen_origin_y + obj.top_coord), (screen_origin_x + obj.left_coord + obj.width), (screen_origin_y + obj.top_coord + obj.height));

  if(obj.left_coord > 280)
  {
    labelOffset = -40;
  }

  if(obj.top_coord > 10)
  {
    display::printf_at(screen_origin_x + obj.left_coord + labelOffset, screen_origin_y + obj.top_coord-3, "Sig %o", obj.signature);
  }
  else
  {
    display::printf_at( screen_origin_x + obj.left_coord + labelOffset, screen_origin_y + obj.top_coord+10, "Sig %o", obj.signature);
  }
}

// function to draw all objects found
void drawObjects() {
  display::set_color_bg(COLOR_GRAY);
  display::draw_rect(screen_origin_x, screen_origin_y, screen_origin_x + screen_width, screen_origin_y + screen_height);
  drawObject();
}

void screenDrawTask(void*) {
  // We have a bug in brightness at the moment
  // it needs lowering from what is set in the vision setup window
  // you may need to play with this a bit.

  c::vision_object_s_t visionDraw = calculateVision();



  // Draw an area representing the vision sensor field of view
  display::erase();
  display::set_color_bg(COLOR_GREEN);
  display::draw_rect(screen_origin_x-1, screen_origin_y-1, screen_width+2, screen_height+2);

  while(true) {
    // request any objects with signature 1
    visionDraw = calculateVision();

    display::set_color_bg(COLOR_WHITE);
    //display::printf( 2, 2, "objects %2d", (int)n );

    display::printf( 6, "Sig      %3d", visionDraw.signature);
    display::printf( 7, "Center X %3d", visionDraw.x_middle_coord );
    display::printf( 8, "Center Y %3d", visionDraw.y_middle_coord );
    display::printf( 9, "Width    %3d", visionDraw.width );
    display::printf( 10, "Height   %3d", visionDraw.height );

    // draw any objects found
    drawObjects();

    // run 10 times/second
    delay(100);
  }
}
