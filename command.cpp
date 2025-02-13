#include <atomic>
#include <chrono>
#include <csignal>
#include <iostream>
#include <string>
#include <thread>
//#include <gz/msgs.hh>
//#include <gz/transport.hh>
 

void cb(const gz::msgs::LaserScan &_msg)
{
  gz::msgs::Twist data;

  bool allMore = true;
  for (int i = 0; i < _msg.ranges_size(); i++)
  {
    if (_msg.ranges(i) < 1.0)
    {
      allMore = false;
      break;
    }
  }
  if (allMore) //if all bigger than one
  {
    data.mutable_linear()->set_x(0.5);
    data.mutable_angular()->set_z(0.0);
  }
  else
  {
    data.mutable_linear()->set_x(0.0);
    data.mutable_angular()->set_z(0.5);
  }
  pub.Publish(data);
}

int main(int argc, char **argv)
{
    std::string topic_sub = "/lidar";
    // Subscribe to a topic by registering a callback.
    if (!node.Subscribe(topic_sub, cb))
    {
        std::cerr << "Error subscribing to topic [" << topic_sub << "]" << std::endl;
        return -1;
    }

    // Zzzzzz.
    gz::transport::waitForShutdown();

    return 0;
}
