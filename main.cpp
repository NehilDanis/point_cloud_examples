#include <iostream>
#include <pcl/io/pcd_io.h>
#include <pcl/point_types.h>
#include <string>

const std::string pcd_data_path = "../dataset/point_cloud_data.pcd";


int main(int argc, char** argv)
{	
	pcl::PointCloud<pcl::PointXYZRGB>::Ptr cloud (new pcl::PointCloud<pcl::PointXYZRGB>);
	
	if(pcl::io::loadPCDFile<pcl::PointXYZRGB> (pcd_data_path, *cloud) == -1)
	{
		PCL_ERROR ("Couldn't read file test_pcd.pcd \n");
    		return (-1);
	}

	std::cout << "Loaded "
            << cloud->width * cloud->height
            << " data points from test_pcd.pcd with the following fields: "
            << std::endl;

	for(std::size_t i = 0; i < cloud->points.size (); i++)
	{
		std::cout << "    " << cloud->points[i].x << " "    << cloud->points[i].y << " "    << cloud->points[i].z << std::endl;
	}


	return 0;
}
