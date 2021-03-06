#include <com_nova_rlopez_facedetectionopencv_OpencvClass.h>
/*JNIEXPORT jint JNICALL Java_com_nova_rlopez_facedetectionopencv_OpencvClass_convertGray
  (JNIEnv *, jclass, jlong, jlong);
*/

JNIEXPORT void JNICALL Java_com_nova_rlopez_facedetectionopencv_OpencvClass_faceDetection
  (JNIEnv *, jclass, jlong addrRgba){
    //Mat& mRgb = *(Mat*) addrRgba;
    Mat& frame = *(Mat*)addrRgba;

    detect(frame);

  }

void detect(Mat& frame){
    // vars
     //String face_cascade_name = "storage/emulated/0/data_richard/haarcascade_frontalface_alt.xml";
     //String face_cascade_name = "storage/emulated/0/data_richard/haarcascade_frontalface_alt2.xml";
     String face_cascade_name = "storage/emulated/0/data_richard/haarcascade_frontalface_default.xml";
     //String eyes_cascade_name = "storage/emulated/0/data_richard/haarcascade_eye_tree_eyeglasses.xml";
     CascadeClassifier face_cascade;
     //CascadeClassifier eyes_cascade;

     // Load cascades
     if( !face_cascade.load( face_cascade_name ) ){ printf("--(!)Error loading\n"); return; };
     //if( !eyes_cascade.load( eyes_cascade_name ) ){ printf("--(!)Error loading\n"); return; };

     std::vector<Rect> faces;
       Mat frame_gray;

       cvtColor( frame, frame_gray, CV_BGR2GRAY );
       equalizeHist( frame_gray, frame_gray );

       // Detect faces
       face_cascade.detectMultiScale( frame_gray, faces, 1.1, 2, 0|CV_HAAR_SCALE_IMAGE, Size(30, 30) );

       for( size_t i = 0; i < faces.size(); i++ )
       {
         Point center( faces[i].x + faces[i].width*0.5, faces[i].y + faces[i].height*0.5 );
         ellipse( frame, center, Size( faces[i].width*0.5, faces[i].height*0.5), 0, 0, 360, Scalar( 255, 0, 255 ), 4, 8, 0 );
        }
}