#include <opencv2/imgcodecs.hpp> //包含opencv库的头文件，用于图像编码和解码
#include <opencv2/highgui.hpp> //包含opencv库的头文件，用于图像显示和交互
#include <opencv2/imgproc.hpp> //包含opencv库的头文件，用于图像处理
#include <iostream> //包含标准库的头文件，用于输入输出流

using namespace cv; //使用cv命名空间，简化代码
using namespace std; //使用std命名空间，简化代码

int main() //主函数
{
    string path = "D:\\software\\opencv\\opencv\\sources\\samples\\data\\vtest.avi"; //定义一个字符串变量，存储视频文件的路径
    VideoCapture cap(path); //定义一个VideoCapture类型的变量，用于捕捉视频文件
    Mat img; //定义一个Mat类型的变量，用于存储每一帧图像
    while (true) { //无限循环

        cap.read(img); //从视频文件中读取一帧图像，并存储到img变量中

        imshow("Image", img); //显示图像，第一个参数是窗口的名称，第二个参数是图像变量
        waitKey(1); //等待用户按键，参数是等待的毫秒数，1表示等待1毫秒
    }
    return 0; //返回0，表示程序正常结束
}
