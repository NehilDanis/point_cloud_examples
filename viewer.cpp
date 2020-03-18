#include <pcl/visualization/cloud_viewer.h>
#include <iostream>
#include <pcl/io/io.h>
#include <pcl/io/pcd_io.h>




int main()
 {
   pcl::PointCloud<pcl::PointXYZI>::Ptr cloud (new pcl::PointCloud<pcl::PointXYZI>);
   //... populate cloud
   
   pcl::io::loadPCDFile ("../dataset/table_scene_lms400.pcd", *cloud);
   pcl::visualization::CloudViewer viewer("Simple Cloud Viewer");
   viewer.showCloud (cloud);
   while (!viewer.wasStopped ())
   {
   }

   return 0;
 }
