#ifndef _M_MAIN_UI_H
#define _M_MAIN_UI_H
#include "imgui.h"

class MainCanvas {
  public:
  bool isOpen;

  MainCanvas();
  ~MainCanvas(){};

  void Draw();
  
  private:
    ImGuiWindowFlags mFlags;
    char* mName;
};



#endif
