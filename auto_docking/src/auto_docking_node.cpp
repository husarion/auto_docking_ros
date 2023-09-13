#include "auto_docking/auto_docking_node.hpp"
namespace auto_docking
{

AutoDockingNode::AutoDockingNode() : Node("auto_docking_node")
{
  using namespace std::placeholders;

  declare_parameter("param_1", 0);
  auto param_1 = get_parameter("param_1").as_int();

  exclusive_cb_group_ = create_callback_group(rclcpp::CallbackGroupType::MutuallyExclusive);
  reentrant_cb_group_ = create_callback_group(rclcpp::CallbackGroupType::Reentrant);

  auto sub_options = rclcpp::SubscriptionOptions();
  sub_options.callback_group = reentrant_cb_group_;

  tag_detection_sub_ = create_subscription<ArUcoDetectionMsg>(
    "aruco_detections", rclcpp::SensorDataQoS(),
    std::bind(&AutoDockingNode::TagDetectionCb, this, _1), sub_options);

  auto cmd_vel_qos = rclcpp::SystemDefaultsQoS();
  cmd_vel_qos.transient_local();

  cmd_vel_pub_ = create_publisher<TwistMsg>("/cmd_vel", cmd_vel_qos);

  RCLCPP_INFO(get_logger(), "Node is initialized");
};

void AutoDockingNode::TagDetectionCb(const ArUcoDetectionMsg::ConstSharedPtr msg)
{
  RCLCPP_INFO_ONCE(
    get_logger(), "Received initial message on topic: %s", tag_detection_sub_->get_topic_name());

  current_tag_pose_ = msg;
}

}  // namespace auto_docking