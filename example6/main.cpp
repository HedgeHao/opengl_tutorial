#include <opencv4/opencv2/opencv.hpp>
using namespace std;
using namespace cv;

int main()
{
  VideoCapture cap(0);
  if (!cap.isOpened())
  {
    cout << "Cannot open camera\n";
    return 1;
  }

  cap.set(CAP_PROP_FRAME_WIDTH, 800);
  cap.set(CAP_PROP_FRAME_HEIGHT, 600);

  Mat frame;
  Mat gray;
  while (true)
  {
    bool ret = cap.read(frame); // or cap >> frame;
    if (!ret)
    {
      cout << "Can't receive frame (stream end?). Exiting ...\n";
      break;
    }

    // Greyscale
    // cvtColor(frame, gray, COLOR_BGR2GRAY);

    imshow("live", frame);
    // imshow("live", gray);

    if (waitKey(1) == 'q')
    {
      break;
    }
  }

  return 0;
}