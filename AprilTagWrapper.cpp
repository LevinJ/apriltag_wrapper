/*
 * AprilTagWrapper.cpp
 *
 *  Created on: Aug 2, 2022
 *      Author: levin
 */

#include "AprilTagWrapper.h"


//#include "tag36h11.h"
//#include "tag25h9.h"
//#include "tag16h5.h"
//#include "tagCircle21h7.h"
//#include "tagCircle49h12.h"
//#include "tagCustom48h12.h"
//#include "tagStandard41h12.h"
//#include "tagStandard52h13.h"
#include "tag36h9.h"

//#include "common/getopt.h"
#include "common/image_u8.h"
//#include "common/pjpeg.h"


AprilTagWrapper::AprilTagWrapper() {
	// TODO Auto-generated constructor stub
	td_ = apriltag_detector_create();
	tf_ = tag36h9_create();
	apriltag_detector_add_family_bits(td_, tf_, 1);
	switch(errno){
		case EINVAL:
			printf("\"hamming\" parameter is out-of-range.\n");
			exit(-1);
		case ENOMEM:
			printf("Unable to add family to detector due to insufficient memory to allocate the tag-family decoder. Try reducing \"hamming\" from %d or choose an alternative tag family.\n", 1);
			exit(-1);
	}
	td_->quad_decimate = 2.0;
	td_->quad_sigma = 0.0;
	td_->nthreads = 1;
	td_->debug = true;
	td_->refine_edges = true;

}
zarray_t *AprilTagWrapper::detect_tags(cv::Mat img){
	cv::Mat gray;
	if (img.channels() == 3) {
		cv::cvtColor(img, gray, cv::COLOR_BGR2GRAY);
	}else{
		gray = img;
	}
	image_u8_t im = { .width = gray.cols,
			.height = gray.rows,
			.stride = gray.cols,
			.buf = gray.data
	};

	zarray_t *detections = apriltag_detector_detect(td_, &im);
	return detections;
}
AprilTagWrapper::~AprilTagWrapper() {
	// TODO Auto-generated destructor stub
	// Cleanup.
	tag36h9_destroy(tf_);
	apriltag_detector_destroy(td_);
}

