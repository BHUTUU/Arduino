#include <Pixy2.h>
// This is the main Pixy object
Pixy2 pixy;
int pencil_body_area; //size of detected pencil body
int eraser_head_area; //size of detected eraser head
int pencil_body_x; //location in x of pencil body
int pencil_body_y; //location in y of pencil body
int eraser_head_x; //location in x of eraser head
int eraser_head_y; //location in y of eraser head
bool isArea; //used to check if area category is justified
bool isLocation; //used to check if location category is justified
void setup()
{
  Serial.begin(115200);
  Serial.print("Starting...\n");
  isArea = false;
  isLocation = false;
  pixy.init();
}
void loop()
{
  int i;
  // grab blocks!
  pixy.ccc.getBlocks();
  // If there are detect blocks, print them!
  if (pixy.ccc.numBlocks)
  {
    pencil_body_area = pixy.ccc.blocks[0].m_height * pixy.ccc.blocks[0].m_width;
    eraser_head_area = pixy.ccc.blocks[1].m_height * pixy.ccc.blocks[1].m_width;
    pencil_body_x = pixy.ccc.blocks[0].m_x;
    pencil_body_y = pixy.ccc.blocks[0].m_y;
    eraser_head_x = pixy.ccc.blocks[1].m_x;
    eraser_head_y = pixy.ccc.blocks[1].m_y;
    int area_factor = pencil_body_area / eraser_head_area;
    if(area_factor > 100 && area_factor < 150){
      isArea = true;
    }else{
      isArea = false;
    }
    int loc_factor_x = pencil_body_x - eraser_head_x;
    int loc_factor_y = pencil_body_y - eraser_head_y;
    if(loc_factor_x < 20 || loc_factor_y < 20){
      isLocation = true;
    }else{
      isLocation = false;
    }
    if(isArea && isLocation){
      Serial.println("Pencil detected!");
    }
  }
}
