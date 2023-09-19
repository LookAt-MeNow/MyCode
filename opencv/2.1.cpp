#include <opencv2/imgcodecs.hpp> //包含opencv库的头文件，用于图像编码和解码
#include <opencv2/highgui.hpp> //包含opencv库的头文件，用于图像显示和交互
#include <opencv2/imgproc.hpp> //包含opencv库的头文件，用于图像处理
#include <iostream> //包含标准库的头文件，用于输入输出流

using namespace cv; //使用cv命名空间，简化代码
using namespace std; //使用std命名空间，简化代码

int main() //主函数
{
    string path = "D:\\popo\\test.png"; //定义一个字符串变量，存储图像的路径
    Mat img = imread(path); //定义一个Mat类型的变量，用于存储读取的图像
    Mat imgGray, imgBlur, imgCanny, imgDil, imgErode; //定义一些Mat类型的变量，用于存储处理后的图像

    cvtColor(img, imgGray, COLOR_BGR2GRAY); //将原始图像转换为灰度图像，第一个参数是输入图像，第二个参数是输出图像，第三个参数是转换类型
    GaussianBlur(img, imgBlur, Size(3, 3), 3, 0); //对原始图像进行高斯模糊，第一个参数是输入图像，第二个参数是输出图像，第三个参数是模糊核的大小，第四个参数是水平方向的标准差，第五个参数是垂直方向的标准差
    Canny(imgBlur, imgCanny, 25, 75); //对模糊后的图像进行边缘检测，第一个参数是输入图像，第二个参数是输出图像，第三个参数是最小阈值，第四个参数是最大阈值

    Mat kernel = getStructuringElement(MORPH_RECT, Size(3, 3)); //定义一个结构元素（核），用于膨胀和腐蚀操作，第一个参数是形状类型，第二个参数是大小
    dilate(imgCanny, imgDil, kernel); //对边缘检测后的图像进行膨胀操作，第一个参数是输入图像，第二个参数是输出图像，第三个参数是结构元素（核）
    erode(imgDil, imgErode, kernel); //对膨胀后的图像进行腐蚀操作，第一个参数是输入图像，第二个参数是输出图像，第三个参数是结构元素（核）

    imshow("Image", img); //显示原始图像，第一个参数是窗口的名称，第二个参数是图像变量
    imshow("ImageGray", imgGray); //显示灰度图像
    imshow("ImageBlur", imgBlur); //显示模糊后的图像
    imshow("ImageCanny", imgCanny); //显示边缘检测后的图像
    imshow("ImageDilation", imgDil); //显示膨胀后的图像
    imshow("ImageErode", imgErode); //显示腐蚀后的图像
    waitKey(0); //等待用户按键，参数是等待的毫秒数，0表示无限等待

    return 0; //返回0，表示程序正常结束
}
