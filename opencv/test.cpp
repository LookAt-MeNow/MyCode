#include <opencv2/imgcodecs.hpp> // 引入opencv的图像编码库
#include <opencv2/highgui.hpp> // 引入opencv的高级图形用户界面库
#include <opencv2/imgproc.hpp> // 引入opencv的图像处理库
#include <opencv2/objdetect.hpp> // 引入opencv的对象检测库
#include <iostream> // 引入标准输入输出流库

using namespace cv; // 使用cv命名空间
using namespace std; // 使用std命名空间

int main()
{
    Mat img; // 定义一个Mat类型的变量，用于存储读取的图像
    VideoCapture cap(0); //定义一个VideoCapture类型的变量，用于捕捉视频文件
    CascadeClassifier faceCascade; // 定义一个CascadeClassifier类型的变量，用于存储人脸检测器
    faceCascade.load("D:\\software\\opencv\\opencv\\sources\\data\\haarcascades\\haarcascade_eye.xml"); // 加载人脸检测器的XML文件
    if (faceCascade.empty()) { cout << "XML file not loaded" << endl; } // 如果人脸检测器为空，输出错误信息
    while (true) {
        vector<Rect> faces; // 定义一个vector类型的变量，用于存储检测到的人脸区域
        cap.read(img);
        faceCascade.detectMultiScale(img, faces, 1.1, 10); // 调用人脸检测器的detectMultiScale方法，对图像进行多尺度检测，并将结果存储在faces中

        for (int i = 0; i < faces.size(); i++) // 遍历faces中的每个元素
        {
            rectangle(img, faces[i].tl(), faces[i].br(), Scalar(255, 0, 255), 3); // 在img上绘制一个矩形，表示人脸区域，矩形的左上角和右下角分别为faces[i]的tl()和br()方法返回的点，矩形的颜色为Scalar(255, 0, 255)，即紫色，矩形的线宽为3
        }

        imshow("Image", img); // 显示img图像，窗口标题为"Image"
        waitKey(1); // 等待用户按键
    }
    return 0; // 返回0，表示程序正常结束
}
//眼睛检测
//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