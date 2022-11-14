add_library(sktui::terminal ALIAS terminal)
export(
  TARGETS terminal 
  NAMESPACE sktui::
  FILE ${PROJECT_BINARY_DIR}/sktui-targets.cmake
)
