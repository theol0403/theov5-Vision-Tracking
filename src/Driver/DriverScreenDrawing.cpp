
#include "main.hpp"
#include "DriverVisionTracking.hpp"
#include "DriverScreenDrawing.hpp"

int   screen_origin_x = 150;
int   screen_origin_y = 20;
int   screen_width    = 316;
int   screen_height   = 212;

//TODO: Tidy things up to look better

// function to draw a single object
void drawObjects(c::vision_object_s_t obj)
{
  display::set_color_bg(COLOR_GREY);
  display::clear_rect(screen_origin_x+1, screen_origin_y+1, screen_origin_x-1 + screen_width, screen_origin_y-1 + screen_height);


  int labelOffset = 0;

  display::set_color_fg(COLOR_YELLOW);
  display::draw_rect((screen_origin_x + obj.left_coord), (screen_origin_y + obj.top_coord), (screen_origin_x + obj.left_coord + obj.width), (screen_origin_y + obj.top_coord + obj.height));

  if(obj.left_coord > 280)
  {
    labelOffset = -40;
  }

  if(obj.top_coord > 10)
  {
    pros::c::display_printf_at(screen_origin_x + obj.left_coord + labelOffset, screen_origin_y + obj.top_coord-3, "Sig %o", obj.signature);
  }
  else
  {
    pros::c::display_printf_at( screen_origin_x + obj.left_coord + labelOffset, screen_origin_y + obj.top_coord+10, "Sig %o", obj.signature);
  }
}


void screenDrawTask(void*) {
  // We have a bug in brightness at the moment
  // it needs lowering from what is set in the vision setup window
  // you may need to play with this a bit.

  c::vision_object_s_t visionDraw = calculateVision();



  // Draw an area representing the vision sensor field of view
  display::erase();
  display::set_color_fg(COLOR_GREEN);
  display::draw_rect(screen_origin_x-2, screen_origin_y-2, screen_width+2, screen_height+2);

  while(true) {
    // request any objects with signature 1
    visionDraw = calculateVision();

    display::set_color_fg(COLOR_WHITE);
    //display::printf( 2, 2, "objects %2d", (int)n );

    pros::c::display_printf( 6, "Sig      %3d", visionDraw.signature);
    pros::c::display_printf( 7, "Center X %3d", visionDraw.x_middle_coord );
    pros::c::display_printf( 8, "Center Y %3d", visionDraw.y_middle_coord );
    pros::c::display_printf( 9, "Width    %3d", visionDraw.width );
    pros::c::display_printf( 10, "Height   %3d", visionDraw.height );

    // draw any objects found
    drawObjects(visionDraw);

    // run 10 times/second
    delay(100);
  }
}
