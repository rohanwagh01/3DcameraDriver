#include <k4a/k4a.h>

#include <stdio.h>
#include <stdlib.h>

int main()
{
	//check for k4a device connection
	uint32_t count = k4a_device_get_installed_count();
	if (count == 0)
	{
		printf("Kinect not connected, plug it in pls");
		return 1;
	}

	k4a_device_t device = NULL;
	if (K4A_FAILED(k4a_device_open(K4A_DEVICE_DEFAULT, &device)))
	{
		printf("unable to connect to kinect, failed to open device");
		return 1;
	}

	//get camera calibration information
	k4a_device_configuration_t config = K4A_DEVICE_CONFIG_INIT_DISABLE_ALL;

	config.depth_mode = K4A_DEPTH_MODE_WFOV_2X2BINNED;
	config.camera_fps = K4A_FRAMES_PER_SECOND_30;
	k4a_calibration_t calibration;
	if (K4A_RESULT_SUCCEEDED !=
            k4a_device_get_calibration(device, config.depth_mode, config.color_resolution, &calibration))
    	{
        	printf("Failed to get calibration\n");
        	return 1;
    	}

	return 1;

}
