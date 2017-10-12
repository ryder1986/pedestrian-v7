#ifndef TEST_H
#define TEST_H
#include <QCoreApplication>
#include <QTimer>

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/video/video.hpp>
#include <opencv2/ml/ml.hpp>
#include <opencv2/objdetect/objdetect.hpp>

#include <QObject>
#include <stdio.h>
#include <QTimer>
class abc:public QObject{
    Q_OBJECT
public:
    abc()
    {
        CvCapture *p_cap;
        int tick=0;
        IplImage *ret_img;
      //  p_cap= cvCreateFileCapture("/root/video/test.mp4");  //读取视频
        p_cap= cvCreateFileCapture("http://192.168.1.28:8554/test");  //读取视频
        ret_img=NULL;
       //   abc test;
        QTimer *t;
        t=new QTimer();

        connect(t,SIGNAL(timeout()),this,SLOT(ss()));
        t->start(100);
        while(1)
        {
            printf("frame start\n");fflush(NULL);
            ret_img=cvQueryFrame(p_cap);
            if(ret_img!=NULL)
            { printf("frame %d done \n",tick++);}else{
               printf("frame err\n");
            }
        }

        cvReleaseCapture(&p_cap);
    }

public   slots:

void ss()
{
  printf("ssssssssssss  \n");fflush(NULL);
}
};
#endif // TEST_H

