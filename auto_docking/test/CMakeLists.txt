ament_add_gtest(auto_docking_node_test auto_docking_node_test.cpp)
ament_target_dependencies(auto_docking_node_test
  ${dependencies}
)
target_link_libraries(auto_docking_node_test
  ${library_name}
)