#include <iostream>
#include <pcl/io/pcd_io.h>
#include <pcl/point_types.h>
#include <pcl/filters/voxel_grid.h>
#include <pcl/visualization/cloud_viewer.h>
#include <string>

const std::string path = "../dataset/table_scene_lms400.pcd";

int main(int argc, char** argv)
{
	// Created two cloud structures.
	pcl::PointCloud<pcl::PointXYZI>::Ptr cloud (new pcl::PointCloud<pcl::PointXYZI>);
	pcl::PointCloud<pcl::PointXYZI>::Ptr filtered_cloud (new pcl::PointCloud<pcl::PointXYZI>);

	// Load the data from the give path.
	
	if(pcl::io::loadPCDFile(path, *cloud) == (-1)) 
	{
		PCL_ERROR ("Couldn't read file test_pcd.pcd \n");
                return (-1);
	}
	
	std::cout << "The data is loaded!" << std::endl;
	std::cout << "The number of points before filtering : "<< cloud->width * cloud->height << std::endl;

	pcl::VoxelGrid<pcl::PointXYZI> sor;
	sor.setInputCloud (cloud);
  	sor.setLeafSize (0.01f, 0.01f, 0.01f);
  	sor.filter (*filtered_cloud);
	
	std::cout << "The data is filtered out" << std::endl;
        std::cout << "The number of points after filtering : "<< filtered_cloud->width * filtered_cloud->height << std::endl;

	// Write filtered data to a new pcd file.
	
	pcl::PCDWriter writer;

	if(writer.writeBinary("../dataset/filtered_data.pcd", *filtered_cloud) == (-1))
	{
		PCL_ERROR ("Couldn't write to a file! \n");
                return (-1);
	}

	std::cout << "Write complete!" << std::endl;

	pcl::visualization::CloudViewer viewer("Simple Cloud Viewer");
	viewer.showCloud (filtered_cloud);
	while (!viewer.wasStopped ()) 
	{
		// Do nothing!
	}	

	return (0);

}
