#pragma once

#include <yaml-cpp/yaml.h>

#include "common.h"
#include "feature_extractor_VLP16.h"
#include "visualizer_feature_points.h"

namespace oh_my_loam {

class OhMyLoam {
 public:
  OhMyLoam() = default;
  ~OhMyLoam() = default;
  OhMyLoam(const OhMyLoam&) = delete;
  OhMyLoam& operator=(const OhMyLoam&) = delete;

  bool Init(const YAML::Node& config);

  void Run(const PointCloud& cloud, double timestamp);

 private:
  void Visualize(const PointCloud& cloud,
                 const std::shared_ptr<const FeaturePoints>& feature_pts,
                 double timestamp = std::nanf(""));

  bool is_vis_ = false;
  std::unique_ptr<FeaturePointsExtractor> feature_extractor_ = nullptr;
  std::unique_ptr<FeaturePointsVisualizer> visualizer_ = nullptr;
  YAML::Node config_;
};

}  // namespace oh_my_loam