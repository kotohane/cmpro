
#ifndef CMPRO_SHAPE_PROCESSING_H
#define CMPRO_SHAPE_PROCESSING_H

#include <dlib/opencv.h>
#include <opencv2/opencv.hpp>
#include <dlib/image_processing/frontal_face_detector.h>
#include <dlib/image_processing/render_face_detections.h>
#include <dlib/image_processing.h>

#include "configure.h"
#include "coordinate_convert.h"
#include "sequence_convert.h"

class ShapeProcessingClass {
public:

    ShapeProcessingClass();


    void image_select(dlib::full_object_detection& shape_input);
    void value_cal(std::vector<double>& vector_input_);

    double right_eye_value;
    double left_eye_value;
    double mouth_value;
    double eye_value;
    bool is_eye_normal;

    double angle_X;
    double angle_Y;
    double angle_Z;



    long shape_differ_left;
    long shape_differ_top;
    long shape_width;
    long shape_height;

    void DimensionCalculation();

    dlib::full_object_detection detected_shape;
private:
    std::vector<double> vector_input;
    bool RightEyeValueCalculate();
    bool LeftEyeValueCalculate();
    bool MouthValueCalculate();
    bool AnglePoseDetect();


    //----------angle data----------
    double K[9] = { 6.5308391993466671e+002, 0.0, 3.1950000000000000e+002, 0.0, 6.5308391993466671e+002, 2.3950000000000000e+002, 0.0, 0.0, 1.0 };
    double D[5] = { 7.0834633684407095e-002, 6.9140193737175351e-002, 0.0, 0.0, -1.3073460323689292e+000 };
    std::vector<cv::Point3d> Model3D={{-7.308957,0.913869,0.000000}, {-6.775290,-0.730814,-0.012799}, {-5.665918,-3.286078,1.022951}, {-5.011779,-4.876396,1.047961}, {-4.056931,-5.947019,1.636229}, {-1.833492,-7.056977,4.061275}, {0.000000,-7.415691,4.070434}, {1.833492,-7.056977,4.061275}, {4.056931,-5.947019,1.636229}, {5.011779,-4.876396,1.047961}, {5.665918,-3.286078,1.022951}, {6.775290,-0.730814,-0.012799}, {7.308957,0.913869,0.000000}, {5.311432,5.485328,3.987654}, {4.461908,6.189018,5.594410}, {3.550622,6.185143,5.712299}, {2.542231,5.862829,4.687939}, {1.789930,5.393625,4.413414}, {2.693583,5.018237,5.072837}, {3.530191,4.981603,4.937805}, {4.490323,5.186498,4.694397}, {-5.311432,5.485328,3.987654}, {-4.461908,6.189018,5.594410}, {-3.550622,6.185143,5.712299}, {-2.542231,5.862829,4.687939}, {-1.789930,5.393625,4.413414}, {-2.693583,5.018237,5.072837}, {-3.530191,4.981603,4.937805}, {-4.490323,5.186498,4.694397}, {1.330353,7.122144,6.903745}, {2.533424,7.878085,7.451034}, {4.861131,7.878672,6.601275}, {6.137002,7.271266,5.200823}, {6.825897,6.760612,4.402142}, {-1.330353,7.122144,6.903745}, {-2.533424,7.878085,7.451034}, {-4.861131,7.878672,6.601275}, {-6.137002,7.271266,5.200823}, {-6.825897,6.760612,4.402142}, {-2.774015,-2.080775,5.048531}, {-0.509714,-1.571179,6.566167}, {0.000000,-1.646444,6.704956}, {0.509714,-1.571179,6.566167}, {2.774015,-2.080775,5.048531}, {0.589441,-2.958597,6.109526}, {0.000000,-3.116408,6.097667}, {-0.589441,-2.958597,6.109526}, {-0.981972,4.554081,6.301271}, {-0.973987,1.916389,7.654050}, {-2.005628,1.409845,6.165652}, {-1.930245,0.424351,5.914376}, {-0.746313,0.348381,6.263227}, {0.000000,0.000000,6.763430}, {0.746313,0.348381,6.263227}, {1.930245,0.424351,5.914376}, {2.005628,1.409845,6.165652}, {0.973987,1.916389,7.654050}, {0.981972,4.554081,6.301271}};
    std::vector<cv::Point3d> object_pts={Model3D[33],Model3D[29],Model3D[34],Model3D[38],Model3D[13],Model3D[17],
                                         Model3D[25],Model3D[21],Model3D[55],Model3D[49],Model3D[43],Model3D[39],
                                         Model3D[45],Model3D[6]};
    std::vector<cv::Point3d> reprojectsrc={cv::Point3d(10.0, 10.0, 10.0),cv::Point3d(10.0, 10.0, -10.0),
                                           cv::Point3d(10.0, -10.0, -10.0),cv::Point3d(10.0, -10.0, 10.0),
                                           cv::Point3d(-10.0, 10.0, 10.0),cv::Point3d(-10.0, 10.0, -10.0),
                                           cv::Point3d(-10.0, -10.0, -10.0),cv::Point3d(-10.0, -10.0, 10.0)};


};


#endif //CMPRO_SHAPE_PROCESSING_H
