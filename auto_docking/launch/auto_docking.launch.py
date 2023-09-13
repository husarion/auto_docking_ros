from launch_ros.actions import Node
from launch_ros.substitutions import FindPackageShare

from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument
from launch.substitutions import LaunchConfiguration, PathJoinSubstitution


def generate_launch_description():
    auto_docking_cfg_path = PathJoinSubstitution(
        [FindPackageShare("auto_docking"), "config", "auto_docking.yaml"]
    )

    cfg_file = LaunchConfiguration("auto_docking_cfg_file")
    use_sim_time = LaunchConfiguration("use_sim_time")

    cfg_file_argument = DeclareLaunchArgument(
        "auto_docking_cfg_file",
        default_value=auto_docking_cfg_path,
        description="ROS2 parameters file to use with auto_docking node",
    )

    use_sim_time_arg = DeclareLaunchArgument(
        "use_sim_time",
        default_value="False",
        description="Use simulation (Gazebo) clock if true",
    )

    log_level_arg = DeclareLaunchArgument(
        "log_level",
        default_value="info",
        description="Logging severity level",
    )

    auto_docking_node = Node(
        package="auto_docking",
        executable="auto_docking",
        arguments=["--ros-args", "--log-level", LaunchConfiguration("log_level")],
        parameters=[cfg_file, {"use_sim_time": use_sim_time}],
        output="screen",
        emulate_tty="true",
    )

    actions = [cfg_file_argument, use_sim_time_arg, log_level_arg, auto_docking_node]

    return LaunchDescription(actions)
