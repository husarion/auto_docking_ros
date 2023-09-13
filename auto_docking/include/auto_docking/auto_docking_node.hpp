#ifndef AUTO_DOCKING__AUTO_DOCKING_NODE_HPP_
#define AUTO_DOCKING__AUTO_DOCKING_NODE_HPP_

#include "aruco_opencv_msgs/msg/aruco_detection.hpp"
#include "auto_docking/types.hpp"
#include "geometry_msgs/msg/twist.hpp"
#include "rclcpp/rclcpp.hpp"

namespace auto_docking
{

using ArUcoDetectionMsg = aruco_opencv_msgs::msg::ArucoDetection;
using TwistMsg = geometry_msgs::msg::Twist;

/**
 * @brief AutoDockingNode ROS2 node. Implements the functionality of
 * auto-docking mobile robots based on the estimated pose of the dock.
 * 
 */
class AutoDockingNode : public rclcpp::Node
{
public:
  /**
   * @brief Construct a new Auto Docking Node object.
   * 
   */
  explicit AutoDockingNode();

protected:
private:
  /**
   * @brief Detection state callback function.
   * 
   * @param msg Received message
   */
  void TagDetectionCb(const ArUcoDetectionMsg::ConstSharedPtr msg);

  /// @brief The most recent detection state
  std::shared_ptr<const ArUcoDetectionMsg> current_tag_pose_;

  /// @brief Mutually exclusive callback group - forbids parallelism
  rclcpp::CallbackGroup::SharedPtr exclusive_cb_group_;
  /// @brief Reentrant callback group - allows parallelism
  rclcpp::CallbackGroup::SharedPtr reentrant_cb_group_;

  /// @brief Subscription of detection state message
  rclcpp::Subscription<ArUcoDetectionMsg>::SharedPtr tag_detection_sub_;

  /// @brief Publisher of the velocity command
  rclcpp::Publisher<TwistMsg>::SharedPtr cmd_vel_pub_;
};

}  // namespace auto_docking

#endif  // AUTO_DOCKING__AUTO_DOCKING_NODE_HPP_