#include<opencv2/opencv.hpp>
#include<iostream>

using namespace cv;

int main(int argc, char** argv){
	// ģ��ͼ��: ʹ�øò�����ԭ��֮һ��Ϊ�˸�ͼ��Ԥ����ʱ���������

	// ��ȡͼ��
	Mat src, dst;
	src = imread("D:/OpenCVProject/day1211/ģ��ͼ��/ģ��ͼ��/test.jpg");
	imshow("origin iamge", src);

	// ��ֵģ��: ��ֵģ���޷��˷���Ե������Ϣ��ʧȱ�ݡ�ԭ���Ǿ�ֵ�˲��ǻ���ƽ��Ȩ��
	/*
		void blur(InputArray src, OutputArray dst, Size ksize, Point anchor=Point(-1,-1), int borderType=BORDER_DEFAULT )
		��һ��������InputArray���͵�src������ͼ�񣬼�Դͼ����Mat��Ķ��󼴿ɡ��ú�����ͨ���Ƕ�������ģ��ҿ��Դ�������ͨ������ͼƬ������Ҫע�⣬�������ͼƬ���Ӧ��ΪCV_8U, CV_16U, CV_16S, CV_32F �Լ� CV_64F֮һ��
		�ڶ���������OutputArray���͵�dst����Ŀ��ͼ����Ҫ��ԴͼƬ��һ���ĳߴ�����͡����������Mat::Clone����ԴͼƬΪģ�壬����ʼ���õ���ٰ�����Ŀ��ͼ��
		������������Size���ͣ���Size�����Ժ��н��⣩��ksize���ں˵Ĵ�С��һ������дSize( w,h )����ʾ�ں˵Ĵ�С( ���У�w Ϊ���ؿ�ȣ� hΪ���ظ߶�)��Size��3,3���ͱ�ʾ3x3�ĺ˴�С��Size��5,5���ͱ�ʾ5x5�ĺ˴�С
		���ĸ�������Point���͵�anchor����ʾê�㣨����ƽ�����Ǹ��㣩��ע������Ĭ��ֵPoint(-1,-1)���������������Ǹ�ֵ�Ļ����ͱ�ʾȡ�˵�����Ϊê�㣬����Ĭ��ֵPoint(-1,-1)��ʾ���ê���ں˵����ġ�
		�����������int���͵�borderType�������ƶ�ͼ���ⲿ���ص�ĳ�ֱ߽�ģʽ����Ĭ��ֵBORDER_DEFAULT������һ�㲻ȥ������
	*/
	blur(src, dst, Size(11, 11), Point(-1, -1));
	imshow("��ֵģ��������ͼƬ", dst);

	// ��˹ģ��: ��˹ģ�����ֿ˷��˾�ֵģ����ȱ�ݣ������޷���ȫ���⣬��Ϊû�п�������ֵ�Ĳ�ͬ
	/*
		void GaussianBlur(InputArray src, OutputArray dst, Size ksize, double sigmaX, double sigmaY=0, int borderType=BORDER_DEFAULT ) ;
		src��dst��Ȼ�ֱ�������ͼ������ͼ��
		KsizeΪ��˹�˲���ģ���С��
		sigmaX��sigmaY�ֱ�Ϊ��˹�˲��ں��ߺ�������˲�ϵ�����е��ɬ�����½��ͣ���
		borderTypeΪ��Ե���ֵ���͡�
	*/
	Mat gs;
	GaussianBlur(src, gs, Size(11, 11), 11, 11);
	imshow("��˹ģ��������ͼƬ", gs);

	// ��˹˫��ģ���� �Ǳ�Ե�������˲������������˱�Ե��Ϣ��ʧ��������ͼ����������	/*
		void bilateralFilter(InputArray src, OutputArray dst, int d, double sigmaColor, double sigmaSpace, int borderType=BORDER_DEFAULT )
		InputArray src: ����ͼ�񣬿�����Mat���ͣ�ͼ�������8λ�򸡵��͵�ͨ������ͨ����ͼ��
		OutputArray dst: ���ͼ�񣬺�ԭͼ������ͬ�ĳߴ�����͡�
		int d: ��ʾ�ڹ��˹�����ÿ�����������ֱ����Χ��������ֵ�Ƿ�������������ӵ��������sigmaSpace�����ֵ��
		double sigmaColor: ��ɫ�ռ��������sigmaֵ�����������ֵ�´󣬱������������������¿�����ɫ�ᱻ��ϵ�һ�𣬲����ϴ�İ������ɫ����
		double sigmaSpace: ����ռ����˲�����sigmaֵ�������ֵ�ϴ�����ζ����ɫ����Ľ�Զ�����ؽ��໥Ӱ�죬�Ӷ�ʹ������������㹻���Ƶ���ɫ��ȡ��ͬ����ɫ����d>0ʱ��dָ���������С����sigmaSpace��٣�����d������sigmaSpace.
		int borderType=BORDER_DEFAULT: �����ƶ�ͼ���ⲿ���ص�ĳ�ֱ߽�ģʽ����Ĭ��ֵBORDER_DEFAULT.                                    
	*/
	Mat btf;
	bilateralFilter(src, btf, 15, 100, 5);
	imshow("��˹˫��ģ��������ͼƬ", btf);

	waitKey(0);
	return 0;
}
