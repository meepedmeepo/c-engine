#include "main_ui.h"
#include "imgui.h"

MainCanvas::MainCanvas() {
  isOpen = true;

  mFlags = 0;
  mFlags |= ImGuiWindowFlags_NoTitleBar;
  mFlags |= ImGuiWindowFlags_NoBackground;
  mFlags |= ImGuiWindowFlags_NoResize;
  mFlags |= ImGuiWindowFlags_NoMove;

  mName = (char *)"main_ui";
}

void MainCanvas::Draw() {
  ImGui::Begin(mName, &isOpen, mFlags);
  ImGui::Text("Test");
  ImGui::End();
}
