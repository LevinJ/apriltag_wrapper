/*
 * AprilTagWrapper.h
 *
 *  Created on: Aug 2, 2022
 *      Author: levin
 */

#ifndef APRILTAGWRAPPER_H_
#define APRILTAGWRAPPER_H_

#include "apriltag.h"
#include "common/zarray.h"
#include "opencv2/opencv.hpp"

class AprilTagWrapper {
public:
	AprilTagWrapper();
	virtual ~AprilTagWrapper();
	zarray_t *detect_tags(cv::Mat img);
private:
	apriltag_detector_t *td_;
	apriltag_family_t *tf_;
};

#endif /* APRILTAGWRAPPER_H_ */
