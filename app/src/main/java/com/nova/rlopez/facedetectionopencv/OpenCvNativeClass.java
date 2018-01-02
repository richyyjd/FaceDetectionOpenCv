package com.nova.rlopez.facedetectionopencv;

/**
 * Created by rlopez on 01-01-18.
 */

public class OpenCvNativeClass {
    public native static int convertGray(long matAddrRgba, long matAddrGray);

    //public native static void faceDetection(long addrRgba);
}