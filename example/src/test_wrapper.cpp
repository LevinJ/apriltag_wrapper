#include "AprilTagWrapper.h"
#include <iostream>
#include <eigen3/Eigen/Dense>


using namespace Eigen;
int main(int argc, char** argv) {
	AprilTagWrapper atw;

	char *path = "/home/levin/temp/1.jpg";
	cv::Mat img = cv::imread(path);
	zarray_t *detections = atw.detect_tags(img);
	std::cout<<"detect tags num="<< detections->size<<std::endl;
	for (int i = 0; i < zarray_size(detections); i++) {
	    apriltag_detection_t *det;
	    zarray_get(detections, i, &det);

	    // Do stuff with detections here.
	    std::cout<<"tag id="<<det->id<<std::endl;
	    Map<Matrix<double,4,2,RowMajor> > corners(det->p[0]);
	    std::cout<<"tag coners:"<<std::endl<<corners<<std::endl;
	    std::cout<<std::endl;
	}
	return 0;
}
