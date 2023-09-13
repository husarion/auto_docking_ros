#include <iostream>

#include "auto_docking/auto_docking_node.hpp"
#include "rclcpp/rclcpp.hpp"

using namespace auto_docking;

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);

  rclcpp::executors::MultiThreadedExecutor executor;
  auto auto_docking_node = std::make_shared<AutoDockingNode>();

  executor.add_node(auto_docking_node);

  try {
    executor.spin();
  } catch (const std::runtime_error & e) {
    std::cerr << "[AutoDockingNode] Caught exception: " << e.what() << std::endl;
  }

  std::cout << "[AutoDockingNode] Shutting down" << std::endl;
  rclcpp::shutdown();
  return 0;
}