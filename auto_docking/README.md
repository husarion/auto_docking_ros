### auto_docking

Package with ROS2 node responsible for mobile robot auto docking.

#### auto_docking_node

Node is responsible for auto-docking mobile robots, requires former pose estimation of the dock. The exact estimation technique is not relevant to this node, the recommended approach is to use a camera and ArUco tag.

**Subscribers**

- `/my_robot/subscribed_1` [*package_msgs/MsgType1*]: topic description.
- `/my_robot/subscribed_2` [*package_msgs/MsgType2*, frame_id: **base_link**]: topic description.

**Publishers**

- `/my_robot/published_1` [*package_msgs/MsgType3*]: topic description
- `/my_robot/published_2` [*package_msgs/MsgType4*, latched: **true**]: topic description

**Service Servers**

- `/my_robot/advertised_1` [*package_srvs/SrvType1*]: service description.
- `/my_robot/advertised_2` [*package_srvs/SrvType2*]: service description.

**Service Clients**

- `/my_robot/cliented_1` [*package_srvs/SrvType3*]: service description.
- `/my_robot/cliented_2` [*package_srvs/SrvType4*]: service description

**Action Servers**

- `/my_robot/goal_server_1` [*package_srvs/SrvType3*]: action description.
- `/my_robot/goal_server_2` [*package_srvs/SrvType4*]: action description.

**Action Clients**

- `/my_robot/goal_client_1` [*package_srvs/SrvType3*]: action description.
- `/my_robot/goal_client_2` [*package_srvs/SrvType4*]: action description.

**Parameters**

- `~my_loacal_param_1` [*type*, default: **value**]: param description.
- `~my_loacal_param_2` [*type*, default: **value**]: param description.
- `/my_robot/my_global_param_1` [*type*, default: **value**]: param description.
