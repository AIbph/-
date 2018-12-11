#include<opencv2/opencv.hpp>
#include<iostream>

using namespace cv;

int main(int argc, char** argv){
	// 模糊图像: 使用该操作的原因之一就为了给图像预处理时候减低噪声

	// 读取图像
	Mat src, dst;
	src = imread("D:/OpenCVProject/day1211/模糊图像/模糊图像/test.jpg");
	imshow("origin iamge", src);

	// 均值模糊: 均值模糊无法克服边缘像素信息丢失缺陷。原因是均值滤波是基于平均权重
	/*
		void blur(InputArray src, OutputArray dst, Size ksize, Point anchor=Point(-1,-1), int borderType=BORDER_DEFAULT )
		第一个参数，InputArray类型的src，输入图像，即源图像，填Mat类的对象即可。该函数对通道是独立处理的，且可以处理任意通道数的图片，但需要注意，待处理的图片深度应该为CV_8U, CV_16U, CV_16S, CV_32F 以及 CV_64F之一。
		第二个参数，OutputArray类型的dst，即目标图像，需要和源图片有一样的尺寸和类型。比如可以用Mat::Clone，以源图片为模板，来初始化得到如假包换的目标图。
		第三个参数，Size类型（对Size类型稍后有讲解）的ksize，内核的大小。一般这样写Size( w,h )来表示内核的大小( 其中，w 为像素宽度， h为像素高度)。Size（3,3）就表示3x3的核大小，Size（5,5）就表示5x5的核大小
		第四个参数，Point类型的anchor，表示锚点（即被平滑的那个点），注意他有默认值Point(-1,-1)。如果这个点坐标是负值的话，就表示取核的中心为锚点，所以默认值Point(-1,-1)表示这个锚点在核的中心。
		第五个参数，int类型的borderType，用于推断图像外部像素的某种边界模式。有默认值BORDER_DEFAULT，我们一般不去管它。
	*/
	blur(src, dst, Size(11, 11), Point(-1, -1));
	imshow("均值模糊处理后的图片", dst);

	// 高斯模糊: 高斯模糊部分克服了均值模糊的缺陷，但是无法完全避免，因为没有考虑像素值的不同
	/*
		void GaussianBlur(InputArray src, OutputArray dst, Size ksize, double sigmaX, double sigmaY=0, int borderType=BORDER_DEFAULT ) ;
		src和dst当然分别是输入图像和输出图像。
		Ksize为高斯滤波器模板大小，
		sigmaX和sigmaY分别为高斯滤波在横线和竖向的滤波系数（有点晦涩，等下解释）。
		borderType为边缘点插值类型。
	*/
	Mat gs;
	GaussianBlur(src, gs, Size(11, 11), 11, 11);
	imshow("高斯模糊处理后的图片", gs);

	// 高斯双边模糊： 是边缘保留的滤波方法，避免了边缘信息丢失，保留了图像轮廓不变	/*
		void bilateralFilter(InputArray src, OutputArray dst, int d, double sigmaColor, double sigmaSpace, int borderType=BORDER_DEFAULT )
		InputArray src: 输入图像，可以是Mat类型，图像必须是8位或浮点型单通道、三通道的图像。
		OutputArray dst: 输出图像，和原图像有相同的尺寸和类型。
		int d: 表示在过滤过程中每个像素邻域的直径范围。如果这个值是非正数，则函数会从第五个参数sigmaSpace计算该值。
		double sigmaColor: 颜色空间过滤器的sigma值，这个参数的值月大，表明该像素邻域内有月宽广的颜色会被混合到一起，产生较大的半相等颜色区域。
		double sigmaSpace: 坐标空间中滤波器的sigma值，如果该值较大，则意味着颜色相近的较远的像素将相互影响，从而使更大的区域中足够相似的颜色获取相同的颜色。当d>0时，d指定了邻域大小且与sigmaSpace五官，否则d正比于sigmaSpace.
		int borderType=BORDER_DEFAULT: 用于推断图像外部像素的某种边界模式，有默认值BORDER_DEFAULT.                                    
	*/
	Mat btf;
	bilateralFilter(src, btf, 15, 100, 5);
	imshow("高斯双边模糊处理后的图片", btf);

	waitKey(0);
	return 0;
}
