#include <yaml-cpp/yaml.h>
#include <iostream>
#include <fstream>

#include "planner.hpp"

int main(int /*argc*/, char** /*argv*/)
{
  std::cout << "OMPL version: " << OMPL_VERSION << std::endl;

  try
  {
    YAML::Node config = YAML::LoadFile("/home/AnywareInterview/cpp/config.yaml");
    double q1_start = config["q1_start"].as<double>();
    double q2_start = config["q2_start"].as<double>();
    double q3_start = config["q3_start"].as<double>();
  }
  catch (const YAML::Exception& e)
  {
    std::cerr << "Error parsing YAML file: " << e.what() << std::endl;
  }

  // q1, q2, q3
  std::array<double, 3> q_start = { 0.611, 0.215, -0.826 };

  // x, y, z
  std::array<double, 3> goal = { 0.5, -1.0, 0.05 };

  // x1, y1, theta1, x2, y2, theta2, x3, y3, theta3
  std::array<double, 9> box_pose = { 1.45, 1.0, 0.0, 1.25, 0.2, 0.0, 1.65, 0.2, 0.0 };

  plan(q_start, goal, box_pose);

  return 0;
}